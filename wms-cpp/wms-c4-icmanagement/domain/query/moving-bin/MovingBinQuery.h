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
#ifndef _MOVINGBIN_QUERY_
#define _MOVINGBIN_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 动仓盘点分页查询对象，用于输入查询条件
 */
class MovingBinQuery : public PageQuery
{
	DTO_INIT(MovingBinQuery, PageQuery);

	// 储位
	API_DTO_FIELD_DEFAULT(String, bin_id, ZH_WORDS_GETTER("bin.field.bin_id"));
	
	// 托盘
	API_DTO_FIELD_DEFAULT(String, tin_id, ZH_WORDS_GETTER("bin.field.tin_id"));
	
	// 商品编码
	API_DTO_FIELD_DEFAULT(String, goods_id, ZH_WORDS_GETTER("bin.field.goods_id"));
	
	// 商品名称
	API_DTO_FIELD_DEFAULT(String, goods_name, ZH_WORDS_GETTER("bin.field.goods_name"));

	// 最后拣货时间起始部分
	API_DTO_FIELD_DEFAULT(String, last_pick_time_start, ZH_WORDS_GETTER("bin.field.last_pick_time_start"));

	// 最后拣货时间结束部分
	API_DTO_FIELD_DEFAULT(String, last_pick_time_end, ZH_WORDS_GETTER("bin.field.last_pick_time_endAA"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MOVINGBIN_QUERY_