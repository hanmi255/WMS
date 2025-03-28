#pragma once
#ifndef _METHODDTO_H_
#define _METHODDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个修改用户信息的数据传输模型
 */
class MethodAddDTO : public oatpp::DTO
{
	DTO_INIT(MethodAddDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, pronut_code, ZH_WORDS_GETTER("pronut_code"));
	API_DTO_FIELD_DEFAULT(String, pronut_name, ZH_WORDS_GETTER("pronut_name"));
};

class MethodDTO : public MethodAddDTO
{
	DTO_INIT(MethodDTO, MethodAddDTO);
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("id");
	}
};
/**
 * 定义一个用户信息分页传输对象
 */
class MethodPageDTO : public PageDTO<MethodDTO::Wrapper>
{
	DTO_INIT(MethodPageDTO, PageDTO<MethodDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // _METHODDTO_H_