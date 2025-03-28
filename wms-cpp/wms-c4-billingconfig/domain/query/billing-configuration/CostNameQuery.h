#pragma once

#ifndef _COST_NAME_QUERY_
#define _COST_NAME_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CostNameQuery : public PageQuery
{
    DTO_INIT(CostNameQuery, PageQuery);
    DTO_FIELD(String, id); // 主键
    DTO_FIELD(String, cost_code);         // 费用代码
    DTO_FIELD(String, cost_name);         // 费用名称
    DTO_FIELD(String, cost_type_code);    // 费用类型代码
    DTO_FIELD(String, create_name);       // 创建人名称
    DTO_FIELD(String, create_by);         // 创建人登录名称
    DTO_FIELD(String, create_date);     // 创建日期
    DTO_FIELD(String, update_name);       // 更新人名称
    DTO_FIELD(String, update_by);         // 更新人登录名称
    DTO_FIELD(String, update_date);     // 更新日期
    DTO_FIELD(String, sys_org_code);      // 所属部门
    DTO_FIELD(String, sys_company_code);  // 所属公司
    DTO_FIELD(Int32, page);               // 分页页码
    DTO_FIELD(Int32, size);               // 分页大小
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_COST_NAME_QUERY_