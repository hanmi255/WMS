/*
/*@File Name         : OperStepVO.h                                                     
/*@Author            : 智商局局长
/*@Description       :
*/

#ifndef _OPERSTEP_VO_
#define _OPERSTEP_VO_

#include "../../GlobalInclude.h"
#include "../../dto/oper_step/OperStepDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

///
class OperStepJsonVO : public JsonVO<OperStepDTO::Wrapper> {
	DTO_INIT(OperStepJsonVO, JsonVO<OperStepDTO::Wrapper>);
};

class OperStepModifyJsonVO : JsonVO<OperStepModifyDTO::Wrapper> {
	DTO_INIT(OperStepModifyJsonVO, JsonVO<OperStepModifyDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 