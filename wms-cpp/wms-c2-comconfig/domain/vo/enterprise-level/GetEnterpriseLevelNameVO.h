#pragma once
#ifndef _GETENTERPRISELEVELNAME_VO_
#define _GETENTERPRISELEVELNAME_VO_

#include "../../GlobalInclude.h"
#include "../../dto/enterprise-level/GetEnterpriseLevelNameDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 用于响应给客户端的Json对象
 */
class EnterpriseLevelNameJseonVO : public JsonVO<EnterpriseLevelNameDTO::Wrapper> {
	DTO_INIT(EnterpriseLevelNameJseonVO, JsonVO<EnterpriseLevelNameDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)

#endif // !_GETENTERPRISELEVELNAME_VO_