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

#ifndef _MOVINGBIN_DO_
#define _MOVINGBIN_DO_
#include "../DoInclude.h"

/**
 * 动仓盘点的数据库实体类
 */
class MovingBinDO
{
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 储位
	CC_SYNTHESIZE(string, bin_id, BinId);
	// 托盘
	CC_SYNTHESIZE(string, tin_id, TinId);
	// 商品编码
	CC_SYNTHESIZE(string, goods_id, GoodsId);
	// 商品名称
	CC_SYNTHESIZE(string, goods_name, GoodsName);
	// 规格
	CC_SYNTHESIZE(string, goods_specification, GoodsSpecification);
	// 生产日期
	CC_SYNTHESIZE(string, goods_pro_date, GoodsProDate);
	// 保质期
	CC_SYNTHESIZE(string, save_date, SaveDate);
	// 到期日
	CC_SYNTHESIZE(string, due_date, DueDate);
	// 总库存
	CC_SYNTHESIZE(string, total_stock, TotalStock);
	// 最后拣货时间
	CC_SYNTHESIZE(string, last_pick_time, LastPickTime);
	// 可用库存
	CC_SYNTHESIZE(string, avail_stock, AvailStock);
	// 待下架
	CC_SYNTHESIZE(string, to_be_taken_down, ToBeTakenDown);
	// 单位
	CC_SYNTHESIZE(string, goods_unit, GoodsUnit);

public:
	MovingBinDO() {
		id = "";
		bin_id = "";
		tin_id = "";
		goods_id = "";
		goods_name = "";
		goods_specification = "";
		goods_pro_date = "";
		save_date = "";
		due_date = "";
		total_stock = "";
		last_pick_time = "";
		avail_stock = "";
		to_be_taken_down = "";
		goods_unit = "";
	}
};
// 给MovingBinDO智能指针设定一个别名方便使用
typedef std::shared_ptr<MovingBinDO> PtrMovingBineDO;
#endif // !_MOVINGBIN_DO_