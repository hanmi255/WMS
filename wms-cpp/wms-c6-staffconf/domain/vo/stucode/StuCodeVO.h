#pragma once
#ifndef _StuCode_VO_
#define _StuCode_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/stucode/StuCodeDTO.h"
//#include "JsonVO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class StuCodeJsonVO : public JsonVO<StuCodeDTO::Wrapper> {
	DTO_INIT(StuCodeJsonVO, JsonVO<StuCodeDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class StuCodePageJsonVO : public JsonVO<StuCodePageDTO::Wrapper> {
	DTO_INIT(StuCodePageJsonVO, JsonVO<StuCodePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_StuCode_VO_