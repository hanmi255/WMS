#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei

 @Date: 2025/3/4 14:33

*/
#ifndef _WM_TO_UP_GOODS_DO_
#define _WM_TO_UP_GOODS_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class Wm_To_Up_GoodsDO
{
	// 主键  
	CC_SYNTHESIZE(string, id, Id);
	// 创建人名称  
	CC_SYNTHESIZE(string, create_name, CreateName);
	// 创建人登录名称  
	CC_SYNTHESIZE(string, create_by, CreateBy);
	// 创建日期  
	CC_SYNTHESIZE(string, create_date, CreateDate);
	// 更新人名称  
	CC_SYNTHESIZE(string, update_name, UpdateName);
	// 更新人登录名称  
	CC_SYNTHESIZE(string, update_by, UpdateBy);
	// 更新日期  
	CC_SYNTHESIZE(string, update_date, UpdateDate);
	// 所属部门  
	CC_SYNTHESIZE(string, sys_org_code, SysOrgCode);
	// 所属公司  
	CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode);
	// 商品编码  
	CC_SYNTHESIZE(string, goods_id, GoodsId);
	// 数量  
	CC_SYNTHESIZE(string, goods_qua, GoodsQua);
	// 原始单据类型  
	CC_SYNTHESIZE(string, order_type_code, OrderTypeCode);
	// 原始单据编码  
	CC_SYNTHESIZE(string, order_id, OrderId);
	// 原始单据行项目  
	CC_SYNTHESIZE(string, order_id_i, OrderIdI);
	// 上架ID  
	CC_SYNTHESIZE(string, wm_to_up_id, WmToUpId);
	// 单位  
	CC_SYNTHESIZE(string, goods_unit, GoodsUnit);
	// 批次  
	CC_SYNTHESIZE(string, goods_batch, GoodsBatch);
	// 生产日期  
	CC_SYNTHESIZE(string, goods_pro_data, GoodsProData);
	// 作业类型  
	CC_SYNTHESIZE(string, act_type_code, ActTypeCode);
	// 库位编码  
	CC_SYNTHESIZE(string, ku_wei_bian_ma, KuWeiBianMa);
	// 托盘码  
	CC_SYNTHESIZE(string, bin_id, BinId);
	// 货主  
	CC_SYNTHESIZE(string, cus_code, CusCode);
	// 基本单位  
	CC_SYNTHESIZE(string, base_unit, BaseUnit);
	// 基本单位数量  
	CC_SYNTHESIZE(string, base_goodscount, BaseGoodscount);
	// 商品名称  
	CC_SYNTHESIZE(string, goods_name, GoodsName);


public:
	Wm_To_Up_GoodsDO()
		: id("")
		, create_name("")
		, create_by("")
		, create_date("")
		, update_name("")
		, update_by("")
		, update_date("")
		, sys_org_code("")
		, sys_company_code("")
		, goods_id("")
		, goods_qua("")
		, order_type_code("")
		, order_id("")
		, order_id_i("")
		, wm_to_up_id("")
		, goods_unit("")
		, goods_batch("")
		, goods_pro_data("")
		, act_type_code("")
		, ku_wei_bian_ma("")
		, bin_id("")
		, cus_code("")
		, base_unit("")
		, base_goodscount("")
		, goods_name("")
	{
	}
};

// 给Wm_To_Up_GoodsDO智能指针设定一个别名方便使用
typedef std::shared_ptr<Wm_To_Up_GoodsDO> PtrWm_To_Up_GoodsDO;
#endif // _WM_TO_UP_GOODS_DO_
