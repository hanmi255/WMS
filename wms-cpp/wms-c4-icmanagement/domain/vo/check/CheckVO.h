#pragma once

#ifndef _CHECK_VO_
#define _CHECK_VO_

#include "../../GlobalInclude.h"
#include "../../dto/check/CheckDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 盘点人详情JsonVO，用于响应给客户端的Json对象
 */
class CheckJsonVO : public JsonVO<CheckDtailDTO::Wrapper> {
	DTO_INIT(CheckJsonVO, JsonVO<CheckDtailDTO::Wrapper>);
};

/**
 * 盘点人详情列表JsonVO，用于响应给客户端的Json对象
 */
class CheckPageJsonVO : public JsonVO<CheckPageDTO::Wrapper> {
	DTO_INIT(CheckPageJsonVO, JsonVO<CheckPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CHECK_VO_#pragma once
