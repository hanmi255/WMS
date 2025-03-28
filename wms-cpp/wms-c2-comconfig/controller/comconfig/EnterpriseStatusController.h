#pragma once
#ifndef _ENTERPRISESTATUSCONTROLLER_
#define _ENTERPRISESTATUSCONTROLLER_

#include "domain/GlobalInclude.h"
#include"domain/query/md-cus-other/EnterpriseQuery.h"
#include"domain/vo/md-cus-other/EnterpriseVO.h"
#include"domain/dto/md-cus-other/EnterpriseDTO.h"
#include"domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

/*
企业基础资料信息管理
*/


class EnterpriseController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(EnterpriseController);
public:

	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryAll) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("get.queryall"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(EnterprisePageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "enterpriseid", ZH_WORDS_GETTER("get.enterpriseid"), "C001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "enterprisename", ZH_WORDS_GETTER("get.enterprisename"), ZH_WORDS_GETTER("enterprise.field.example"), false);

	}

	ENDPOINT(API_M_GET, "/entstat/get-entstatlist", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(enterpriseQuery, EnterpriseQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAll(enterpriseQuery));
	}

	// 定义ID查询接口描述
	ENDPOINT_INFO(queryForList) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("get.enterpriselist"), EnterpriseJsonVO::Wrapper);
	}
	// 3.2 定义状态查询接口处理
	ENDPOINT(API_M_GET, "/entstat/get-entstatforlist", queryForList, API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryForList());
	}
	


private:
	EnterprisePageJsonVO::Wrapper execQueryAll(const EnterpriseQuery::Wrapper& query);  //分页查询
	EnterpriseJsonVO::Wrapper execQueryForList(); //下拉列表
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section

#endif // !_ENTERPRISESTATUSCONTROLLER_