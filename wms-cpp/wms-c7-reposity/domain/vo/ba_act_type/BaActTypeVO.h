#pragma once

#ifndef _BAACTTYPE_VO_
#define _BAACTTYPE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/ba_act_type/BaActTypeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 客户详情JsonVO，用于响应给客户端的Json对象
 */
class BaActTypeJsonVO : public JsonVO<BaActTypeDTO::Wrapper> {
	DTO_INIT(BaActTypeJsonVO, JsonVO<BaActTypeDTO::Wrapper>);
};

/**
 * 客户分页列表JsonVO，用于响应给客户端的Json对象
 */
class BaActTypePageJsonVO : public JsonVO<BaActTypeListPageDTO::Wrapper> {
	DTO_INIT(BaActTypePageJsonVO, JsonVO<BaActTypeListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_BAACTTYPE_VO_