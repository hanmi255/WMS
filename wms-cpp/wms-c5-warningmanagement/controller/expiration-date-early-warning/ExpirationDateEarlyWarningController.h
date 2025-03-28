#pragma once
#ifndef _EXPIRATION_DATE_EARLY_WARNING_CONTROLLER_
#define _EXPIRATION_DATE_EARLY_WARNING_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/expiration-date-early-warning/ExpirationDateEarlyWarningQuery.h"
#include "domain/vo/expiration-date-early-warning/ExpirationDateEarlyWarningVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class ExpirationDateEarlyWarningController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ExpirationDateEarlyWarningController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryListOfWarning) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("EWM.getthewarninglist"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ExpirationDateEarlyWarningPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "productcode", ZH_WORDS_GETTER("EWM.productcode"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "customerproductcode", ZH_WORDS_GETTER("EWM.customerproductcode"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "productname", ZH_WORDS_GETTER("EWM.productname"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "customercode", ZH_WORDS_GETTER("EWM.customercode"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "customername", ZH_WORDS_GETTER("EWM.customername"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "productiondate", ZH_WORDS_GETTER("EWM.productiondate"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "expirationdate", ZH_WORDS_GETTER("EWM.expirationdate"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "The lower value of the remaining ratio", ZH_WORDS_GETTER("EWM.The lower value of the remaining ratio"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "The upper value of the remaining ratio", ZH_WORDS_GETTER("EWM.The upper value of the remaining ratio"), "", false);

	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/warningmanagement/expiration-date-early-warning/query-list-of-warning", queryListOfWarning, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, ExpirationDateEarlyWarningQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryListOfWarning(userQuery, authObject->getPayload()));
	}


private:
	// 3.3 演示分页查询数据
	ExpirationDateEarlyWarningPageJsonVO::Wrapper execQueryListOfWarning(const ExpirationDateEarlyWarningQuery::Wrapper& query, const PayloadDTO& payload);

};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _EXPIRATION_DATE_EARLY_WARNING_CONTROLLER_