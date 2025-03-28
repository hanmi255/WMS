#pragma once
#ifndef _STUCODE_DTO_
#define _STUCODE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class StuCodeDTO : public oatpp::DTO
{
	DTO_INIT(StuCodeDTO, DTO);

	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id)
	{
		info->description = ZH_WORDS_GETTER("sex.filed.id");
	}


	DTO_FIELD(String, code);
	DTO_FIELD_INFO(code)
	{
		info->description = ZH_WORDS_GETTER("sex.filed.sexcode");
	}

	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name)
	{
		info->description = ZH_WORDS_GETTER("sex.filed.sexname");
	}
};

class StuCodeListDTO : public oatpp::DTO
{
	DTO_INIT(StuCodeListDTO, DTO);
	DTO_FIELD(List<StuCodeDTO::Wrapper>, stucodeList);
};

/**
 * 示例分页传输对象
 */
class StuCodePageDTO : public PageDTO<StuCodeDTO::Wrapper>
{
	DTO_INIT(StuCodePageDTO, PageDTO<StuCodeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_STUCODE_DTO_