#pragma once

#include "../DoInclude.h"

using namespace std;

class BaActTypeDO
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
    // 作业类型代码
    CC_SYNTHESIZE(string, act_type_code, ActTypeCode);
    // 作业类型名称
    CC_SYNTHESIZE(string, act_type_name, ActTypeName);
    // 业务环节
    CC_SYNTHESIZE(string, oper_step_code, OperStepCode);

public:
    BaActTypeDO()
    {
        id = "";
        create_name = "";
        create_by = "";
        create_date = "";
        update_name = "";
        update_by = "";
        update_date = "";
        sys_org_code = "";
        sys_company_code = "";
        act_type_code = "";
        act_type_name = "";
        oper_step_code = "";
    }
};

// 定义智能指针类型
typedef std::shared_ptr<BaActTypeDO> PtrBaActTypeDO;
