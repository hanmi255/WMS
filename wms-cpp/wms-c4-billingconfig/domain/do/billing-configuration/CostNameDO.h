#pragma once

#ifndef _COST_NAME_DO_
#define _COST_NAME_DO_
#include "../DoInclude.h"

/**
 * 费用名称数据对象
 */
class CostNameDO
{
	// 主键
	CC_SYNTHESIZE(string, id, Id);
	// 费用代码
	CC_SYNTHESIZE(string, cost_code, CostCode);
	// 费用名称
	CC_SYNTHESIZE(string, cost_name, CostName);
	// 费用类型代码
	CC_SYNTHESIZE(string, cost_type_code, CostTypeCode);
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

public:
	CostNameDO() {
		id = "";
		cost_code = "";
		cost_name = "";
		cost_type_code = "";
		create_name = "";
		create_by = "";
		create_date = "";
		update_name = "";
		update_by = "";
		update_date = "";
		sys_org_code = "";
		sys_company_code = "";
	}
};

// 费用名称数据对象指针类型
typedef std::shared_ptr<CostNameDO> PtrCostNameDO;
#endif // !_COST_NAME_DO_