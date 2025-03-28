/*
 @Author: nanbowan
*/
#include "stdafx.h"
#include "FileService.h"
#include "../../dao/file/FileDAO.h"
#include "../../domain/dto/ordertypes/OrderTypesDTO.h"
#include"FastDfsClient.h"
#include"ExcelComponent.h"
#include "domain/do/ordertypes/OrderTypesDO.h"
#include "ServerInfo.h"
#include "NacosClient.h"


string FileService::queryData()
{
	// 构建返回对象
	auto pages = FileDTO::createShared();

	// 查询数据总条数
	FileDAO dao;
	uint64_t count = dao.count();
	if (count <= 0)
	{
		return {};
	}
	
	list<FileDO> result = dao.selectAll();

	// 创建二维 vector 来存储数据
	std::vector<std::vector<std::string>> allData;

	//插入表头
	std::vector<std::string> dataPair;
	dataPair.push_back(ZH_WORDS_GETTER("dictionary.order.code.summary"));
	dataPair.push_back(ZH_WORDS_GETTER("dictionary.order.type.summary"));
	allData.push_back(dataPair);
	dataPair.clear();

	// 将DO数据取出
	for (FileDO sub : result)
	{
		dataPair.push_back(std::string(sub.getCode()));
		dataPair.push_back(sub.getName());
		allData.push_back(dataPair);
		dataPair.clear();
	}

	//将数据以excel格式写入buff中
	ExcelComponent excel;
	auto buff = excel.writeVectorToBuff(ZH_WORDS_GETTER("dictionary.file.sheet.summary"), allData);

	ZO_CREATE_DFS_CLIENT(dfs);

	const char* tsData = reinterpret_cast<const char*>(buff.data());
	string path = dfs.uploadFile(tsData,buff.size(),"xlsx");

	if (!result .empty())
	{
		return path;
	}

	return {};
}

bool FileService::insertData(string fullpath)
{
	ZO_CREATE_DFS_CLIENT(dfs);

	string savePath = "./public/fastdfs";

	string filePath = dfs.downloadFile(fullpath, &savePath);

	ExcelComponent excel;

	vector<vector<string>> buff=excel.readIntoVector(filePath, ZH_WORDS_GETTER("dictionary.file.sheet.summary"));

	if (buff.size() > 1) {
		for (auto it = buff.begin() + 1; it != buff.end(); ++it) {
			OrderTypesDO data;
			String tmp0 = (*it)[0];
			String tmp1 = (*it)[1];
			String tmp2 = (*it)[2];
			auto dto = ModifyOrderTypeDTO::createShared();
			dto->id = tmp0;
			dto->order_type_code = tmp1;
			dto->order_type_name = tmp2;
			ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Code, order_type_code, Name, order_type_name);
			// 执行数据插入
			FileDAO dao;
			dao.insert(data);
		}
	}
	dfs.deleteFile(fullpath);
	return 1;
}