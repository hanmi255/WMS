#pragma once

#ifndef _GETLEVELNAME_CONTROLLER_
#define _GETLEVELNAME_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/enterprise-level/GetEnterpriseLevelNameDTO.h"
#include "domain/vo/enterprise-level/GetEnterpriseLevelNameVO.h"
#include "domain/query/enterprise-level/GetEnterPirseLevelNameQuery.h"
#include "service/enterpriselevel/EnterpriseLevelService.h"


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class LevelNameController : public oatpp::web::server::api::ApiController // 1 继承控制器

{	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(LevelNameController);
public:
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(GetLevelName) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("enterprise.level.title"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(EnterpriseLevelNameJseonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("enterprise.level.name"), "1111", false);
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("enterprise.level.code"), "123341", false);
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("enterprise.level.id"), "0007", false);

	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/entleve/level-name", GetLevelName, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, getLevelNameQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execGetLevelName());
	}

private:
	EnterpriseLevelNameJseonVO::Wrapper execGetLevelName();
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) 
#endif // _GETLEVELNAME_CONTROLLER_