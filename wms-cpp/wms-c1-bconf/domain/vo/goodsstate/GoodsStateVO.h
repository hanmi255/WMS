#pragma once
#ifndef _GOODSSTATEVO_H_
#define _GOODSSTATEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/goodsstate/GoodStateDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class GoodsStateVO : public JsonVO<GoodStateDTO::Wrapper> {
	DTO_INIT(GoodsStateVO, JsonVO<GoodStateDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_GOODSSTATEVO_H_