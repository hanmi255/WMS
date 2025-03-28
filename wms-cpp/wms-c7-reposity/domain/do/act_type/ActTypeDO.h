#pragma once
#ifndef _ACTTYPEDO_H_
#define _ACTTYPEDO_H_
#include "../DoInclude.h"

class ActTypeDO {
	// 唯一编号
	CC_SYNTHESIZE(string, id, Id);
	// 作业类型代码
	CC_SYNTHESIZE(string, act_type_code, ActTypeCode);
	// 作业类型名称
	CC_SYNTHESIZE(string, act_type_name, ActTypeName);
	// 业务环节
	CC_SYNTHESIZE(string, oper_step_code, OperStepCode);
	// 创建日期
    CC_SYNTHESIZE(string, create_date, CreateDate);
	// 创建人名称
    CC_SYNTHESIZE(string, create_name, CreateName);
	// 创建人登录名称
	CC_SYNTHESIZE(string, create_by, CreateBy);
	// 所属部门
    CC_SYNTHESIZE(string, sys_org_code, SysOrgCode);
	// 所属公司
    CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode);


public:
	ActTypeDO() : id(""), act_type_code(""), act_type_name(""), oper_step_code(""){}
	ActTypeDO(string id, string act_type_code, string act_type_name, string oper_step_code)
	{
		this->id = id;
		this->act_type_code = act_type_code;
		this->act_type_name = act_type_name;
		this->oper_step_code = oper_step_code;
	}
};

typedef std::shared_ptr<ActTypeDO> PtrActTypeDO;

#endif // !_ACTTYPEDO_H_