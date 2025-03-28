#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: BigTomato
 @Date: 2025/02/19 11:06:41

*/
#ifndef _GOODSVO_H_
#define _GOODSVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/goods/GoodsDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class GoodsJsonVO : public JsonVO<GoodsDTO::Wrapper> {
	DTO_INIT(GoodsJsonVO, JsonVO<GoodsDTO::Wrapper>);
};

class CombineGoodsJsonVO : public JsonVO<CombineGoodsDTO::Wrapper> {
	DTO_INIT(CombineGoodsJsonVO, JsonVO<CombineGoodsDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_GOODSVO_H_