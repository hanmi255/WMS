#pragma once
#ifndef _ENTERPRISE_VO_
#define _ENTERPRISE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/companyattr/CompanyDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 企业分页列表JsonVO，用于响应给客户端的Json对象
 */
class CompanyPageJsonVO : public JsonVO<CompanyListPageDTO::Wrapper> {
	DTO_INIT(CompanyPageJsonVO, JsonVO<CompanyListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ENTERPRISE_VO_