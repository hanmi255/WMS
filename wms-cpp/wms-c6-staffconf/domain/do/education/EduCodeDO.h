#pragma once
#ifndef _EduCOdeDO_H_
#define _EduCOdeDO_H_
#include "../../GlobalInclude.h"

class EduCodeDO
{
	// id
	CC_SYNTHESIZE(string, id, Id);
	// 学历代码
	CC_SYNTHESIZE(string, edu_sta_code, Edu_sta_code);
	// 学历名称
	CC_SYNTHESIZE(string, edu_sta_name, Edu_sta_name);
	// 更新人名称
	CC_SYNTHESIZE(string, update_name, Update_name);
	// 更新人登录名称
	CC_SYNTHESIZE(string, update_by, Update_by);
	// 更新日期
	CC_SYNTHESIZE(string, update_date, Update_date);
public:
	EduCodeDO() {}
	EduCodeDO(string id, string edu_sta_code, string edu_sta_name, string update_name, string update_by, string update_date)
	{
		this->id = id;
		this->edu_sta_code = edu_sta_code;
		this->edu_sta_code = edu_sta_name;
		this->update_name = update_name;
		this->update_by = update_by;
		this->update_date = update_date;
	}
};


class EduInfoDO
{
	// id
	CC_SYNTHESIZE(string, id, Id);
	// 创建人名称
	CC_SYNTHESIZE(string, create_name, Create_name);
	// 创建人登录名称
	CC_SYNTHESIZE(string, create_by, Create_by);
	// 创建日期
	CC_SYNTHESIZE(string, create_date, Create_date);
	// 更新人名称
	CC_SYNTHESIZE(string, update_name, Update_name);
	// 更新人登录名称
	CC_SYNTHESIZE(string, update_by, Update_by);
	// 更新日期
	CC_SYNTHESIZE(string, update_date, Update_date);
	// 所属部门
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	// 所属公司
	CC_SYNTHESIZE(string, sys_company_code, Sys_company_code);
	// 学历代码
	CC_SYNTHESIZE(string, edu_sta_code, Edu_sta_code);
	// 学历名称
	CC_SYNTHESIZE(string, edu_sta_name, Edu_sta_name);


public:
	EduInfoDO()
	{
		id = "0";
		create_name = "admin";
		create_by = "x";
		create_date = "x-x-x";
		update_name = "admin";
		update_by = "x";
		update_date = "x-x-x";
		sys_org_code = "x";
		sys_company_code = "x";
		edu_sta_code = "code";
		edu_sta_name = "name";
	}
};

#endif // !_EduCOdeDO_H_


