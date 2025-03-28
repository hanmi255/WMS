#ifndef _CITYTYPE_QUERY_
#define _CITYTYPE_QUERY_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class CityTypeQuery : public PageQuery
{
	DTO_INIT(CityTypeQuery, PageQuery);

	// 城市类型代码
	DTO_FIELD(String, city_type_code);
	DTO_FIELD_INFO(city_type_code) {
		info->description = ZH_WORDS_GETTER("citytype.code");
	}
	// 城市类型名称
	DTO_FIELD(String, city_type_name);
	DTO_FIELD_INFO(city_type_name) {
		info->description = ZH_WORDS_GETTER("citytype.name");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif 