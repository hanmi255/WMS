/*
* @Author: laughter
*/
#pragma once
#ifndef _COMPANYATTR_CONTROLLER_
#define _COMPANYATTR_CONTROLLER_

#include "domain/GlobalInclude.h"
#include"domain/query/companyattr/CompanyattrQuery.h"
#include"domain/vo/companyattr/CompanyattrVO.h"
#include"domain/dto/companyattr/CompanyattrDTO.h"
#include"domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

/*
企业属性资料信息管理
*/

class CompanyattrController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(CompanyattrController);
public:

	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryAll) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("company.attribute.query"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CompanyattrPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "com_type_code", ZH_WORDS_GETTER("company.attribute.id"), "01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "com_type_name", ZH_WORDS_GETTER("company.attribute.name"), ZH_WORDS_GETTER("company.attribute.nameex"), false);
	}

	ENDPOINT(API_M_GET, "/entattr/get-entattrnamelist", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(companyQuery, CompanyattrQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAll(companyQuery,authObject->getPayload()));
	}

	//新增
	ENDPOINT_INFO(addCompanyAttr) {
		
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("company.attribute.add"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(CompanyattrJsonVO);
	}

	ENDPOINT(API_M_POST, "/entattr/add-entattr", addCompanyAttr, BODY_DTO(CompanyattrListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		
		API_HANDLER_RESP_VO(execAdd(dto, authObject->getPayload()));
	}

	//// 修改
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("company.attribute.mod"), modifyCompanyAttr, CompanyAttrJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/entattr/mod-entattr", modifyCompanyAttr, BODY_DTO(CompanyattrIdListDTO::Wrapper, dto), execModify(dto, authObject->getPayload()));


private:
	//企业属性分页查询
	CompanyattrPageJsonVO::Wrapper execQueryAll(const CompanyattrQuery::Wrapper& query, const PayloadDTO& payload);  //分页查询
	//企业属性修改
	Uint64JsonVO::Wrapper execModify(const CompanyattrIdListDTO::Wrapper& dto, const PayloadDTO& payload);
	//企业属性添加
	Uint64JsonVO::Wrapper execAdd(const CompanyattrListDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section

#endif // !_ENTERPRISE_CONTROLLER_