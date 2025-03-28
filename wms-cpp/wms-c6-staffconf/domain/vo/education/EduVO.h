#pragma once

#ifndef _EDU_VO_
#define _EDU_VO_

#include "../../GlobalInclude.h"
#include "../../dto/education/EduDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 学历显示JsonVO，用于响应给客户端的Json对象
 */
class EduJsonVO : public JsonVO<EduDTO::Wrapper> {
	DTO_INIT(EduJsonVO, JsonVO<EduDTO::Wrapper>);
};

/**
 * 学历分页显示JsonVO，用于响应给客户端的Json对象
 */
class EduPageJsonVO : public JsonVO<EduPageDTO::Wrapper> {
	DTO_INIT(EduPageJsonVO, JsonVO<EduPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_Edu_VO_