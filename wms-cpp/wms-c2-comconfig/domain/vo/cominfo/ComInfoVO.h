#pragma once
#ifndef _COMPANY_INFORMATION_VO_
#define _COMPANY_INFORMATION_VO_

#include "../../GlobalInclude.h"
#include "../../dto/cominfo/ComInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 公司信息显示JsonVO，用于响应给客户端的Json对象
 */
class ComInfoJsonVO : public JsonVO<ComInfoDTO::Wrapper> {
	DTO_INIT(ComInfoJsonVO, JsonVO<ComInfoDTO::Wrapper>);
};

/**
 * 公司信息分页显示JsonVO，用于响应给客户端的Json对象
 */
class ComInfoPageJsonVO : public JsonVO<ComInfoPageDTO::Wrapper> {
	DTO_INIT(ComInfoPageJsonVO, JsonVO<ComInfoPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_COMPANY_INFORMATION_VO_

