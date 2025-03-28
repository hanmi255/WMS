#pragma once
#include "../../GlobalInclude.h"
#include "../wms-c7-reposity/domain/dto/BusstyDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class BusstyJsonVO : public JsonVO<tyleadDTO::Wrapper> {
	DTO_INIT(BusstyJsonVO, JsonVO<tyleadDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
