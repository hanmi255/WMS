#pragma once
#ifndef _ACTTYPEQUERY_H_
#define _ACTTYPEQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个获取作业类型列表的数据传输模型
 */
class ActTypeQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(ActTypeQuery, PageQuery);
	// 作业类型代码
	API_DTO_FIELD_DEFAULT(String, act_type_code, ZH_WORDS_GETTER("act_type.field.act_type_code"));
	// 作业类型名称
	API_DTO_FIELD_DEFAULT(String, act_type_name, ZH_WORDS_GETTER("act_type.field.act_type_name"));
	// 业务环节
	API_DTO_FIELD_DEFAULT(String, oper_step_code, ZH_WORDS_GETTER("act_type.field.oper_step_code"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ACTTYPEQUERY_H_