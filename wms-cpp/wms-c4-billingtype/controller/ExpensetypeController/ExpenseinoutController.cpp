/*****************************************************************************
    *  @COPYRIGHT NOTICE
    *  @Copyright (c) 2013, kato1
    *  @All rights reserved
    *  @file	 : ExpenseinoutController.cpp
    *  @version  : ver 1.0
    *  @author   : kato1
    *  @date     : 2025/3/10 21:12
    *  @brief    : brief
*****************************************************************************/

#include "stdafx.h"
#include <iostream>
#include "ExpenseinoutController.h"
#include "../../service/expensetype/ExpenseTypeService.h"
#include "../../domain/query/expensetype/ExpenseTypeQuery.h"
#include "../../service/CostTypeService/CostTypeService.h"

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

//excel 报表
#include "../../lib-common/include/ExcelComponent.h"


StringJsonVO::Wrapper ExpenseinoutController::execUploadExpenceType(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{
	//// 1 初始化

	auto jvo = StringJsonVO::createShared();
	API_MULTIPART_INIT(container, reader);
	////// 2 配置读取器
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	////// 3 读取数据
	request->transferBody(&reader);
	////// 4 解析数据
	/////* todo: 解析的数据具体逻辑，需要根据你的业务需求来，下面是使用示例而已。 */
	/////* 获取文件数据 */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	auto fileData = "";
	auto fileSize = 0;
	std::string filename = "";
	std::string sheetName = "Sheet1";// 使用创建excel表默认的sheet表名
	CostTypeService service;
	if (file)
	{
		ExcelComponent excel;
		//	// 5. 读取文件内容
		fileData = file->data();  // 获取二进制数据
		fileSize = file->size();
		filename = partfile->getFilename().getValue(""); // 获取原始文件名

		std::vector<std::vector<std::string>> result = excel.readIntoVector(fileData, fileSize, sheetName);
		for (int i = 1; i < result.size(); i++)
		{

			auto dto = GetCostDTO::createShared();  // 创建对象
			dto->cost_code = oatpp::String(result[i][0]);
			dto->cost_name = oatpp::String(result[i][1]);
			dto->cost_type = oatpp::String(result[i][2]);
			service.saveData(dto, payload);
		}
	}
	else
	{
		jvo->fail("No file uploaded");
		return jvo;
	}

	jvo->success("uploaded file success");
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> ExpenseinoutController::execExportData(const ExpenseTypeQuery::Wrapper& query)
{
	ExpenseTypeService service;

	auto result = service.exportData(query);

	std::string fullPath = result;
	// 读取文件
	auto fstring = String::loadFromFile(fullPath.c_str());

	// 判断是否读取成功
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息

	response->putHeader("Content-Disposition", "attachment; filename=test.xlsx");

	// 影响成功结果
	return response;
}