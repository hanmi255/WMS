#pragma once

#ifndef BUSINESS_LINK_JsonVO
#define BUSINESS_LINK_JsonVO

#include "../../GlobalInclude.h"
#include "../../dto/business-link/BusinessLinkDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class BusinessLinkPageJsonVO : public JsonVO<BusinessLinkPageDTO::Wrapper> {
	DTO_INIT(BusinessLinkPageJsonVO, JsonVO<BusinessLinkPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif