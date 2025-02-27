#pragma once



#ifndef _XIANGXIXINXIXIANSHI_
#define _XIANGXIXINXIXIANSHI_

#include "../../GlobalInclude.h"
#include "../../dto/chuweidingyi/xxxxdto.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��λ��������JsonVO��������Ӧ���ͻ��˵�Json����
 */
class xiangxixinxiJsonVO : public JsonVO<xiangxixinxi::Wrapper> {
	DTO_INIT(xiangxixinxiJsonVO, JsonVO<xiangxixinxi::Wrapper>);
};

/**
 * ������JsonVO��������Ӧ���ͻ��˵�Json����
 */
class daochuJsonVO : public JsonVO<daochudto::Wrapper> {
	DTO_INIT(daochuJsonVO, JsonVO<daochudto::Wrapper>);
};


/**
 * �����JsonVO��������Ӧ���ͻ��˵�Json����
 */
class daoruJsonVO : public JsonVO<daorudto::Wrapper> {
	DTO_INIT(daoruJsonVO, JsonVO<daorudto::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_XIANGXIXINXIXIANSHI_