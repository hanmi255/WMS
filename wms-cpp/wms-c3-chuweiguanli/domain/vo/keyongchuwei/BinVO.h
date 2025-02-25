#pragma once
#ifndef _BINVO_
#define _BINVO_
#include "domain/GlobalInclude.h"
#include "domain/dto/keyongchuwei/BinDTO.h"
#include "domain/query/keyongchuwei/BinQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class BinPageJsonVO : public JsonVO<BinPageDTO::Wrapper> {
	DTO_INIT(BinPageJsonVO, JsonVO<BinPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_BINVO_
