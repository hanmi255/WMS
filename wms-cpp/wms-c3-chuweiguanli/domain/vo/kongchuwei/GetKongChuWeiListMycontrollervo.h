#pragma once
#include "../../GlobalInclude.h"
#include "../../dto/kongchuwei/GetKongChuWeiListMycontrollerDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 显示JsonVO，用于响应给客户端的Json对象
 */
class GetKongChuWeiListMycontrollerJsonVO : public JsonVO<GetKongChuWeiListMycontrollerDTO::Wrapper> {
	DTO_INIT(GetKongChuWeiListMycontrollerJsonVO, JsonVO<GetKongChuWeiListMycontrollerDTO::Wrapper>);
};

/**
 * 分页显示JsonVO，用于响应给客户端的Json对象
 */
class GetKongChuWeiListMycontrollerPageJsonVO : public JsonVO<GetKongChuWeiListMycontrollerPageDTO::Wrapper> {
	DTO_INIT(GetKongChuWeiListMycontrollerPageJsonVO, JsonVO<GetKongChuWeiListMycontrollerPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

// !_BIN_TRANSFER_VO_
