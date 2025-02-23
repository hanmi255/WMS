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
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TUOPAN_QUERY_