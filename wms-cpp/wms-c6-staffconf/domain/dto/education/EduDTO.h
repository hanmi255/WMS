#pragma once

#ifndef _EDU_DTO_
#define _EDU_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 学历新增数据传输对象
 */
class EduAddDTO : public oatpp::DTO
{
	DTO_INIT(EduAddDTO, DTO);
	// 学历代码
	DTO_FIELD(String, educode);
	DTO_FIELD_INFO(educode) {
		info->description = ZH_WORDS_GETTER("education.filed.educode");
	}
	// 学历名称
	DTO_FIELD(String, eduname);
	DTO_FIELD_INFO(eduname) {
		info->description = ZH_WORDS_GETTER("education.filed.eduname");
	}
};

/**
 *  学历传输对象
 */
class EduDTO : public EduAddDTO
{
	DTO_INIT(EduDTO, EduAddDTO);
	// id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = "id";
	}
	// 学历代码
	DTO_FIELD(String, educode);
	DTO_FIELD_INFO(educode) {
		info->description = ZH_WORDS_GETTER("education.filed.educode");
	}
	// 学历名称
	DTO_FIELD(String, eduname);
	DTO_FIELD_INFO(eduname) {
		info->description = ZH_WORDS_GETTER("education.filed.eduname");
	}
};

/**
 * 学历分页传输对象
 */
class EduPageDTO : public PageDTO<EduDTO::Wrapper>
{
	DTO_INIT(EduPageDTO, PageDTO<EduDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EDU_DTO_