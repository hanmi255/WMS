#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: maomao
 @Date: 2025/2/24 10:25:27

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
#ifndef _DEFPLAT_CONTROLLER_
#define _DEFPLAT_CONTROLLER_
#include "oatpp-swagger/Types.hpp"
#include "domain/GlobalInclude.h"
#include "domain/vo/def-file/DefPlatVo.h"
#include "domain/dto/def-file/DefPlatDto.h"

//#include "domain/query/plc-file/PlcFileQuery.h"
#include "domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

/**
 * 月台管理-月台定义 接口
 */
class DefPlatController : public oatpp::web::server::api::ApiController {

	API_ACCESS_DECLARE(DefPlatController);

public:

	// 3.1 定义删除接口描述
	ENDPOINT_INFO(DelPlat) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("def.del.description"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("def.del.id"), "default", true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/platmanag/def/{id}", DelPlat, PATH(String, id), execDelPlat(id));

	// 月台编辑接口
	ENDPOINT_INFO(EditPlat) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("def.edit.description"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
		//// 定义其他查询参数描述

		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("def.edit.id"), "", true);
		API_DEF_ADD_QUERY_PARAMS(String, "platform_code", ZH_WORDS_GETTER("def.edit.code"), "", true);
		API_DEF_ADD_QUERY_PARAMS(String, "platform_name", ZH_WORDS_GETTER("def.edit.name"), "", true);
	}
	ENDPOINT(API_M_PUT, "/platmanag/def", EditPlat, QUERIES(QueryParams, qps), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数
		API_HANDLER_QUERY_PARAM(dto, DefEditDto, qps);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execEditPlat(dto, authObject->getPayload()));
	}
	// 月台导出接口
	ENDPOINT_INFO(PutPlat) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("def.put.description"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//// 定义其他查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "id1", ZH_WORDS_GETTER("def.put.id"), "", false);
	}
	ENDPOINT(API_M_POST, "/platmanag/def/output", PutPlat, BODY_DTO(DefPutDto::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execPutPlat(authObject->getPayload()));
	}
private:
	Uint64JsonVO::Wrapper execDelPlat(const String& id);
	Uint64JsonVO::Wrapper execEditPlat(const DefEditDto::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execPutPlat(const PayloadDTO& payload);

};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section

#endif // !_DEFPLAT_CONTROLLER_