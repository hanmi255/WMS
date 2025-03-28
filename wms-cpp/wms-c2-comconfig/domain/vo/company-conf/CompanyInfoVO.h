#pragma once
#ifndef _COMPANY_VO_
#define _COMPANY_VO_

#include "../../GlobalInclude.h"
#include "../../dto/company-conf/CompanyInfoDTO.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 公司详细信息显示JsonVO，用于响应给客户端的Json对象
 */
class CompanyInfoVOJsonVO : public JsonVO<CompanyBaseeDTO::Wrapper> {
	DTO_INIT(CompanyInfoVOJsonVO, JsonVO<CompanyBaseeDTO::Wrapper>);
};

/**
 * 公司信息分页显示JsonVO，用于响应给客户端的Json对象
 */
class CompanyPageJsonVO : public JsonVO<CompanyListPageDTO::Wrapper> {
	DTO_INIT(CompanyPageJsonVO, JsonVO<CompanyListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_COMPANY_VO_