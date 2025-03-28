/*****************************************************************************
    *  @COPYRIGHT NOTICE
    *  @Copyright (c) 2013, kato1
    *  @All rights reserved
    *  @file	 : ListgoodsController.cpp
    *  @version  : ver 1.0
    *  @author   : kato1
    *  @date     : 2025/2/26 17:04
    *  @brief    : brief
*****************************************************************************/
#include "stdafx.h"
#include "ListgoodsController.h"
#include "../../service/adjust-list/AdjustlistService.h"
#include "../../service/adjust-list/ListgoodsService.h"
ListgoodsPageJsonVO::Wrapper ListgoodsController::execQueryPage(const ListgoodsQuery1::Wrapper& query, const PayloadDTO& payload) {
	// 定义一个Service
	AdjustlistService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ListgoodsPageJsonVO::createShared();
	jvo->success(result);
	return jvo;

}




ListgoodsdetailJsonVO::Wrapper ListgoodsController::execQuerydetail(const String&id) {

	// 定义返回数据对象
	auto jvo = ListgoodsdetailJsonVO::createShared();

	// 参数校验
	// 非空校验
	if (!id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (id.getValue({}) == "")
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	AdjustlistService service;
	// 执行数据新增
	auto res = service.getById(id.getValue({}));
	jvo->success(res);

	//响应结果
	return jvo;

}


StringJsonVO::Wrapper ListgoodsController::execModifyListgoods(const ListgoodsadjustDTO::Wrapper& dto, const PayloadDTO& payload) {
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->id || dto->id == "")
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	AdjustlistService service;
	// 执行数据修改
	String resultfail = String("fail");
	String resultsuccess = String("success");
	if (service.updateData(dto,payload)) {
		jvo->success(resultsuccess);
	}
	else
	{
		jvo->fail(resultfail);
	}
	// 响应结果
	return jvo;

}	

/************************************************/

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> ListgoodsController::execExportData(const ExportDataQuery::Wrapper& query)
{
	ListGoodsService service;

	auto result = service.exportData(query);

	std::string fullPath = result/* + URIUtil::urlDecode("test.xlsx")*/;
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
	//response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));
	response->putHeader("Content-Disposition", "attachment; filename=test.xlsx" /*ZH_WORDS_GETTER("diff-post.excel.name")*/);

	// 影响成功结果
	return response;
}