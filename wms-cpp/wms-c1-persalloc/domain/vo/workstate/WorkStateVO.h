#pragma once
// Õı“≤ 2025/2/24
#ifndef _WORKSTATE_VO_
#define _WORKSTATE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/workstate/WorkStateDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class WorkStateJsonVO : public JsonVO<WorkStateDTO::Wrapper> {
	DTO_INIT(WorkStateJsonVO, JsonVO<WorkStateDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_WORKSTATE_VO_