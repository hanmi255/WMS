#pragma once
#ifndef _HUOQUKEZHUANYILIEBIAOVO_
#define _HUOQUKEZHUANYILIEBIAOVO_

#include "../../GlobalInclude.h"
#include "../../dto/shengchengtuopanzhuanyi/HuoQuKeZhuanYiLieBiaoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 可转移列表JsonVO，用于响应给客户端的Json对象
 */
class HuoQuKeZhuanYiLieBiaoJsonVO : public JsonVO<HuoQuKeZhuanYiLieBiaoDTO::Wrapper> {
	DTO_INIT(HuoQuKeZhuanYiLieBiaoJsonVO, JsonVO<HuoQuKeZhuanYiLieBiaoDTO::Wrapper>);
};

/**
 * 可转移列表分页显示JsonVO，用于响应给客户端的Json对象
 */
class HuoQuKeZhuanYiLieBiaoPageJsonVO : public JsonVO<HuoQuKeZhuanYiLieBiaoListPageDTO::Wrapper> {
	DTO_INIT(HuoQuKeZhuanYiLieBiaoPageJsonVO, JsonVO<HuoQuKeZhuanYiLieBiaoListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_HUOQUKEZHUANYILIEBIAOVO_