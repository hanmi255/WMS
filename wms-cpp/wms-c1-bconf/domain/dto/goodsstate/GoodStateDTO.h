#pragma once
#ifndef _GOODSTATEDTO_H_
#define _GOODSTATEDTO_H_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class GoodStateDTO : public oatpp::DTO
{
	DTO_INIT(GoodStateDTO, DTO);
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
	API_DTO_FIELD_DEFAULT(String, qm_sta_code, ZH_WORDS_GETTER("goodsstate.qm_qa_code"));
	// 品质代码名称
	API_DTO_FIELD_DEFAULT(String, qm_sta_name, ZH_WORDS_GETTER("goodsstate.qm_qa_name"));
};
/**
 * 示例分页传输对象
 */
class  GoodStatePageDTO : public PageDTO<GoodStateDTO::Wrapper>
{
	DTO_INIT(GoodStatePageDTO, PageDTO<GoodStateDTO::Wrapper>);
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
	CC_SYNTHESIZE(string, qm_sta_code, Qm_sta_code);
	// 品质代码名称
	CC_SYNTHESIZE(string, qm_sta_name, Qm_sta_name);
};

/**
 * 批量删除请求 DTO
 */
class BatchDeleteRequestDTO : public oatpp::DTO
{
	DTO_INIT(BatchDeleteRequestDTO, DTO);
	// 批量删除的 ID 列表
	API_DTO_FIELD_DEFAULT(oatpp::List<oatpp::String>, ids, ZH_WORDS_GETTER("goodsstate.ids"));
};



#include OATPP_CODEGEN_END(DTO)

#endif // !_GOODSTATEDTO_H_