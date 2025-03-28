#pragma once
#ifndef _METHOD_VO_
#define _METHOD_VO_

#include "../../GlobalInclude.h"
#include "../../dto/costmethod/MethodDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class MethodJsonVO : public JsonVO<MethodDTO::Wrapper> {
	DTO_INIT(MethodJsonVO, JsonVO<MethodDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class MethodPageJsonVO : public JsonVO<MethodPageDTO::Wrapper> {
	DTO_INIT(MethodPageJsonVO, JsonVO<MethodPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // _METHOD_VO_