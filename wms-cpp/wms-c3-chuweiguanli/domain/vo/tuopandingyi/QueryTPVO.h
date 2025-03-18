#pragma once
#ifndef _QUERY_TP_VO_H_
#define _QUERY_TP_VO_H_
#include "../../GlobalInclude.h"
#include "domain/dto/tuopandingyi/QueryTPDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ªÒ»°Õ–≈Ã√˚≥∆JsonVO
*/
class QueryTPListJsonVO : public JsonVO<oatpp::List<QueryTPDTO::Wrapper>> {
	DTO_INIT(QueryTPListJsonVO, JsonVO<oatpp::List<QueryTPDTO::Wrapper>>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_QUERY_TP_VO_H_
