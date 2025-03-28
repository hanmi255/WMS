#pragma once
#ifndef _CostSum_VO_
#define _CostSum_VO_

#include "../../GlobalInclude.h"
#include "../../dto/cost-sum-dto/CostSumDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class CostSumJsonVO : public JsonVO< CostSumBaseDTO::Wrapper> {
	DTO_INIT(CostSumJsonVO, JsonVO< CostSumBaseDTO::Wrapper>);
};

/**
 * 示例分页l列表JsonVO，用于响应给客户端的Json对象
 */
class CostSumPageJsonVO : public JsonVO< CostSumPageDTO::Wrapper> {
	DTO_INIT(CostSumPageJsonVO, JsonVO< CostSumPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_
