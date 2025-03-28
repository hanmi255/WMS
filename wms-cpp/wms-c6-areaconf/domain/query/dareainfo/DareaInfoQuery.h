#ifndef _DAREAINFO_QUERY_
#define _DAREAINFO_QUERY_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class DareaInfoQuery : public PageQuery
{
	DTO_INIT(DareaInfoQuery, PageQuery);

	// 大区代码
	DTO_FIELD(String, area_code);
	DTO_FIELD_INFO(area_code) {
		info->description = ZH_WORDS_GETTER("DareaInfo.area_code");
	}
	// 大区名称
	DTO_FIELD(String, area_name);
	DTO_FIELD_INFO(area_name) {
		info->description = ZH_WORDS_GETTER("DareeaInfo.area_name");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif 