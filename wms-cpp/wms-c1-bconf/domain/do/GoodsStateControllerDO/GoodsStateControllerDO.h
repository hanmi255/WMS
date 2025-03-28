#pragma once
#ifndef _GOODSSTATECONTROLLERDO_H_
#define _GOODSSTATECONTROLLERDO_H_ 
#include "../DoInclude.h"
class GoodsStateControllerDO
{
	// ID
	CC_SYNTHESIZE(string, id, Id);
	// 创建姓名
	CC_SYNTHESIZE(string, create_name, Create_name);
	// 创建者
	CC_SYNTHESIZE(string, create_by, Create_by);
	// 创建日期
	CC_SYNTHESIZE(string, create_date, Create_date);
	// 更新姓名
	CC_SYNTHESIZE(string, update_name, Update_name);
	// 父更新者
	CC_SYNTHESIZE(string, update_by, Update_by);
	// 更新日期
	CC_SYNTHESIZE(string, update_date, Update_date);
	// 所属部门
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	// 所属公司
	CC_SYNTHESIZE(string, sys_company_code, Sys_company_code);
	// 品质代码
	CC_SYNTHESIZE(string, qm_sta_code, Qm_sta_code);
	// 品质代码名称
	CC_SYNTHESIZE(string, qm_sta_name, Qm_sta_name);
public:
	GoodsStateControllerDO()
	{
		id = " ";
		create_name = " ";
		create_by = " ";
		create_date = " ";
		update_name = " ";
		update_by = " ";
		update_date = " ";
		sys_org_code = " ";
		sys_company_code = " ";
		qm_sta_code = " ";
		qm_sta_name = " ";
	}
};

//给goodsstateDO定义一个别名方便使用

typedef std::shared_ptr<GoodsStateControllerDO> PtrGoodsStateControllerDO;
#endif // !_GOODSSTATECONTROLLERDO_H_