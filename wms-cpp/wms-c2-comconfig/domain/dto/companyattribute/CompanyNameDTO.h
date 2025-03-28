#pragma once

#ifndef _COMPANYNAME_DTO_
#define _COMPANYNAME_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//获取状态下拉列表
class CompanyNameDTO : public oatpp::DTO
{
	DTO_INIT(CompanyNameDTO, oatpp::DTO);

	//唯一标识符
	DTO_FIELD(List<String>, id) = {};
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("company.field.id");
	}

	// 企业代码
	DTO_FIELD(List<String>, code) = {};
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("company.field.code");
	}

	// 企业名称
	DTO_FIELD(List<String>, name) = {};
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("company.field.name");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
