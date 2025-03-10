#pragma once

#ifndef _TUOPAN_DTO_
#define _TUOPAN_DTO_
#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 托盘列表基础数据对象
 */

class TuopanBaseDTO : public oatpp::DTO
{
	DTO_INIT(TuopanBaseDTO, DTO);

	// 托盘号
	DTO_FIELD(String, tin_id);
	DTO_FIELD_INFO(tin_id) {
		info->description = ZH_WORDS_GETTER("tuopan.field.id");
	}
	// 托盘顺序
	DTO_FIELD(String, tin_sort);
	DTO_FIELD_INFO(tin_sort) {
		info->description = ZH_WORDS_GETTER("tuopan.field.order");
	}
	// 储位
	DTO_FIELD(String, bin_id);
	DTO_FIELD_INFO(bin_id) {
		info->description = ZH_WORDS_GETTER("tuopan.field.place");
	}
	// 托盘状态
	DTO_FIELD(String, tin_status);
	DTO_FIELD_INFO(tin_status) {
		info->description = ZH_WORDS_GETTER("tuopan.field.status");
	}
	// 流程状态
	DTO_FIELD(String, bpm_status);
	DTO_FIELD_INFO(bpm_status) {
		info->description = ZH_WORDS_GETTER("tuopan.field.bpm_status");
	}
	// 所属部门
	DTO_FIELD(String, sys_org_code);
	DTO_FIELD_INFO(sys_org_code) {
		info->description = ZH_WORDS_GETTER("tuopan.field.sys_org_code");
	}
	// 所属公司
	DTO_FIELD(String, sys_company_code);
	DTO_FIELD_INFO(sys_company_code) {
		info->description = ZH_WORDS_GETTER("tuopan.field.sys_company_code");
	}
};

/**
 * 托盘列表传输对象
 */

class TuopanDTO : public TuopanBaseDTO
{
	DTO_INIT(TuopanDTO, TuopanBaseDTO);

	// 主键
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("tuopan.id");
	}
};

/*
* 托盘分页传输对象
*/
class TuopanPageDTO : public PageDTO<TuopanDTO::Wrapper>
{
	DTO_INIT(TuopanPageDTO, PageDTO<TuopanDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TUOPAN_DTO_