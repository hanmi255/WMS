#pragma once
#include "domain/do/DoInclude.h"

class MoveGoodsDO {
	CC_SYNTHESIZE(string, id, Id);							   // 主键
	CC_SYNTHESIZE(string, create_name, CreateName);			   // 创建人名称
	CC_SYNTHESIZE(string, create_by, CreateBy);				   // 创建人登录名称
	CC_SYNTHESIZE(string, create_date, CreateDate);			   // 创建日期
	CC_SYNTHESIZE(string, update_name, UpdateName);			   // 更新人名称
	CC_SYNTHESIZE(string, update_by, UpdateBy);				   // 更新人登录名称
	CC_SYNTHESIZE(string, update_date, UpdateDate);			   // 更新日期
	CC_SYNTHESIZE(string, sys_org_code, SysOrgCode);		   // 所属部门
	CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode);   // 所属公司
	CC_SYNTHESIZE(string, order_type_code, OrderTypeCode);	   // 原始单据类型
	CC_SYNTHESIZE(string, order_id, OrderId);				   // 原始单据编码
	CC_SYNTHESIZE(string, order_id_i, OrderIdI);			   // 原始单据行项目
	CC_SYNTHESIZE(string, goods_id, GoodsId);			       // 商品编码
	CC_SYNTHESIZE(string, goods_name, GoodsName);			   // 商品名称
	CC_SYNTHESIZE(string, goods_qua, GoodsQua);				   // 数量
	CC_SYNTHESIZE(string, goods_pro_data, GoodsProData);	   // 生产日期
	CC_SYNTHESIZE(string, goods_unit, GoodsUnit);			   // 单位
	CC_SYNTHESIZE(string, cus_code, CusCode);				   // 客户编码
	CC_SYNTHESIZE(string, cus_name, CusName);				   // 客户名称
	CC_SYNTHESIZE(string, tin_from, TinFrom);				   // 源托盘
	CC_SYNTHESIZE(string, tin_id, TinId);					   // 到托盘
	CC_SYNTHESIZE(string, bin_from, BinFrom);				   // 源储位
	CC_SYNTHESIZE(string, bin_to, BinTo);					   // 到储位
	CC_SYNTHESIZE(string, move_sta, MoveSta);				   // 状态
	CC_SYNTHESIZE(string, to_cus_code, ToCusCode);			   // 转移客户
	CC_SYNTHESIZE(string, to_cus_name, ToCusName);			   // 转移客户名称
	CC_SYNTHESIZE(string, base_unit, BaseUnit);				   // 基本单位
	CC_SYNTHESIZE(string, base_goodscount, BaseGoodscount);       // 基本单位数量
	CC_SYNTHESIZE(string, to_goods_pro_data, ToGoodsProData);  // 到生产日期
	CC_SYNTHESIZE(string, run_sta, RunSta);					   // 执行状态

public:
	MoveGoodsDO()
	{
		id = "";
		create_name = "";
		create_by = "";
		create_date = "";
		update_name = "";
		update_by = "";
		update_date = "";
		sys_org_code = "";
		sys_company_code = "";
		order_type_code = "";
		order_id = "";
		order_id_i = "";
		goods_id = "";
		goods_name = "";
		goods_qua = "";
		goods_pro_data = "";
		goods_unit = "";
		cus_code = "";
		cus_name = "";
		tin_from = "";
		tin_id = "";
		bin_from = "";
		bin_to = "";
		move_sta = "";
		to_cus_code = "";
		to_cus_name = "";
		base_unit = "";
		base_goodscount = "";
		to_goods_pro_data = "";
		run_sta = "";
	}
};

// 定义智能指针
using PtrMoveGoodsDO = std::shared_ptr<MoveGoodsDO>;