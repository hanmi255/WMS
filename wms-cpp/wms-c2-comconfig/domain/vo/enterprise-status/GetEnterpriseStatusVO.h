#pragma once
#ifndef _GETENTERPRISESTATUS_VO_
#define _GETENTERPRISESTATUS_VO_

#include "../../GlobalInclude.h"
#include "../../dto/enterprise-status/GetEnterpriseStatusDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 用于响应给客户端的Json对象
 */
class EnterpriseStatusJseonVO : public JsonVO<EnterpriseStatusDTO::Wrapper> {
	DTO_INIT(EnterpriseStatusJseonVO, JsonVO<EnterpriseStatusJseonVO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)

#endif // !_GETENTERPRISESTATUS_VO_