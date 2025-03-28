#pragma once

#ifndef _SEX_VO_
#define _SEX_VO_

#include "../../GlobalInclude.h"
#include "../../dto/sample/SampleDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 性别显示JsonVO，用于响应给客户端的Json对象
 */
class SexJsonVO : public JsonVO<SampleDTO::Wrapper> {
	DTO_INIT(SexJsonVO, JsonVO<SampleDTO::Wrapper>);
};

/**
 * 性别分页显示JsonVO，用于响应给客户端的Json对象
 */
class SexPageJsonVO : public JsonVO<SamplePageDTO::Wrapper> {
	DTO_INIT(SexPageJsonVO, JsonVO<SamplePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_