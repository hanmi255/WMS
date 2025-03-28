#pragma once
/*
 @Author: yunyin
*/

#ifndef _BUSINESSLINK_CONTROLLER_
#define _BUSINESSLINK_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/business-link/BusinessLinkNameListJsonVO.h"
#include "domain/query/business-link/BusinessLinkQuery.h"
#include "domain/vo/business-link/BusinessLinkJsonVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


class BusinessLinkController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(BusinessLinkController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryBusinessLinkNameList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("business-link.get.namelist"));
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(BusinessLinkNameListJsonVO);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "repository/getnamelist-business-link", queryBusinessLinkNameList) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryBusinessLinkNameList());
	}

	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryBusinessLink) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("business-link.get.businesslink"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(BusinessLinkPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "create_name", ZH_WORDS_GETTER("business-link.field.create-name"), ZH_WORDS_GETTER("business-link.example.create-name"), false);
		API_DEF_ADD_QUERY_PARAMS(String, "create_by", ZH_WORDS_GETTER("business-link.field.create-by"), "admin", false);
		API_DEF_ADD_QUERY_PARAMS(String, "create_date", ZH_WORDS_GETTER("business-link.field.create-date"), "2017-08-02 06:55:20", false);
		API_DEF_ADD_QUERY_PARAMS(String, "update_name", ZH_WORDS_GETTER("business-link.field.update-name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "update_by", ZH_WORDS_GETTER("business-link.field.update-by"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "update_date", ZH_WORDS_GETTER("business-link.field.update-date"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "sys_org_code", ZH_WORDS_GETTER("business-link.field.sys-org-code"), "A05", false);
		API_DEF_ADD_QUERY_PARAMS(String, "sys_company_code", ZH_WORDS_GETTER("business-link.field.sys-company-code"), "A05", false);
		API_DEF_ADD_QUERY_PARAMS(String, "oper_step_code", ZH_WORDS_GETTER("business-link.field.oper-step-code"), "11", false);
		API_DEF_ADD_QUERY_PARAMS(String, "oper_step_name", ZH_WORDS_GETTER("business-link.field.oper-step-name"), "11", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/repository/queryall-business-link", queryBusinessLink, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(businessLinkQuery, BusinessLinkPageDTO, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryBusinessLink(businessLinkQuery, authObject->getPayload()));
	}


	// 3.1 定义新增接口描述
	ENDPOINT_INFO(addBusinessLink) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("business-link.post.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_POST, "/repository/add-business-link", addBusinessLink, BODY_DTO(BusinessLinkAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddBusinessLink(dto));
	}

private:
	// 获取业务环节名称列表
	BusinessLinkNameListJsonVO::Wrapper execQueryBusinessLinkNameList();

	// 获取业务环节（分页+条件）
	BusinessLinkPageJsonVO::Wrapper execQueryBusinessLink(const BusinessLinkPageDTO::Wrapper& query, const PayloadDTO& payload);

	// 新增业务环节
	Uint64JsonVO::Wrapper execAddBusinessLink(const BusinessLinkAddDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _BUSINESSLINK_CONTROLLER_