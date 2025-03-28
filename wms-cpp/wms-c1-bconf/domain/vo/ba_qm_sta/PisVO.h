#pragma once

#ifndef _PIS_VO_
#define _PIS_VO_

#include "../../GlobalInclude.h"
#include "../../dto/ba_qm_sta/PisDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class PisJsonVO : public JsonVO<PisDTO::Wrapper> {
	DTO_INIT(PisJsonVO, JsonVO<PisDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class PisPageJsonVO : public JsonVO<PisPageDTO::Wrapper> {
	DTO_INIT(PisPageJsonVO, JsonVO<PisPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_
