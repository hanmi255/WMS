/*
 @Author: gutianxuan
*/
#include "stdafx.h"
#include "TemperatureService.h"
#include "../../dao/temperature/TemperatureDAO.h"
#include"FastDfsClient.h"
#include"ExcelComponent.h"
#include"../../domain/do/temperature/TemperatureDO.h"
#include "ServerInfo.h"
#include "NacosClient.h"

string TemperatureService::queryData()
{
	// 构建返回对象：TemperatureDetailDTO
	auto pages = TemperatureDetailDTO::createShared();

	// 查询数据总条数
	TemperatureDAO dao;
	uint64_t count = dao.count();

	if (count <= 0)
	{
		return {};
	}

	list<TemperatureDO> result = dao.selectAll();

	// 创建二维 vector 来存储数据
	std::vector<std::vector<std::string>> allData;

	//插入表头 温层代码 温层名称
	std::vector<std::string> dataPair;

	dataPair.push_back(ZH_WORDS_GETTER("reposity.temperature.field.deg_type_code"));
	dataPair.push_back(ZH_WORDS_GETTER("reposity.temperature.field.deg_type_name"));

	allData.push_back(dataPair);
	dataPair.clear();

	// 将DO数据取出
	for (TemperatureDO sub : result)
	{
		dataPair.push_back(std::string(sub.getDeg_Type_Code()));
		dataPair.push_back(std::string(sub.getDeg_Type_Name()));
		allData.push_back(dataPair);
		dataPair.clear();
	}

	//将数据以excel格式写入buff中
	ExcelComponent excel;
	auto buff = excel.writeVectorToBuff(ZH_WORDS_GETTER("reposity.temperature.field.sheet"), allData);

	FastDfsClient dfs("192.168.200.171");

	const char* tsData = reinterpret_cast<const char*>(buff.data());
	string path = dfs.uploadFile(tsData, buff.size(), "xlsx");

	if (!result.empty())
	{
		return path;
	}

	return {};

}

//excel 插入
//根据dfs的excel表格进行插入
bool TemperatureService::insertData(string fullpath)
{
	ZO_CREATE_DFS_CLIENT(dfs);

	string savePath = "./public/repository/temperature";

	string filePath = dfs.downloadFile(fullpath, &savePath);

	ExcelComponent excel;

	vector<vector<string>> buff = excel.readIntoVector(filePath, ZH_WORDS_GETTER("reposity.temperature.field.sheet"));

	if (buff.size() > 1) {
		for (auto it = buff.begin() + 1; it != buff.end(); ++it) {
			TemperatureDO data;
			String tmp0 = (*it)[0];
			String tmp1 = (*it)[1];
			String tmp2 = (*it)[2];
			auto dto = TemperatureDetailDTO::createShared();
			dto->id = tmp0;
			dto->deg_type_code = tmp1;
			dto->deg_type_name = tmp2;
			ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Create_Name, create_name, Create_By, create_by, Create_Date, create_date, Update_Name, update_name, Update_By, update_by, Update_Date, update_date, Sys_Org_Code, sys_org_code, Sys_Company_Code, sys_company_code, Deg_Type_Code, deg_type_code, Deg_Type_Name, deg_type_name);
			// 执行数据插入
			TemperatureDAO dao;
			dao.insert(data);
		}
	}
	dfs.deleteFile(fullpath);
	return 1;
}

uint64_t TemperatureService::addData(const TemperatureDetailDTO::Wrapper& dto)
{
	TemperatureDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Create_Name, create_name, Create_By, create_by, Create_Date, create_date, Update_Name, update_name, Update_By, update_by, Update_Date, update_date, Sys_Org_Code, sys_org_code, Sys_Company_Code, sys_company_code, Deg_Type_Code, deg_type_code, Deg_Type_Name, deg_type_name);

	TemperatureDAO dao;
	return dao.insert(data);

}

bool TemperatureService::updateData(const TemperatureDetailDTO::Wrapper& dto)
{
	// 组装DO数据
	TemperatureDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Create_Name, create_name, Create_By, create_by, Create_Date, create_date, Update_Name, update_name, Update_By, update_by, Update_Date, update_date, Sys_Org_Code, sys_org_code, Sys_Company_Code, sys_company_code, Deg_Type_Code, deg_type_code, Deg_Type_Name, deg_type_name);
	// 执行数据修改
	TemperatureDAO dao;
	return dao.update(data) == 1;

}

bool TemperatureService::removeData(string id)
{
	TemperatureDAO dao;
	return dao.deleteById(id) == 1;
}



TemperaturePageDTO::Wrapper TemperatureService::listQueryTemperature(const TemperatureQuery::Wrapper& query)
{
	auto pages = TemperaturePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;


	TemperatureDAO dao;
	uint64_t count = dao.count();

	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();

	list<TemperatureDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (TemperatureDO sub : result)
	{
		auto dto = TemperatureListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, deg_type_code, Deg_Type_Code, deg_type_name, Deg_Type_Name);
		pages->addData(dto);
	}
	return pages;
}

TemperatureNamePageDTO::Wrapper TemperatureService::listTemperatureName(const PageQuery::Wrapper& query)
{
	auto pages = TemperatureNamePageDTO::createShared();

	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	TemperatureDAO dao;
	uint64_t count = dao.count();

	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<TemperatureNameDO> result = dao.selectTemperatureNameList();
	for (TemperatureNameDO sub : result)
	{
		auto dto = TemperatureNameDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, deg_type_name, Deg_Type_Name);
		pages->addData(dto);
	}
	return pages;
}
