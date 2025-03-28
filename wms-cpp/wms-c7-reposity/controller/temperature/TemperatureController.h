#pragma once
/*
 @Author: gutianxuan
*/
#ifndef _TEMPERATURE_CONTROLLER_
#define _TEMPERATURE_CONTROLLER_

#include "domain/GlobalInclude.h"
#include "domain/vo/temperature/TemperatureVO.h"
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "../../lib-common/include/id/UuidFacade.h"
#include "domain/query/temperature/TemperatureQuery.h"



// 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 仓库管理-温度属性控制
 */
class TemperatureController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(TemperatureController);

public:

	//温度属性修改接口说明
	ENDPOINT_INFO(modifyTemperature) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("reposity.temperature.modify.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);

	}
	//温度属性修改接口
	ENDPOINT(API_M_PUT, "/repository/temperature/modify", modifyTemperature, BODY_DTO(TemperatureModifyDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execModifyTemperature(dto, authObject->getPayload()));

	};



	//温度属性删除接口说明
	ENDPOINT_INFO(removeTemperature) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("reposity.temperature.remove.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);

	}
	//温度属性删除接口 
	ENDPOINT(API_M_DEL, "/repository/temperature/remove", removeTemperature, PATH(String, id), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execRemoveTemperature(id));
	};


	// 定义一个excel导入接口
	// 定义描述
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("reposity.temperature.excelin.summary"), uploadExcel, Uint64JsonVO::Wrapper);
	// 定义端点
	API_HANDLER_ENDPOINT(API_M_POST, "/repository/temperature/uploadexcel", uploadExcel, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadExcel(request));



	////定义一个excel导出接口
	// 定义描述
	ENDPOINT_INFO(downloadExcel) {

		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("reposity.temperature.excelout.summary"), Void);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/repository/temperature/downloadexcel", downloadExcel, QUERY(String, filename)) {
		return execDownloadExcel(filename);
	}


	//  获取查询温度属性名称接口描述
	ENDPOINT_INFO(queryNameTemperature) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("reposity.temperature.queryname.summary"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(TemperatureNamePageJsonVO);
	}
	// 定义查询订单类型接口处理
	ENDPOINT(API_M_GET, "/repository/temperature/queryname", queryNameTemperature, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(temperatureQuery, PageQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryNameTemperature(temperatureQuery));
	}


	//  定义查询订单类型列表接口描述
	ENDPOINT_INFO(queryTemperature) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("repository.temperature.queryall.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 定义查询订单类型接口处理
	ENDPOINT(API_M_GET, "/repository/temperature/queryall", queryTemperature, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(temperatureQuery, TemperatureQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryTemperature(temperatureQuery));
	}



	//定义新增温度属性接口处理
	ENDPOINT_INFO(addTemperature) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("repository.temperature.add.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(TemperaturePageJsonVO);
	}

	// 定义新增温度属性接口
	ENDPOINT(API_M_POST, "/repository/temperature/add", addTemperature, BODY_DTO(TemperatureAddDTO::Wrapper, adddto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddTemperature(adddto, authObject->getPayload()));
	}


private:
	//修改数据执行函数
	Uint64JsonVO::Wrapper execModifyTemperature(const TemperatureModifyDTO::Wrapper&, const PayloadDTO& payload);
	//删除数据执行函数
	Uint64JsonVO::Wrapper execRemoveTemperature(const String& id);
	//excel导入
	StringJsonVO::Wrapper execUploadExcel(const std::shared_ptr<IncomingRequest> request);
	//excel导出
	std::shared_ptr<OutgoingResponse> execDownloadExcel(const String filename);

	//温度属性名称查询
	TemperatureNamePageJsonVO::Wrapper execQueryNameTemperature(const PageQuery::Wrapper& query);
	//温度属性列表查询
	TemperaturePageJsonVO::Wrapper execQueryTemperature(const TemperatureQuery::Wrapper& temperatureQuery);
	//新增温度属性
	Uint64JsonVO::Wrapper execAddTemperature(const TemperatureAddDTO::Wrapper& adddto, const PayloadDTO& payload);



};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _TEMPERATURE_CONTROLLER_