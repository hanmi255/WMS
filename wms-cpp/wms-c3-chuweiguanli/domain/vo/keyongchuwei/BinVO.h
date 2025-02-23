#pragma once
#ifndef _BINVO_
#define _BINVO_
#include "domain/GlobalInclude.h"
#include "domain/dto/keyongchuwei/BinDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class BinJsonVO : public JsonVO<BinDTO::Wrapper> {
	DTO_INIT(BinJsonVO, JsonVO<BinDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_BINVO_
