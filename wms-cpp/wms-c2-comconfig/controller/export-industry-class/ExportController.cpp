#include "stdafx.h"
#include <iostream>
#include "ExportController.h"
//#include "domain/vo/cominfo/ComInfoVO.h"
#include <regex>

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include "ExcelComponent.h"


std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> ExportController::execExportExcel(const String& filename)
{
	// 构建文件全路径
	std::string fullPath = "Public/DownloadIndcla/" + URIUtil::urlDecode(filename.getValue(""));
	//表`ba_classfl`对应结构
	std::vector<std::string> ba_classfl = {
	ZH_WORDS_GETTER("chengfeng.id"),
	ZH_WORDS_GETTER("chengfeng.code"),
	ZH_WORDS_GETTER("chengfeng.name"),
	ZH_WORDS_GETTER("chengfeng.del")
	};
	std::vector<std::string> ba_classfl_en = {
		"id","code","name","del"
	};
	//导出数据到客户端
	/*
	int total_size;//由查询企业信息得到的条数
	int PageSize;//每页几条

	//创建一个excel表格
	ExcelComponent excel;
	std::string sheetName = "Page";

	for (int PageIndex = 0; PageIndex  < (total_size - 1) / PageSize; PageIndex++) //计算总页数
	{
		//构造每一条数据
		std::vector<std::vector<std::string>> data;
		data.push_back(ba_comp);
		data.push_back(ba_comp_en);

		// 生成当前页的数据
		for (int i = 0; i < PageSize; i++)
		{
			int recordIndex = PageIndex * PageSize + i;
			if (recordIndex >= total_size) break; // 避免越界

			// 实际应从数据库查询
			std::vector<std::string> row = {

			};
			data.push_back(row);
		}
		// 生成当前分页的数据到文件
		std::string currentSheetName = sheetNamePrefix + std::to_string(PageIndex + 1);
		excel.writeVectorToFile(fullPath, currentSheetName, data);
	}
	//构造每一条数据
	std::vector<std::vector<std::string>> data;
	data.push_back(ba_comp);
	data.push_back(ba_comp_en);
	for(int i=PageIndex*PageSize;i<total_size;++i)
	{
		int recordIndex = PageIndex * PageSize + i;

		// 实际应从数据库查询
		std::vector<std::string> row = {

		};
		data.push_back(row);
	}
	// 读取文件内容到 buffer 发送
	auto buff = excel.writeVectorToBuff(sheetName + std::to_string(++PageIndex), data);
	const char* tsData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(tsData, buff.size());

	// 判断是否读取成功
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	*/


	// 测试数据 此内容仅供测试
	// 导出zo_wms中内容需要待查询企业信息接口完成
	// 假设 total_size 和 PageSize 由查询企业信息接口完成获取
	int total_size = 200;  // 假设数据总数
	int PageSize = 100;      // 每页100条
	int PageIndex;

	ExcelComponent excel;
	std::string sheetName = "Page";

	for (PageIndex = 0; PageIndex < (total_size - 1) / PageSize; PageIndex++)
	{
		std::vector<std::vector<std::string>> data;
		data.push_back(ba_classfl);
		data.push_back(ba_classfl_en);

		// 生成当前页的数据
		for (int i = 0; i < PageSize; i++)
		{
			int recordIndex = PageIndex * PageSize + i;
			if (recordIndex >= total_size) break; // 避免越界

			// 这里用模拟数据，实际应从数据库查询
			std::vector<std::string> row = {
				std::to_string(recordIndex + 1), "user" + std::to_string(recordIndex),
				"creator" + std::to_string(recordIndex), "2024-03-01 10:00:00",
				"editor" + std::to_string(recordIndex), "editor_by" + std::to_string(recordIndex),
				"2024-03-02 11:00:00", "100" + std::to_string(recordIndex),
				"200" + std::to_string(recordIndex), "C00" + std::to_string(recordIndex),
				"Company" + std::to_string(recordIndex), "Alias" + std::to_string(recordIndex),
				"Address" + std::to_string(recordIndex), "Company_EN" + std::to_string(recordIndex),
				"Alias_EN" + std::to_string(recordIndex)
			};
			data.push_back(row);
		}

		// 生成当前分页的数据到文件
		std::string currentSheetName = sheetName + std::to_string(PageIndex + 1);
		excel.writeVectorToFile(fullPath, currentSheetName, data);
	}
	std::vector<std::vector<std::string>> data;
	data.push_back(ba_classfl);
	data.push_back(ba_classfl_en);
	// 生成当前页的数据
	for (int i = PageIndex * PageSize; i < total_size; i++)
	{

		// 这里用模拟数据，实际应从数据库查询
		std::vector<std::string> row = {
			std::to_string(i + 1), "user" + std::to_string(i),
			"creator" + std::to_string(i), "2024-03-01 10:00:00",
			"editor" + std::to_string(i), "editor_by" + std::to_string(i),
			"2024-03-02 11:00:00", "100" + std::to_string(i),
			"200" + std::to_string(i), "C00" + std::to_string(i),
			"Company" + std::to_string(i), "Alias" + std::to_string(i),
			"Address" + std::to_string(i), "Company_EN" + std::to_string(i),
			"Alias_EN" + std::to_string(i)
		};
		data.push_back(row);
	}

	// 读取文件内容到 buffer 发送
	auto buff = excel.writeVectorToBuff(sheetName + std::to_string(++PageIndex), data);
	const char* tsData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(tsData, buff.size());


	// 判断是否读取成功
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));

	// 影响成功结果
	return response;

}