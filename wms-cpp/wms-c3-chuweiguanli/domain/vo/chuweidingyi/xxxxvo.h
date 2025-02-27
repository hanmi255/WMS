#pragma once



#ifndef _XIANGXIXINXIXIANSHI_
#define _XIANGXIXINXIXIANSHI_

#include "../../GlobalInclude.h"
#include "../../dto/chuweidingyi/xxxxdto.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 储位定义详情JsonVO，用于响应给客户端的Json对象
 */
class xiangxixinxiJsonVO : public JsonVO<xiangxixinxi::Wrapper> {
	DTO_INIT(xiangxixinxiJsonVO, JsonVO<xiangxixinxi::Wrapper>);
};

/**
 * 导出表JsonVO，用于响应给客户端的Json对象
 */
class daochuJsonVO : public JsonVO<daochudto::Wrapper> {
	DTO_INIT(daochuJsonVO, JsonVO<daochudto::Wrapper>);
};


/**
 * 导入表JsonVO，用于响应给客户端的Json对象
 */
class daoruJsonVO : public JsonVO<daorudto::Wrapper> {
	DTO_INIT(daoruJsonVO, JsonVO<daorudto::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_XIANGXIXINXIXIANSHI_