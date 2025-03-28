#ifndef _BAREAINFO_QUERY_
#define _BAREAINFO_QUERY_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class BareaInfoQuery : public PageQuery
{
	DTO_INIT(BareaInfoQuery, PageQuery);
	// 片区代码
	DTO_FIELD(String, barea_code);
	DTO_FIELD_INFO(barea_code) {
		info->description = ZH_WORDS_GETTER("BareaInfo.excel.head1");
	}
	// 片区名称
	DTO_FIELD(String, barea_name);
	DTO_FIELD_INFO(barea_name) {
		info->description = ZH_WORDS_GETTER("BareaInfo.excel.head2");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif 