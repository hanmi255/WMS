#pragma once
/*
wangye 2025 02 28
*/
#ifndef _WORKSTATE_DO_
#define _WORKSTATE_DO_
#include "../DoInclude.h"

/**
 * 工作状态数据库实体类
 */
class WorkStateDO
{
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 创建人名称
	CC_SYNTHESIZE(string, create_name, Create_name);
	// 创建人登录名称
	CC_SYNTHESIZE(string, create_by, Create_by);
	// 创建日期
	CC_SYNTHESIZE(string, create_date, Create_date);
	// 更新人名称
	CC_SYNTHESIZE(string, update_name, Update_name);
	// 更新人登陆名称
	CC_SYNTHESIZE(string, update_by, Update_by);
	// 更新日期
	CC_SYNTHESIZE(string, update_date, Update_date);
	// 所属部门
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	// 所属公司
	CC_SYNTHESIZE(string, sys_company_code, Sys_company_code);
	// 工作状态代码
	CC_SYNTHESIZE(string, work_sta_code, Work_sta_code);
	// 工作状态名称
	CC_SYNTHESIZE(string, work_sta_name, Work_sta_name);
public:
	WorkStateDO() {
		id = "";
		create_name = "";
		create_by = "";
		create_date = "";
		update_name = "";
		update_by = "";
		update_date = "";
		sys_org_code = "";
		sys_company_code = "";
		work_sta_code = "";
		work_sta_name = "";
	}
};

#endif // !_WORKSTATE_DO_
