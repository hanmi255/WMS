#pragma once
#ifndef _QUALITYDTO_H_
#define _QUALITYDTO_H_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class QualityDTO : public oatpp::DTO
{
	DTO_INIT(QualityDTO, DTO);
	// 主键
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("qcd.id"));
	// 创建人名称
	API_DTO_FIELD_DEFAULT(String, create_name, ZH_WORDS_GETTER("qcd.create_name"));
	// 创建人登录名称
	API_DTO_FIELD_DEFAULT(String, create_by, ZH_WORDS_GETTER("qcd.create_by"));
	// 创建日期
	API_DTO_FIELD_DEFAULT(String, create_date, ZH_WORDS_GETTER("qcd.create_date"));
	// 更新人名称
	API_DTO_FIELD_DEFAULT(String, update_name, ZH_WORDS_GETTER("qcd.update_name"));
	// 更新人登录名称
	API_DTO_FIELD_DEFAULT(String, update_by, ZH_WORDS_GETTER("qcd.update_by"));
	// 更新日期
	API_DTO_FIELD_DEFAULT(String, update_date, ZH_WORDS_GETTER("qcd.update_date"));
	// 所属部门
	API_DTO_FIELD_DEFAULT(String, sys_org_code, ZH_WORDS_GETTER("qcd.sys_org_code"));
	// 所属公司
	API_DTO_FIELD_DEFAULT(String, sys_company_code, ZH_WORDS_GETTER("qcd.sys_company_code"));
	// 品质代码
	API_DTO_FIELD_DEFAULT(String, qm_qa_code, ZH_WORDS_GETTER("qcd.qm_qa_code"));
	// 品质代码名称
	API_DTO_FIELD_DEFAULT(String, qm_qa_name, ZH_WORDS_GETTER("qcd.qm_qa_name"));
};


/**
 * 示例分页传输对象
 */
class QualityPageDTO2 : public PageDTO<QualityDTO::Wrapper>
{
	DTO_INIT(QualityPageDTO2, PageDTO<QualityDTO::Wrapper>);
	// ID
	CC_SYNTHESIZE(string, id, Id);
	// 创建姓名
	CC_SYNTHESIZE(string, create_name, Create_name);
	// 创建者
	CC_SYNTHESIZE(string, create_by, Create_by);
	// 创建日期
	CC_SYNTHESIZE(string, create_date, Create_date);
	// 更新姓名
	CC_SYNTHESIZE(string, update_name, Update_name);
	// 父更新者
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
};

/**
 * 批量删除
 */
class DeleteDTO : public oatpp::DTO
{
	DTO_INIT(DeleteDTO, DTO);
	// 批量删除的 ID 列表
	DTO_FIELD(Vector<Int32>, ids) = {};
	DTO_FIELD_INFO(ids) {
		info->description = ZH_WORDS_GETTER("qcd.ids");
		info->required = true;
	}
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_QUALITYDTO_H_