#pragma once

#ifndef _COMDEG_VO_
#define _COMDEG_VO_

#include "../../GlobalInclude.h"
#include "../../dto/comdeg/ComdegDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 公司等级显示JsonVO，用于响应给客户端的Json对象
 */
class ComdegJsonVO : public JsonVO<ComdegDetailDTO::Wrapper> {
	DTO_INIT(ComdegJsonVO, JsonVO<ComdegDetailDTO::Wrapper>);
};

/**
 * 公司等级分页显示JsonVO，用于响应给客户端的Json对象
 */
class ComdegPageJsonVO : public JsonVO<ComdegPageDTO::Wrapper> {
	DTO_INIT(ComdegPageJsonVO, JsonVO<ComdegPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_COMDEG_VO_