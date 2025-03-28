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

#ifndef _MOVINGBIN_DTO_
#define _MOVINGBIN_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *	动仓盘点基本数据传输对象，要展示的内容
 */
class MovingBinDTO : public oatpp::DTO
{
	DTO_INIT(MovingBinDTO, DTO);
	//唯一标识
	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("bin.field.id"), false, "1");
	
};

/**
 * 动仓盘点列表传输对象，唯一标识
 */
class MovingBinListDTO : public MovingBinDTO
{
	DTO_INIT(MovingBinListDTO, MovingBinDTO);
	// 储位
	API_DTO_FIELD(String, bin_id, ZH_WORDS_GETTER("bin.field.bin_id"), false, "A221");

	// 托盘
	API_DTO_FIELD(String, tin_id, ZH_WORDS_GETTER("bin.field.tin_id"), false, "A00001");

	// 商品编码
	API_DTO_FIELD(String, goods_id, ZH_WORDS_GETTER("bin.field.goods_id"), false, "RL001");

	// 商品名称
	API_DTO_FIELD(String, goods_name, ZH_WORDS_GETTER("bin.field.goods_name"), false, "iPhone");

	// 规格
	API_DTO_FIELD(String, goods_specification, ZH_WORDS_GETTER("bin.field.specification"), false, ZH_WORDS_GETTER("bin.field.zhi"));

	// 生产日期
	API_DTO_FIELD(String, goods_pro_date, ZH_WORDS_GETTER("bin.field.goods_pro_date"), false, "2025-03-01");

	// 保质期
	API_DTO_FIELD(String, save_date, ZH_WORDS_GETTER("bin.field.goods_save_date"), false, "360");

	// 到期日
	API_DTO_FIELD(String, due_date, ZH_WORDS_GETTER("bin.field.due_date"), false, "2025-09-01");

	// 总库存
	API_DTO_FIELD(String, total_stock, ZH_WORDS_GETTER("bin.field.total_stock"), false, "40");

	// 最后拣货时间
	API_DTO_FIELD(String, last_pick_time, ZH_WORDS_GETTER("bin.field.last_pick_time"), false, "2025-02-21 10:00:00");

	// 可用库存
	API_DTO_FIELD(String, avail_stock, ZH_WORDS_GETTER("bin.field.avail_stock"), false, "31");

	// 待下架
	API_DTO_FIELD(String, to_be_taken_down, ZH_WORDS_GETTER("bin.field.to_be_taken_down"), false, "33");

	// 单位
	API_DTO_FIELD(String, goods_unit, ZH_WORDS_GETTER("bin.field.goods_unit"), false, ZH_WORDS_GETTER("bin.field.xiang"));
};

/**
 * 动仓盘点分页传输对象
 */
class MovingBinPageDTO : public PageDTO<MovingBinListDTO::Wrapper>
{
	DTO_INIT(MovingBinPageDTO, PageDTO<MovingBinListDTO::Wrapper>);

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MOVINGBIN_DTO_