#pragma once

#ifndef _COMPANY_CONTROLLER_
#define _COMPANY_CONTROLLER_

#include "domain/GlobalInclude.h"
#include "domain/vo/company-conf/CompanyInfoVO.h"
#include "domain/query/company-conf/CompanyInfoQuery.h"
#include "domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class CompanyController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(CompanyController);
public:

	// 查询所有企业信息
	ENDPOINT_INFO(queryALL) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("company.query-all.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CompanyPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("company.field.code"), "a01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ChineseSampleName", ZH_WORDS_GETTER("company.field.ChineseSampleName"), "2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ChineseFullName", ZH_WORDS_GETTER("company.field.ChineseFullName"), "2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ChineseAddr", ZH_WORDS_GETTER("company.field.ChineseAddr"), "2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "EnglishSampleName", ZH_WORDS_GETTER("company.field.EnglishSampleName"), "2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "EnglishFullName", ZH_WORDS_GETTER("company.field.EnglishFullName"), "2", false);
	}
	ENDPOINT(API_M_GET, "/cominfo/get-cominfolist", queryALL, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(compQuery, CompanyInfoQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryALL(compQuery));
	}

	// 查询具体企业信息
	ENDPOINT_INFO(queryDETAIL) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("company.query-all.detail"), CompanyInfoVOJsonVO::Wrapper);
		// 定义参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt64, "id", ZH_WORDS_GETTER("company.field.code"), 1, true);
	}
	// 3.2 定义ID查询接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/cominfo/get-cominfodetail", queryDETAIL, QUERY(Int64, id), execQueryDETAIL(id));
	//ENDPOINT_INFO(queryDETAIL) {
	//    // 定义接口标题
	//    API_DEF_ADD_TITLE(ZH_WORDS_GETTER("company.query-all.detail"));
	//    // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
	//    API_DEF_ADD_AUTH();
	//    // 定义响应参数格式
	//    API_DEF_ADD_RSP_JSON_WRAPPER(CompanyPageJsonVO);
	//    // 定义分页查询参数描述
	//    API_DEF_ADD_PAGE_PARAMS();
	//    // 定义其他查询参数描述
	//    API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("company.field.code"), "a01", false);
	//}
	//ENDPOINT(API_M_GET, "/cominfo/get-cominfodetail", queryDETAIL, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
	//    API_HANDLER_QUERY_PARAM(compQuery, CompanyInfoQuery, queryParams);
	//    // 呼叫执行函数响应结果
	//    API_HANDLER_RESP_VO(execQueryDETAIL(compQuery));
	//}

private:
	// 查询所有信息
	CompanyPageJsonVO::Wrapper execQueryALL(const CompanyInfoQuery::Wrapper& query);
	// 查询具体信息
	CompanyInfoVOJsonVO::Wrapper execQueryDETAIL(const Int64& id);
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section

#endif // !_COMPANY_CONTROLLER_