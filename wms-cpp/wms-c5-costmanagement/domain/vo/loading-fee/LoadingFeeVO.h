#pragma once

#ifndef _LOADINGFEE_VO_
#define _LOADINGFEE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/loading-fee/LoadingFeeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 外包装车费列表显示JsonVO，用于响应给客户端的Json对象
 */
class LoadingFeeJsonVO : public JsonVO<LoadingFeeDTO::Wrapper> {
	DTO_INIT(LoadingFeeJsonVO, JsonVO<LoadingFeeDTO::Wrapper>);
};

/**
 * 外包装车费分页显示JsonVO，用于响应给客户端的Json对象
 */
class LoadingFeePageJsonVO : public JsonVO<LoadingFeePageDTO::Wrapper> {
	DTO_INIT(LoadingFeePageJsonVO, JsonVO<LoadingFeePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // _LOADINGFEE_VO_