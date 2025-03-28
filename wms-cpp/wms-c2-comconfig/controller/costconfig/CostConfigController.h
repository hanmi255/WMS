#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: todou
 @Date: 2022/10/25 0:27:04

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

#ifndef _COSTCONFIG_CONTROLLER_
#define _COSTCONFIG_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/costconfig/CostConfigQuery.h"
#include "domain/dto/costconfig/CostConfigDTO.h"
#include "domain/vo/costconfig/CostConfigdeleteVO.h"
#include "domain/GlobalInclude.h"
#include"domain/vo/CDMattr/CDMinfoVO.h"
#include"domain/dto/CDMattr/CDMDTO.h"
#include"domain/vo/BaseJsonVO.h"
#include"service/comdegdm/CDMService.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 客户计费方式-删除计费方式
 */
class CostConfigController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	bool performDeleteOperation(const UInt64& id)
	{
		// 这里添加实际的删除逻辑，例如调用数据库删除操作
		// 示例代码，返回 true 表示删除成功
		return true;
	}
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(CostConfigController);
	// 3 定义接口
public:
	// 3.1 定义删除接口描述
	ENDPOINT_INFO(waydelete) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("CostConfigQuery.delete.query"), StringJsonVO::Wrapper);
		// 定义其他路径参数说明
	//	API_DEF_ADD_PATH_PARAMS(UInt64, "code", ZH_WORDS_GETTER("CostConfigQuery.way.code"), 1, true);
	}
	// 3.2 定义删除接口处理
	//API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/com/deg", waydelete, PATH(UInt64, code), execwaydelete(code));
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/entleve/delete-entleve", waydelete, PATH(CddDTO::Wrapper, id), execwaydelete(id));

private:
	// 3.3 删除数据
	StringJsonVO::Wrapper execwaydelete(const CddDTO::Wrapper& id);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif 