#pragma once

#ifndef _COST_VO_
#define _COST_VO_

#include "../../GlobalInclude.h"
#include "../../dto/cost-detail-ahead/CostDetialDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 费用明细详情JsonVO，用于响应给客户端的Json对象
 */
class CostDetailJsonVO : public JsonVO<CostDetailBaseDTO::Wrapper> {
	DTO_INIT(CostDetailJsonVO, JsonVO<CostDetailBaseDTO::Wrapper>);
};

/**
 * 费用明细分页列表JsonVO，用于响应给客户端的Json对象
 */
class CostDetailListPageJsonVO : public JsonVO<CostDetailListPageDTO::Wrapper> {
	DTO_INIT(CostDetailListPageJsonVO, JsonVO<CostDetailListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_COST_VO_