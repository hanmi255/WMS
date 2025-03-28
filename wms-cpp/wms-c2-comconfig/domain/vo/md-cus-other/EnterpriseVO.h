#pragma once
#ifndef _ENTERPRISEVO_
#define _ENTERPRISEVO_

#include "../../GlobalInclude.h"
#include "../../dto/md-cus-other/EnterpriseDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 企业分页列表JsonVO，用于响应给客户端的Json对象
 */
class EnterprisePageJsonVO : public JsonVO<EnterpriseListPageDTO::Wrapper> {
	DTO_INIT(EnterprisePageJsonVO, JsonVO<EnterpriseListPageDTO::Wrapper>);
};


/*
企业状态的列表框
*/
class EnterpriseJsonVO : public JsonVO<EnterpriseStatusListDTO::Wrapper> {
	DTO_INIT(EnterpriseJsonVO, JsonVO<EnterpriseStatusListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ENTERPRISE_VO_