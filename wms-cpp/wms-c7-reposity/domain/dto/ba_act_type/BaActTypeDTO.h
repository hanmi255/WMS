#pragma once

#ifndef _BAACTTYPE_DTO_
#define _BAACTTYPE_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 作业类型基础数据对象
 */
class BaActTypeDTO : public oatpp::DTO
{
    DTO_INIT(BaActTypeDTO, DTO);

    // 作业类型代码
    API_DTO_FIELD_DEFAULT(String, act_type_code, ZH_WORDS_GETTER("ba_act_type.field.act_type_code"));

    // 作业类型名称
    API_DTO_FIELD_DEFAULT(String, act_type_name, ZH_WORDS_GETTER("ba_act_type.field.act_type_name"));

    // 业务环节
    API_DTO_FIELD_DEFAULT(String, oper_step_code, ZH_WORDS_GETTER("ba_act_type.field.oper_step_code"));

	// 唯一ID
    API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("ba_act_type.field.id"));

};

/**
 * 作业类型新增数据对象
 */
class BaActTypeAddDTO : public oatpp::DTO
{
    DTO_INIT(BaActTypeAddDTO, DTO);

    // 作业类型代码
    API_DTO_FIELD_DEFAULT(String, act_type_code, ZH_WORDS_GETTER("ba_act_type.field.act_type_code"));

    // 作业类型名称
    API_DTO_FIELD_DEFAULT(String, act_type_name, ZH_WORDS_GETTER("ba_act_type.field.act_type_name"));

    // 业务环节
    API_DTO_FIELD_DEFAULT(String, oper_step_code, ZH_WORDS_GETTER("ba_act_type.field.oper_step_code"));

};



/**
 * 作业类型详细数据对象
 */
class BaActTypeDetailDTO : public oatpp::DTO {
    DTO_INIT(BaActTypeDetailDTO, DTO);

    // 作业类型代码
    API_DTO_FIELD_DEFAULT(String, act_type_code, ZH_WORDS_GETTER("ba_act_type.field.act_type_code"));

    // 作业类型名称
    API_DTO_FIELD_DEFAULT(String, act_type_name, ZH_WORDS_GETTER("ba_act_type.field.act_type_name"));

    // 业务环节
    API_DTO_FIELD_DEFAULT(String, oper_step_code, ZH_WORDS_GETTER("ba_act_type.field.oper_step_code"));

    // 唯一ID
    API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("ba_act_type.field.id"));

    // 创建人名称
    API_DTO_FIELD_DEFAULT(String, create_name, ZH_WORDS_GETTER("ba_act_type.field.create_name"));

    // 创建人登录名称
    API_DTO_FIELD_DEFAULT(String, create_by, ZH_WORDS_GETTER("ba_act_type.field.create_by"));

    // 创建日期
    API_DTO_FIELD_DEFAULT(String, create_date, ZH_WORDS_GETTER("ba_act_type.field.create_date"));

    // 更新人名称
    API_DTO_FIELD_DEFAULT(String, update_name, ZH_WORDS_GETTER("ba_act_type.field.update_name"));

    // 更新人登录名称
    API_DTO_FIELD_DEFAULT(String, update_by, ZH_WORDS_GETTER("ba_act_type.field.update_by"));

    // 更新日期
    API_DTO_FIELD_DEFAULT(String, update_date, ZH_WORDS_GETTER("ba_act_type.field.update_date"));

    // 所属部门
    API_DTO_FIELD_DEFAULT(String, sys_org_code, ZH_WORDS_GETTER("ba_act_type.field.sys_org_code"));

    // 所属公司
    API_DTO_FIELD_DEFAULT(String, sys_company_code, ZH_WORDS_GETTER("ba_act_type.field.sys_company_code"));
};

/**
 * 作业类型列表分页数据对象
 */
class BaActTypeListPageDTO : public PageDTO<BaActTypeDTO::Wrapper>
{
    DTO_INIT(BaActTypeListPageDTO, PageDTO<BaActTypeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_BAACTTYPE_DTO_
