#pragma once
#ifndef _BAACTTYPE_QUERY_
#define _BAACTTYPE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 作业类型分页查询对象
 */
class BaActTypeQuery : public PageQuery
{
    DTO_INIT(BaActTypeQuery, PageQuery);

    // 作业类型代码
    API_DTO_FIELD_DEFAULT(String, act_type_code, ZH_WORDS_GETTER("ba_act_type.field.act_type_code"));

    // 作业类型名称
    API_DTO_FIELD_DEFAULT(String, act_type_name, ZH_WORDS_GETTER("ba_act_type.field.act_type_name"));

    // 业务环节
    API_DTO_FIELD_DEFAULT(String, oper_step_code, ZH_WORDS_GETTER("ba_act_type.field.oper_step_code"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_BAACTTYPE_QUERY_
