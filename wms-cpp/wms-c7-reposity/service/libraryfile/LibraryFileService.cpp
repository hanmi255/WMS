/*
 @Author: nanbowan
*/
#include "stdafx.h"
#include "LibraryFileService.h"
#include "../../dao/libraryfile/LibraryFileDAO.h"
#include "../../domain/dto/library/LibraryDTO.h"
#include"FastDfsClient.h"
#include"ExcelComponent.h"
#include "domain/do/library/LibraryDO.h"
#include "ServerInfo.h"
#include "NacosClient.h"


string LibraryFileService::queryData()
{
	// 构建返回对象
	auto pages = LibraryFileDTO::createShared();

	// 查询数据总条数
	LibraryFileDAO dao;
	uint64_t count = dao.count();
	if (count <= 0)
	{
		return {};
	}

	list<LibraryFileDO> result = dao.selectAll();

	// 创建二维 vector 来存储数据
	std::vector<std::vector<std::string>> allData;

	//插入表头
	std::vector<std::string> dataPair;
	dataPair.push_back(ZH_WORDS_GETTER("dictionary.library.code.summary"));
	dataPair.push_back(ZH_WORDS_GETTER("dictionary.library.type.summary"));
	allData.push_back(dataPair);
	dataPair.clear();

	// 将DO数据取出
	for (LibraryFileDO sub : result)
	{
		dataPair.push_back(std::string(sub.getCode()));
		dataPair.push_back(sub.getName());
		allData.push_back(dataPair);
		dataPair.clear();
	}

	//将数据以excel格式写入buff中
	ExcelComponent excel;
	auto buff = excel.writeVectorToBuff(ZH_WORDS_GETTER("dictionary.libraryfile.sheet.summary"), allData);

	ZO_CREATE_DFS_CLIENT(dfs);

	const char* tsData = reinterpret_cast<const char*>(buff.data());
	string path = dfs.uploadFile(tsData, buff.size(), "xlsx");

	if (!result.empty())
	{
		return path;
	}

	return {};
}

bool LibraryFileService::insertData(string fullpath)
{
	ZO_CREATE_DFS_CLIENT(dfs);

	string savePath = "./public/fastdfslibrary";

	string filePath = dfs.downloadFile(fullpath, &savePath);

	ExcelComponent excel;

	vector<vector<string>> buff = excel.readIntoVector(filePath, ZH_WORDS_GETTER("dictionary.libraryfile.sheet.summary"));

	if (buff.size() > 1) {
		for (auto it = buff.begin() + 1; it != buff.end(); ++it) {
			LibraryDO data;
			String tmp0 = (*it)[0];
			String tmp1 = (*it)[1];
			String tmp2 = (*it)[2];
			auto dto = ModifyLibraryDTO::createShared();
			dto->id = tmp0;
			dto->bin_type_code = tmp1;
			dto->bin_type_name = tmp2;
			ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Code, bin_type_code, Name, bin_type_name);
			// 执行数据插入
			LibraryFileDAO dao;
			dao.insert(data);
		}
	}
	dfs.deleteFile(fullpath);
	return 1;
}