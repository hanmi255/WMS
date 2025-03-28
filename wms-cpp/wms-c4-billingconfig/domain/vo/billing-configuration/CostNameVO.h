#pragma once

#ifndef _COST_NAME_VO_
#define _COST_NAME_VO_

#include "../../GlobalInclude.h"
#include "../../dto/billing-configuration/CostNameDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CostNameJsonVO : public JsonVO<CostListDTO::Wrapper>
{
    DTO_INIT(CostNameJsonVO, JsonVO<CostListDTO::Wrapper>);
};

class CostNamePageJsonVO : public JsonVO<CostListPageDTO::Wrapper>
{
    DTO_INIT(CostNamePageJsonVO, JsonVO<CostListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_COST_NAME_VO_