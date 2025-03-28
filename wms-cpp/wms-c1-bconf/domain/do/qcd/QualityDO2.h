#pragma once
#ifndef _QUALITYDO_H_
#define _QUALITYDO_H_ 
#include "../DoInclude.h"
class QualityDO
{
	// 主键
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
	// 品质代码
	CC_SYNTHESIZE(string, qm_qa_code, Qm_qa_code);
	// 品质代码名称
	CC_SYNTHESIZE(string, qm_qa_name, Qm_qa_name);
public:
	QualityDO()
	{
		id = " ";
		create_name = "";
		create_by = "";
		create_date = "";
		update_name = "";
		update_by = "";
		update_date = "";
		sys_org_code = "";
		sys_company_code = "";
		qm_qa_code = "";
		qm_qa_name = "";
	}
};

#endif // !_QUALITYDO_H_