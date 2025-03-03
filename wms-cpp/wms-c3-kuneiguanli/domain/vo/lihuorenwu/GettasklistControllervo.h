#pragma once
#include "../../GlobalInclude.h"
#include "../../dto/lihuorenwu/GettasklistControllerDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 显示JsonVO，用于响应给客户端的Json对象
 */
class GettasklistControllerJsonVO : public JsonVO<GettasklistControllerDTO::Wrapper> {
	DTO_INIT(GettasklistControllerJsonVO, JsonVO<GettasklistControllerDTO::Wrapper>);
};

/**
 * 分页显示JsonVO，用于响应给客户端的Json对象
 */
class GettasklistControllerPageJsonVO : public JsonVO<GettasklistControllerPageDTO::Wrapper> {
	DTO_INIT(GettasklistControllerPageJsonVO, JsonVO<GettasklistControllerPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

// !_BIN_TRANSFER_VO_