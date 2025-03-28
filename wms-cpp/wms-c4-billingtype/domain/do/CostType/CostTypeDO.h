#pragma once
#ifndef _COST_TYPE_DO_
#define _COST_TYPE_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class CostTypeDO
{
	// 编号id
	CC_SYNTHESIZE(uint64_t, id, Id);
	//费用代码
	CC_SYNTHESIZE(string, cost_code, Cost_code);
	//费用名称
	CC_SYNTHESIZE(string, cost_name, Cost_name);
	//费用类型
	CC_SYNTHESIZE(string, cost_type, Cost_type);
	//创建者名称
	CC_SYNTHESIZE(string, create_name, Create_name);
	//创建时间
	CC_SYNTHESIZE(string, create_date, Create_date);
	//创建者（fangtang新增
	CC_SYNTHESIZE(string, create_by, Create_by);
	//修改名称
	CC_SYNTHESIZE(string, update_name, Update_name);
	//修改时间
	CC_SYNTHESIZE(string, update_date, Update_date);

	// 所属部门、公司……（fangtang新增
	CC_SYNTHESIZE(string, sys_org_code, SysOrgCode);
	// 所属公司  
	CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode);

public:
	CostTypeDO() {
		id = 1;
		cost_code = "";
		cost_name = "";
		cost_type = "";
		create_by = "";
		create_name = "";
		create_date = "";
		update_name = "";
		update_date = "";
	}
};

// 给CostTypeDO智能指针设定一个别名方便使用
typedef std::shared_ptr<CostTypeDO> PtrCostTypeDO;
#endif // !_COST_TYPE_DO_
