#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: fangtang
 @Date: 2025/03/03 10:15:23

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

#ifndef _STT_ON_MOVE_D0_
#define _STT_ON_MOVE_D0_
#include "../DoInclude.h"

/*
* 动碰盘视图实体类型
*/
class SttOnMoveDO
{
	// 创建日期
	CC_SYNTHESIZE(string, create_date, CreateDate);
	// 创建人名称
	CC_SYNTHESIZE(string,create_name,CreateName);
	// 创建人登录名称
	CC_SYNTHESIZE(string, create_by, CreateBy);
	// 唯一标识
	CC_SYNTHESIZE(string, id, Id);
	// 库存类型
	CC_SYNTHESIZE(string,kuctype,Kuctype);
	// 储位
	CC_SYNTHESIZE(string,bin_id,BinId);
	// 托盘
	CC_SYNTHESIZE(string,tin_id,TinId);
	// 货主
	CC_SYNTHESIZE(string,cus_code,CusCode);
	// 货主名称
	CC_SYNTHESIZE(string,cus_name,CusName);
	// 商品编码
	CC_SYNTHESIZE(string,goods_id,GoodsId);
	// 商品数量
	CC_SYNTHESIZE(string,goods_qua,GoodsQua);
	// 商品名称
	CC_SYNTHESIZE(string,shpMingCheng,ShpMingCheng);
	// 生产日期
	CC_SYNTHESIZE(string,goodsProData,GoodsProData);
	// 保质期
	CC_SYNTHESIZE(string,bzhiQi,BzhiQi);
	// 允收天数？？？？？？源自md_goods的毛重
	CC_SYNTHESIZE(string, yushoutianshu, Yushoutianshu);
	// 单位
	CC_SYNTHESIZE(string,goodsUnit,GoodsUnit);
	// 状态
	CC_SYNTHESIZE(string,sttSta,SttSta);
	// 移动状态
	CC_SYNTHESIZE(string, moveSta, MoveSta);
	// 移动日期
	CC_SYNTHESIZE(string, lastMove, LastMove);

public:
	SttOnMoveDO()
	{
		createDate = "";
		createName = "";
		createBy = "";
		id = "";
		kuctype = "";
		kuWeiBianMa = "";
		binId = "";
		cusCode = "";
		zhongWenQch = "";
		goodsId = "";
		goodsQua = "";
		shpMingCheng = "";
		goodsProData = "";
		bzhiQi = "";
		goodsUnit = "";
		yushoutianshu = "";
		sttSta = "";
		moveSta = "";
		lastMove = "";
	}

};

// 给SttOnMoveDO智能指针设定一个别名方便使用
typedef std::shared_ptr<SttOnMoveDO> PtrSttOnMoveDO;
#endif