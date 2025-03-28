#ifndef _ONOCC_QUERY_
#define _ONOCC_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class EsQuery :public PageQuery
{
	DTO_INIT(EsQuery, PageQuery);

	API_DTO_FIELD_DEFAULT(String, pos_sta_code, ZH_WORDS_GETTER("es.field.pos_sta_code"));
	API_DTO_FIELD_DEFAULT(String, pos_sta_name, ZH_WORDS_GETTER("es.field.pos_sta_name"));
};




#include OATPP_CODEGEN_END(DTO)
#endif