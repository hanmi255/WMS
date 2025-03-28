#pragma once

#ifndef _UNLOADINGFEE_VO_
#define _UNLOADINGFEE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/unloading-fee/UnloadingFeeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 外包卸货费显示JsonVO，用于响应给客户端的Json对象
 */
class UnloadingFeeJsonVO : public JsonVO<UnloadingFeeDTO::Wrapper> {
	DTO_INIT(UnloadingFeeJsonVO, JsonVO<UnloadingFeeDTO::Wrapper>);
};

/**
 * 外包卸货费分页显示JsonVO，用于响应给客户端的Json对象
 */
class UnloadingFeePageJsonVO : public JsonVO<UnloadingFeePageDTO::Wrapper> {
	DTO_INIT(UnloadingFeePageJsonVO, JsonVO<UnloadingFeePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // _UNLOADINGFEE_VO_