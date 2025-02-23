#pragma once
#ifndef _TUOPAN_VO_
#define _TUOPAN_VO_

#include "../../GlobalInclude.h"
#include "../../dto/tuopandingyi/TuopanDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 托盘分页显示JsonVO，用于响应给客户端的Json对象
 */
class TuopanPageJsonVO : public JsonVO<TuopanPageDTO::Wrapper> {
	DTO_INIT(TuopanPageJsonVO, JsonVO<TuopanPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_TUOPAN_VO_