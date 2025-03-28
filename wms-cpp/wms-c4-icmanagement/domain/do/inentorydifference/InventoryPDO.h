#pragma once
#ifndef _INVENTORY_DO_
#define _INVENTORY_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class InventoryPDO
{
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	//盘点人
	CC_SYNTHESIZE(string, stt_name, Stt_name);
	//盘点日期
	CC_SYNTHESIZE(string, stt_date, Stt_date);
	// 储位
	CC_SYNTHESIZE(string, bin_id, Bin_id);
	//托盘
	CC_SYNTHESIZE(string, tin_id, Tin_id);
	//商品编码
	CC_SYNTHESIZE(string, goods_id, Goods_id);
	//商品名称
	CC_SYNTHESIZE(string, goods_name, Goods_name);
	//账目数量
	CC_SYNTHESIZE(string, goods_qua, Goods_qua);
	//单位
	CC_SYNTHESIZE(string, goods_unit, Goods_unit);
	// 生产日期
	CC_SYNTHESIZE(string, goods_pro_data, Goods_pro_data);
	// 盘点数量
	CC_SYNTHESIZE(string, stt_qua, Stt_qua);
	//货主
	CC_SYNTHESIZE(string, cus_code, Cus_code);
	//货主编码
	CC_SYNTHESIZE(string, cus_id, Cus_id);
	//盘点状态
	CC_SYNTHESIZE(string, stt_sta, Stt_sta);
public:
	InventoryPDO() {
		id = "";
		stt_name = "Li Hua";
		stt_date = "2099-12-31";
		bin_id = "X1-1-03";
		tin_id = "";
		goods_id = "";
		goods_name = "";
		goods_qua = "";
		goods_unit = "个";
		goods_pro_data = "2099-12-31";
		stt_qua = "";
		cus_code = "halo";
		cus_id = "X00001";
		stt_sta = "";
	}
};

// 给InventoryPDO智能指针设定一个别名方便使用
typedef std::shared_ptr<InventoryPDO> PtrInventoryPDO;
#endif // !_INVENTORY_DO_