#pragma once
#ifndef _CDMINFO_VO_
#define _CDMINFO_VO_

#include "../../GlobalInclude.h"
#include "../../dto/CDMattr/CDMDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
















class CdmVO : public JsonVO<CdmDTO::Wrapper> {
	DTO_INIT(CdmVO, JsonVO<CdmDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ENTERPRISE_VO_