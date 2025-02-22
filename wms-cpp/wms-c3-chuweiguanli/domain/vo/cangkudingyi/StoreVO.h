#pragma once
#ifndef STOREVO
#define STOREVO

#include "../../GlobalInclude.h"
#include "dto/cangkudingyi/StoreDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class StoreJsonVO : public JsonVO<StoreDTO::Wrapper> {
	DTO_INIT(StoreJsonVO, JsonVO<StoreDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !STOREVO