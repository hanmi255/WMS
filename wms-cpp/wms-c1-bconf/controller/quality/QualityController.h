#pragma once
#ifndef _QUALITY_CONTROLLER_
#define _QUALITY_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/quality/QualityQuery.h"
#include "domain/dto/quality/QualityDTO.h"
#include "domain/vo/quality/QualityVO.h"

/*
 @Author: S4turday
 @Date: 2025年3月8日19:27:47

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

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 品质代码控制器
 */
class QualityController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(QualityController);
	// 3 定义接口
public:
	// 获取品质代码列表
	ENDPOINT_INFO(quality_query)
	{
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("quality.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(QualityPageJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "qm_qa_code", ZH_WORDS_GETTER("quality.qm_qa_code"), "CDE001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "qm_qa_name", ZH_WORDS_GETTER("quality.qm_qa_name"), "name", false);
	}
	ENDPOINT(API_M_GET, "/qcd/query", quality_query, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		queryParams.getAll();
		API_HANDLER_QUERY_PARAM(quaQuery, QualityQuery, queryParams);
		API_HANDLER_RESP_VO(execquery(quaQuery));
	}

	// 3.1 定义Code查询接口描述
	ENDPOINT_INFO(queryQualityByCode) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("quality.query.bycode"), QualityJsonVO::Wrapper);
		// 定义参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "qm_code", ZH_WORDS_GETTER("quality.qm_qa_code"), 1, true);
	}
	// 3.2 定义Code查询接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/qcd/query-by-code", queryQualityByCode, QUERY(String, code), execQueryByCode(code));

	// 3.1 定义品质代码名称查询接口描述
	ENDPOINT_INFO(queryQualityByName) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("quality.query.byname"), QualityJsonVO::Wrapper);
		// 定义参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("quality.qm_qa_name"), 1, true);
	}
	// 3.2 定义品质代码名称查询接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/qcd/query-by-name", queryQualityByName, QUERY(String, name), execQueryByName(name));


	// 添加品质代码
	ENDPOINT_INFO(quality_add)
	{
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("quality.add.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
 	ENDPOINT(API_M_POST, "/qcd/add", quality_add, BODY_DTO(QualityAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_RESP_VO(execAdd(dto, authObject->getPayload()));
	}

	// 修改品质代码信息
	ENDPOINT_INFO(quality_update)
	{
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("quality.update.summary"));
		API_DEF_ADD_AUTH();

	}
	ENDPOINT(API_M_PUT, "/qcd/update", quality_update, BODY_DTO(QualityListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_RESP_VO(execUpdate(dto, authObject->getPayload()));
	}
private:
	Uint64JsonVO::Wrapper execUpdate(const QualityListDTO::Wrapper& dto, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execAdd(const QualityAddDTO::Wrapper& dto, const PayloadDTO& payload);
	QualityPageJsonVO::Wrapper execquery(const QualityQuery::Wrapper& query);
	QualityJsonVO::Wrapper execQueryByCode(const String& code);
	QualityJsonVO::Wrapper execQueryByName(const String& name);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _QUALITY_CONTROLLER_