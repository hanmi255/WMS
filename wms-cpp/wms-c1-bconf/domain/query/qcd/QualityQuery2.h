#pragma once
#ifndef _QUALITYQUERY_H_
#define _QUALITYQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class QualityQuery : public PageQuery
{
	DTO_INIT(QualityQuery, PageQuery);
	// ID
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("goodsstate.id"));
	// 创建姓名
	API_DTO_FIELD_DEFAULT(String, create_name, ZH_WORDS_GETTER("goodsstate.create_name"));
	// 创建者
	API_DTO_FIELD_DEFAULT(String, create_by, ZH_WORDS_GETTER("goodsstate.create_by"));
	// 创建日期
	API_DTO_FIELD_DEFAULT(String, create_date, ZH_WORDS_GETTER("goodsstate.create_date"));
	// 更新姓名
	API_DTO_FIELD_DEFAULT(String, update_name, ZH_WORDS_GETTER("goodsstate.update_name"));
	// 父更新者
	API_DTO_FIELD_DEFAULT(String, update_by, ZH_WORDS_GETTER("goodsstate.update_by"));
	// 更新日期
	API_DTO_FIELD_DEFAULT(String, update_date, ZH_WORDS_GETTER("goodsstate.update_date"));
	// 所属部门
	API_DTO_FIELD_DEFAULT(String, sys_org_code, ZH_WORDS_GETTER("goodsstate.sys_org_code"));
	// 所属公司
	API_DTO_FIELD_DEFAULT(String, sys_company_code, ZH_WORDS_GETTER("goodsstate.sys_company_code"));
	// 品质代码
	API_DTO_FIELD_DEFAULT(String, qm_qa_code, ZH_WORDS_GETTER("goodsstate.qm_qa_code"));
	// 品质代码名称
	API_DTO_FIELD_DEFAULT(String, qm_qa_name, ZH_WORDS_GETTER("goodsstate.qm_qa_name"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_QUALITYQUERY_H_