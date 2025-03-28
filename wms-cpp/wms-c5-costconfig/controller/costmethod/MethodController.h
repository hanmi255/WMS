#pragma once
#ifndef _METHODCONTROLLER_H_
#define _METHODCONTROLLER_H_
#include "oatpp-swagger/Types.hpp"
#include "domain/query/costmethod/BillMethodQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/costmethod/MethodVO.h"
using namespace oatpp;

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class MethodController : public oatpp::web::server::api::ApiController
{
	// 添加访问定义
	API_ACCESS_DECLARE(MethodController);
public:
	ENDPOINT_INFO(queryAll)
	{
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("method.queryall"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_GET, "cost-config/cost-method/query-all", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_QUERY_PARAM(methodquery, BillmethodQuery, queryParams);
        API_HANDLER_RESP_VO(execQueryall(methodquery));
	}
	ENDPOINT_INFO(query) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("method.query"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(MethodPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "pronut_code", ZH_WORDS_GETTER("pronut_code"), "123", false);
		API_DEF_ADD_QUERY_PARAMS(String, "pronut_name", ZH_WORDS_GETTER("pronut_name"), "by t", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/cost-config/cost-method/query", query, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(methodquery, BillmethodQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQuery(methodquery,authObject->getPayload()));
	}
	ENDPOINT_INFO(addme) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("method.add"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/cost-config/cost-method/add", addme, BODY_DTO(MethodAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddme(dto));
	}

	// 3.1 定义计费方式修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("method.modify"), modifyme, StringJsonVO::Wrapper);
	// 3.2 定义计费方式修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/cost-config/cost-method/modify", modifyme, BODY_DTO(MethodDTO::Wrapper, dto), execModifyme(dto));
private:
	// 查询所有
	MethodPageJsonVO::Wrapper execQuery(const BillmethodQuery::Wrapper& query,const PayloadDTO& payload);
	MethodPageJsonVO::Wrapper execQueryall(const BillmethodQueryomit::Wrapper& query);
	StringJsonVO::Wrapper execAddme(const MethodAddDTO::Wrapper& dto);
    StringJsonVO::Wrapper execModifyme(const MethodDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _USERCONTROLLER_H_