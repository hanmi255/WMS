#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 圣少游
 @Date: 2025/2/22 11:36:29

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
#ifndef _GOODS_CONTROLLER_
#define _GOODS_CONTROLLER_

#include "oatpp-swagger/Types.hpp"
#include "domain/vo/BaseJsonVO.h"
#include "domain/do/batch-modify-goods/DownGoodsDO.h"
#include "domain/dto/batch-modify-goods/DownGoodsDTO.h"
#include "domain/vo//batch-modify-goods/DownGoodsVO.h"
#include "Macros.h"
#include "domain/query/batch-modify-goods/DownGoodsQuery.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 批量修改下架货物
 */
class DownGoodsController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(DownGoodsController);
	// 3 定义接口
public:


	// 3.1 定义`批量`修改接口
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("goods.modify.summary"), modifyGoods, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/removal-adjustment/batch-modify", modifyGoods, BODY_DTO(DownGoodsBatchDTO::Wrapper, dto), execModifyGoods(dto, authObject->getPayload()));


	//导出所有下架调整数据---有查询条件
	ENDPOINT_INFO(exportRemovalGoods) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("goods.download.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//API_DEF_ADD_AUTH();
		API_DEF_ADD_QUERY_PARAMS(String, "order_id", ZH_WORDS_GETTER("goods.field.order_id"), "123456", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_id", ZH_WORDS_GETTER("goods.field.goods_id"), "123456", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_name", ZH_WORDS_GETTER("goods.field.goods_name"), "123456", false);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/removal-adjustment/download", exportRemovalGoods, QUERIES(QueryParams, exportParams)/*, API_HANDLER_AUTH_PARAME*/) {
		// 解析查询参数为DownGoodsQuery领域模型
		API_HANDLER_QUERY_PARAM(binQuery, DownGoodsQuery, exportParams);
		// 呼叫执行函数响应结果
		return execExportGoods(binQuery);
	}
private:
	// 批量修改下架货物
	StringJsonVO::Wrapper execModifyGoods(const DownGoodsBatchDTO::Wrapper& dto, const PayloadDTO& payload);
	// 执行文件下载处理
	std::shared_ptr<OutgoingResponse> execExportGoods(const DownGoodsQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _GOODS_CONTROLLER_