#pragma once
#ifndef _COST_VO_
#define _COST_VO_

#include "../../GlobalInclude.h"
#include "../../dto/billingtype/CostDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class CostJsonVO : public JsonVO<CostListDTO::Wrapper> {
	DTO_INIT(CostJsonVO, JsonVO<CostListDTO::Wrapper>);
};

class CostPageJsonVO : public JsonVO<CostListPageDTO::Wrapper> {
	DTO_INIT(CostPageJsonVO, JsonVO<CostListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_COST_VO_