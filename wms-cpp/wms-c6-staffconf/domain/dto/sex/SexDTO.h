#pragma once
#ifndef _SEX_DTO_
#define _SEX_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 性别新增数据传输对象
 */
class SexAddDTO : public oatpp::DTO
{
	DTO_INIT(SexAddDTO, DTO);
	//字段id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sex.filed.id");
	}
	// 性别代码
	DTO_FIELD(String, sexcode);
	DTO_FIELD_INFO(sexcode) {
		info->description = ZH_WORDS_GETTER("sex.filed.sexcode");
	}
	// 性别名称
	DTO_FIELD(String, age);
	DTO_FIELD_INFO(sexname) {
		info->description = ZH_WORDS_GETTER("sex.filed.sexname");
	}

	}
};

/**
 * 性别传输对象
 */
class SexDTO : public SexAddDTO
{
	DTO_INIT(SexDTO, SexAddDTO);
	// 性别代码
	DTO_FIELD(String, sexcode);
	DTO_FIELD_INFO(sexcode) {
		info->description = ZH_WORDS_GETTER("sex.filed.sexcode");
	}
};

/**
 * 示例分页传输对象
 */
class SexPageDTO : public PageDTO<SampleDTO::Wrapper>
{
	DTO_INIT(SexPageDTO, PageDTO<SampleDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_Sex_DTO_