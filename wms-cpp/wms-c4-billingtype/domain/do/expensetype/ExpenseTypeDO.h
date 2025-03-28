#pragma once
#ifndef _EXPENSETYPEDO_
#define _EXPENSETYPEDO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class ExpenseTypeDO
{
	// 编号id
	CC_SYNTHESIZE(string, id, Id);
	//创建者名称
	CC_SYNTHESIZE(string, create_name, Create_name);
	//创建人登录名称
	CC_SYNTHESIZE(string, create_by, Create_by);
	//创建时间
	CC_SYNTHESIZE(string, create_date, Create_date);
	//更新人名称
	CC_SYNTHESIZE(string, update_name, Update_name);
	//更新人人登录名称
	CC_SYNTHESIZE(string, update_by, Update_by)
	//更新时间
	CC_SYNTHESIZE(string, update_date, Update_date);
	//所属部门
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	//所属公司
	CC_SYNTHESIZE(string, sys_company_code, Sys_company_code);
	//费用代码
	CC_SYNTHESIZE(string, cost_type_code, Cost_type_code);
	//费用名称
	CC_SYNTHESIZE(string, cost_type_name, Cost_type_name);
	//停用
	CC_SYNTHESIZE(string, cost_type_del, Cost_type_del);


public:
	ExpenseTypeDO() {
		id = "";
		create_name = "";
		create_by = "";
		create_date = "";
		update_name = "";
		update_by = "";
		update_date = "";
		sys_org_code = "";
		sys_company_code = "";
		cost_type_code = "";
		cost_type_name = "";
		cost_type_del = "";
	}
};

// 给CostTypeDO智能指针设定一个别名方便使用
typedef std::shared_ptr<ExpenseTypeDO> PtrExpenseTypeDO;
#endif // !_EXPENSETYPEDO_
