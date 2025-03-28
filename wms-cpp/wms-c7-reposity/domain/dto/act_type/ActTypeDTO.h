#pragma once
#ifndef _ACTTYPEDTO_H_
#define _ACTTYPEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个作业类型的基础类型的数据传输模型
 */
class ActTypeBaseDTO : public oatpp::DTO
{
	DTO_INIT(ActTypeBaseDTO, DTO);
	//// 作业类型ID
	//API_DTO_FIELD_DEFAULT(String, act_type_id, ZH_WORDS_GETTER("act_type.field.act_type_id"));
	// 作业类型代码
	API_DTO_FIELD_DEFAULT(String, act_type_code, ZH_WORDS_GETTER("act_type.field.act_type_code"));
	// 作业类型名称
	API_DTO_FIELD_DEFAULT(String, act_type_name, ZH_WORDS_GETTER("act_type.field.act_type_name"));
	// 业务环节
	API_DTO_FIELD_DEFAULT(String, oper_step_code, ZH_WORDS_GETTER("act_type.field.oper_step_code"));
};

/**
 * 定义一个作业类型的详细类型的数据传输模型
 */ 
//class ActTypeDTO : public ActTypeBaseDTO
//{
//	DTO_INIT(ActTypeDTO, ActTypeBaseDTO);
//	// 作业类型ID
//	API_DTO_FIELD_DEFAULT(String, act_type_id, ZH_WORDS_GETTER("act_type.field.act_type_id"));
//	// 创建人名称
//    API_DTO_FIELD_DEFAULT(String, create_name, ZH_WORDS_GETTER("act_type.field.create_name"));
//	// 创建人登录名称
//    API_DTO_FIELD_DEFAULT(String, create_by, ZH_WORDS_GETTER("act_type.field.create_by"));
//	// 创建日期
//    API_DTO_FIELD_DEFAULT(String, create_date, ZH_WORDS_GETTER("act_type.field.create_date"));
//	// 更新人名称
//    API_DTO_FIELD_DEFAULT(String, update_name, ZH_WORDS_GETTER("act_type.field.update_name"));
//	// 更新人登录名称
//    API_DTO_FIELD_DEFAULT(String, update_by, ZH_WORDS_GETTER("act_type.field.update_by"));
//	// 更新日期
//    API_DTO_FIELD_DEFAULT(String, update_date, ZH_WORDS_GETTER("act_type.field.update_date"));
//	// 所属部门
//    API_DTO_FIELD_DEFAULT(String, sys_org_code, ZH_WORDS_GETTER("act_type.field.sys_org_code"));
//	// 所属公司
//    API_DTO_FIELD_DEFAULT(String, sys_company_code, ZH_WORDS_GETTER("act_type.field.sys_company_code"));
//
//};

/**
 * 定义一个录入作业类型的数据传输模型
 */
class ActTypeDTO : public ActTypeBaseDTO
{
	DTO_INIT(ActTypeDTO, ActTypeBaseDTO);
	// 作业类型ID
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("act_type.field.act_type_id"));
};



/**
*  作业列表分页传输对象
*/
//class ActTypeListDTO : public PageDTO<ActTypeDTO::Wrapper> 
//{
//	DTO_INIT(ActTypeListDTO, PageDTO);
//};
class ActTypePageDTO : public PageDTO<ActTypeDTO::Wrapper>
{
	DTO_INIT(ActTypePageDTO, PageDTO<ActTypeDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // _ACTTYPEDTO_H_