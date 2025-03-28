#pragma once
#ifndef _EXPORT_VO_H_
#define _EXPORT_VO_H_

#include "../../GlobalInclude.h"
#include "../../dto/export-industry-class/ExportDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 行业分类显示JsonVO，用于响应给客户端的Json对象
 */
class ExportJsonVO : public JsonVO<ExportDTO::Wrapper> {
	DTO_INIT(ExportJsonVO, JsonVO<ExportDTO::Wrapper>);
};

/**
 * 行业分类分页显示JsonVO，用于响应给客户端的Json对象
 */
class ExportPageJsonVO : public JsonVO<ExportPageDTO::Wrapper> {
	DTO_INIT(ExportPageJsonVO, JsonVO<ExportPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_EXPORT_VO_H_