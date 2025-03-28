#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/02/24 11:19:05

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _COMNAMELISTCONTROLLER_
#define _COMNAMELISTCONTROLLER_

#include"domain/query/companyattribute/CompanyNameQuery.h"
#include"domain/vo/companyattribute/CompanyNameVO.h"
#include"domain/dto/companyattribute/CompanyNameDTO.h"
#include"domain/vo/BaseJsonVO.h"
#include <iostream>

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

/*
企业基础资料信息管理
*/


class ComNameListController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(ComNameListController);
public:
	//  定义企业状态查询接口描述
	ENDPOINT_INFO(queryForList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("company.field.companylist"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CompanyNameJsonVO);
	}

	ENDPOINT(API_M_GET, "/entattr/get-entattrname", queryForList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		//API_HANDLER_QUERY_PARAM(enterprisePartQuery, CompanyNameQueryStatus, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryForList());
	}

private:
	CompanyNameJsonVO::Wrapper execQueryForList(); //下拉列表
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section

#endif // !_ENTERPRISE_CONTROLLER_
