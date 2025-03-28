#pragma once

#ifndef _LEVELSNAME_CONTROLLER_
#define _LEVELSNAME_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/enterprise-level/GetEnterpriseLevelNameDTO.h"
#include "domain/vo/enterprise-level/GetEnterpriseLevelNameVO.h"


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class LevelsNameController : public oatpp::web::server::api::ApiController // 1 继承控制器

{	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(LevelsNameController);
public:
	// 3.1 定义新增接口描述
	ENDPOINT_INFO(GetLevelName) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("enterprise.level.name"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(EnterpriseLevelNameJseonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "ID", ZH_WORDS_GETTER("enterprise.level.ID"), "123341", false);
	}
	// 3.2 定义新增接口处理
	ENDPOINT(API_M_GET, "/enterprise/level/name", GetLevelName, BODY_DTO(EnterpriseLevelNameDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execGetLevelName());
	}

private:
	EnterpriseLevelNameJseonVO::Wrapper execGetLevelName();
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) 
#endif // _LEVELNAME_CONTROLLER_