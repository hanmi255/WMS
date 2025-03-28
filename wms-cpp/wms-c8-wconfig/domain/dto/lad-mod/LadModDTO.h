#pragma once

#ifndef _LADMOD_DTO_
#define _LADMOD_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 提货方式新增数据传输对象，只包含基本数据
 * 因为添加新数据时只需要基本数据不需要id
 */
class LadModAddDTO : public oatpp::DTO
{
	DTO_INIT(LadModAddDTO, oatpp::DTO);
	// 提货方式代码
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("lad.field.code"));

	// 提货方式代码
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("lad.field.name"));
};
/**
 * 提货方式传输对象,在新增数据传输对象的基础上添加唯一id
 * 修改数据需要id
 */
class LadModDTO : public LadModAddDTO
{
	DTO_INIT(LadModDTO, LadModAddDTO);
	// 唯一ID
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("lad.field.id"));
};

/**
 * 提货方式分页传输对象
 */
class LadModPageDTO : public PageDTO<LadModDTO::Wrapper>
{
	DTO_INIT(LadModPageDTO, PageDTO<LadModDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_LADMOD_DTO_