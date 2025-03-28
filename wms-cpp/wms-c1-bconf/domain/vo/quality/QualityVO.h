#pragma once
#ifndef _QUALITY_VO_
#define _QUALITY_VO_

#include "../../GlobalInclude.h"
#include "../../dto/quality/QualityDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 品质代码详情JsonVO，用于响应给客户端的Json对象
 */
class QualityJsonVO : public JsonVO<QualityDetailDTO::Wrapper> {
	DTO_INIT(QualityJsonVO, JsonVO<QualityDetailDTO::Wrapper>);
};

/**
 * 品质代码分页显示JsonVO，用于响应给客户端的Json对象
 */
class QualityPageJsonVO : public JsonVO<QualityPageDTO::Wrapper> {
	DTO_INIT(QualityPageJsonVO, JsonVO<QualityPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO__