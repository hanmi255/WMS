#pragma once


#ifndef _XIANGXIXINXIXIANSHIVO_
#define _XIANGXIXINXIXIANSHIVO_

#include "../../GlobalInclude.h"
#include "../../dto/chuweidingyi/xiangxixinxiDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 储位定义详情JsonVO，用于响应给客户端的Json对象
 */
class xiangxixinxiJsonVO : public JsonVO<xiangxixinxiDTO::Wrapper> {
	DTO_INIT(xiangxixinxiJsonVO, JsonVO<xiangxixinxiDTO::Wrapper>);
};

/**
 * 导出表JsonVO，用于响应给客户端的Json对象
 */
//class daochuJsonVO : public JsonVO<daochudto::Wrapper> {
//	DTO_INIT(daochuJsonVO, JsonVO<daochudto::Wrapper>);
//};


#include OATPP_CODEGEN_END(DTO)

#endif // !_XIANGXIXINXIXIANSHIVO_