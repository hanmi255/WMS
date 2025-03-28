#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei

 @Date: 2025/2/22 14:33

*/
#ifndef _WM_STT_IN_GOODS_DO_
#define _WM_STT_IN_GOODS_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class Wm_Stt_In_GoodsDO
{
	// 编号  
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
	// 库位编码  
	CC_SYNTHESIZE(string, bin_id, BinId);
	// 托盘编码  
	CC_SYNTHESIZE(string, tin_id, TinId);
	// 商品编码  
	CC_SYNTHESIZE(string, goods_id, GoodsId);
	// 商品名称  
	CC_SYNTHESIZE(string, goods_name, GoodsName);
	// 数量  
	CC_SYNTHESIZE(string, goods_qua, GoodsQua);
	// 单位  
	CC_SYNTHESIZE(string, goods_unit, GoodsUnit);
	// 生产日期  
	CC_SYNTHESIZE(string, goods_pro_date, GoodsProDate);
	// 批次  
	CC_SYNTHESIZE(string, goods_batch, GoodsBatch);
	// 盘点数量  
	CC_SYNTHESIZE(string, stt_qua, SttQua);
	// 客户名称  
	CC_SYNTHESIZE(string, cus_name, CusName);
	// 客户  
	CC_SYNTHESIZE(string, cus_code, CusCode);
	// 盘点状态  
	CC_SYNTHESIZE(string, stt_sta, SttSta);
	// 基本单位  
	CC_SYNTHESIZE(string, base_unit, BaseUnit);
	// 基本单位数量  
	CC_SYNTHESIZE(string, base_goodscount, BaseGoodscount);
	// stt_id  
	CC_SYNTHESIZE(string, stt_id, SttId);
	// 商品统一编码  
	CC_SYNTHESIZE(string, goods_code, GoodsCode);
	// 盘点类型  
	CC_SYNTHESIZE(string, stt_type, SttType);
	// 动线  
	CC_SYNTHESIZE(string, dong_xian, DongXian);
	
	
public:
	Wm_Stt_In_GoodsDO()
		: id("")
		, create_name("")
		, create_by("")
		, create_date("")
		, update_name("")
		, update_by("")
		, update_date("")
		, sys_org_code("")
		, sys_company_code("")
		, bin_id("")
		, tin_id("")
		, goods_id("")
		, goods_name("")
		, goods_qua("")
		, goods_unit("")
		, goods_pro_date("")
		, goods_batch("")
		, stt_qua("")
		, cus_name("")
		, cus_code("")
		, stt_sta("")
		, base_unit("")
		, base_goodscount("")
		, stt_id("")
		, goods_code("")
		, stt_type("")
		, dong_xian("")
	{
	}
};

// 给Wm_Stt_In_GoodsDO智能指针设定一个别名方便使用
typedef std::shared_ptr<Wm_Stt_In_GoodsDO> PtrWm_Stt_In_GoodsDO;
#endif // _WM_STT_IN_GOODS_DO_
