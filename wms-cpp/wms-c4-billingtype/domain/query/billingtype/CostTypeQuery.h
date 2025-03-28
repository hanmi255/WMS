#pragma once

#ifndef  _COST_TYPE_QUERY_
#define  _COST_TYPE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CostTypeQuery : public PageQuery
{
    DTO_INIT(CostTypeQuery, PageQuery);
    DTO_FIELD(UInt64, id); // 主键
    DTO_FIELD(String, cost_code);         // 费用代码
    DTO_FIELD(String, cost_name);         // 费用名称
    DTO_FIELD(String, cost_type);    // 费用类型
    DTO_FIELD(String, create_name);       // 创建人名称
    DTO_FIELD(String, create_date);       // 创建日期
    DTO_FIELD(String, update_name);       // 更新人名称
    DTO_FIELD(String, update_date);       // 更新日期
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_COST_TYPE_QUERY_