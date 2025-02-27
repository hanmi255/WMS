#pragma once
#ifndef _TUOPAN_QUERY_
#define _TUOPAN_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ÍÐÅÌ·ÖÒ³²éÑ¯¶ÔÏó
 */
class TuopanQuery : public PageQuery
{
	DTO_INIT(TuopanQuery, PageQuery);
	// ÍÐÅÌºÅ
	DTO_FIELD(String, tin_id);
	DTO_FIELD_INFO(tin_id) {
		info->description = ZH_WORDS_GETTER("tuopan.field.id");
	}
	// ÍÐÅÌË³Ðò
	DTO_FIELD(String, tin_sort);
	DTO_FIELD_INFO(tin_sort) {
		info->description = ZH_WORDS_GETTER("tuopan.field.order");
	}
	// ´¢Î»
	DTO_FIELD(String, bin_id);
	DTO_FIELD_INFO(bin_id) {
		info->description = ZH_WORDS_GETTER("tuopan.field.place");
	}
	// ÍÐÅÌ×´Ì¬
	DTO_FIELD(String, tin_status);
	DTO_FIELD_INFO(tin_status) {
		info->description = ZH_WORDS_GETTER("tuopan.field.status");
	}
	// Á÷³Ì×´Ì¬
	DTO_FIELD(String, bpm_status);
	DTO_FIELD_INFO(bpm_status) {
		info->description = ZH_WORDS_GETTER("tuopan.field.bpm_status");
	}
	// ËùÊô²¿ÃÅ
	DTO_FIELD(String, sys_org_code);
	DTO_FIELD_INFO(sys_org_code) {
		info->description = ZH_WORDS_GETTER("tuopan.field.sys_org_code");
	}
	// ËùÊô¹«Ë¾
	DTO_FIELD(String, sys_company_code);
	DTO_FIELD_INFO(sys_company_code) {
		info->description = ZH_WORDS_GETTER("tuopan.field.sys_company_code");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TUOPAN_QUERY_