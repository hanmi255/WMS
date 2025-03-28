#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: JOHAN LIN
 @Date: 2025/02/21 19:29:00

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

#ifndef _COST_ATTRIBUTE_CONTROLLER_
#define _COST_ATTRIBUTE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/cost-attribute/CostAttributeDTO.h"
#include "domain/do/cost-attribute/CostAttributeDO.h"
#include "domain/query/cost-attribute/CostAttributeQuery.h"
#include "domain/vo/cost-attribute/CostAttributeVO.h"
#include "domain/GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class CostAttributeController : public oatpp::web::server::api::ApiController {
	// 定义控制器访问入口
	API_ACCESS_DECLARE(CostAttributeController);

public:
	// --------------------------------------------------------定义删除接口描述--------------------------------------------------------//
	ENDPOINT_INFO(deleteCostAttribute) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("cost.attribute.delete"), StringJsonVO::Wrapper);
		//// 定义其他路径参数说明
		//API_DEF_ADD_PATH_PARAMS(List<String>, "ids", ZH_WORDS_GETTER("cost.attribute.delete"), {"1"}, true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/cost-config/cost-attribute/delete-attribute", deleteCostAttribute, BODY_DTO(List<String>, ids), execDeleteCostAttribute(ids));

	
	// --------------------------------------------------------定义导入客户属性（单文件上传）接口---------------------------------------//
	// 定义描述
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("excel.import"), importFile, StringJsonVO::Wrapper);
	// 定义端点
	API_HANDLER_ENDPOINT(API_M_POST, "/cost-config/cost-attribute/import-attribute", importFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execImportCostAttribute(request));
	
	// --------------------------------------------------------定义导出客户属性（文件下载）接口------------------------------------------//
	// 定义描述
	ENDPOINT_INFO(exportFile) {
		API_DEF_ADD_AUTH();
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("excel.export"), Void);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/cost-config/cost-attribute/export-attribute", exportFile, API_HANDLER_AUTH_PARAME) {
		return execExportCostAttribute();
	}

private:
	// 定义删除客户计费属性执行函数
	StringJsonVO::Wrapper execDeleteCostAttribute(const List<String>& ids);

	// 定义导入客户计费属性执行函数
	StringJsonVO::Wrapper execImportCostAttribute(shared_ptr<IncomingRequest> request);

	// 定义导出客户计费属性执行函数
	std::shared_ptr<OutgoingResponse> execExportCostAttribute();
};

#include OATPP_CODEGEN_END(ApiController)
#endif // !_COST_ATTRIBUTE_CONTROLLER_