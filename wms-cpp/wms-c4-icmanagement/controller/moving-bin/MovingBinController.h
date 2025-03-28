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
#ifndef _MOVINGBIN_CONTROLLER_
#define _MOVINGBIN_CONTROLLER_

#include "oatpp-swagger/Types.hpp"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/moving-bin/MovingBinQuery.h"
#include "domain/dto/moving-bin/MovingBinDTO.h"
#include "domain/vo/moving-bin/MovingBinVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 动仓盘点模块控制器，用于盘点动仓中的商品信息
 */
class MovingBinController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(MovingBinController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryMovingBin) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("bin.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(MovingBinPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "bin_id", ZH_WORDS_GETTER("bin.field.bin_id"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "tin_id", ZH_WORDS_GETTER("bin.field.tin_id"), "2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_id", ZH_WORDS_GETTER("bin.field.goods_id"), "3", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_name", ZH_WORDS_GETTER("bin.field.goods_name"), "name", false);
		API_DEF_ADD_QUERY_PARAMS(String, "last_pick_time_start", ZH_WORDS_GETTER("bin.field.last_pick_time_start"), "2025-02-22", false);
		API_DEF_ADD_QUERY_PARAMS(String, "last_pick_time_end", ZH_WORDS_GETTER("bin.field.last_pick_time_end"), "2025-02-27", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/moving-warehouse-inventory/query", queryMovingBin, QUERIES(QueryParams, queryParams) /*, API_HANDLER_AUTH_PARAME*/) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(binQuery, MovingBinQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAll(binQuery));
	}

	//导出所有动仓盘点数据---有查询条件
	ENDPOINT_INFO(exportMovingBin) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("bin.download.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		//API_DEF_ADD_AUTH();
		API_DEF_ADD_QUERY_PARAMS(String, "bin_id", ZH_WORDS_GETTER("bin.field.bin_id"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "tin_id", ZH_WORDS_GETTER("bin.field.tin_id"), "2", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_id", ZH_WORDS_GETTER("bin.field.goods_id"), "3", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_name", ZH_WORDS_GETTER("bin.field.goods_name"), "name", false);
		API_DEF_ADD_QUERY_PARAMS(String, "last_pick_time_start", ZH_WORDS_GETTER("bin.field.last_pick_time_start"), "2025-02-22", false);
		API_DEF_ADD_QUERY_PARAMS(String, "last_pick_time_end", ZH_WORDS_GETTER("bin.field.last_pick_time_end"), "2025-02-27", false);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/moving-warehouse-inventory/download", exportMovingBin, QUERIES(QueryParams, exportParams)/*, API_HANDLER_AUTH_PARAME*/) {
		// 解析查询参数为MovingBinQuery领域模型
		API_HANDLER_QUERY_PARAM(binQuery, MovingBinQuery, exportParams);
		// 呼叫执行函数响应结果
		return execExportMovingBin(binQuery);
	}
private:
	// 执行查询所有数据
	MovingBinPageJsonVO::Wrapper execQueryAll(const MovingBinQuery::Wrapper& query);
	// 执行文件下载处理
	std::shared_ptr<OutgoingResponse> execExportMovingBin(const MovingBinQuery::Wrapper& query);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _MOVINGBIN_CONTROLLER_