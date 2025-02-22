#pragma once
#ifndef _QUERY_TP_VO_H_
#define _QUERY_TP_VO_H_
#include "../../GlobalInclude.h"
#include "domain/dto/tuopandingyi/QueryTPDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 获取托盘名称列表JsonVO
*/
class QueryTPListJsonVO : public JsonVO<QueryTPListDTO::Wrapper> {
	DTO_INIT(QueryTPListJsonVO, JsonVO<QueryTPListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_QUERY_TP_VO_H_
