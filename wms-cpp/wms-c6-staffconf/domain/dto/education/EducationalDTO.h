#pragma once
#ifndef EDUCATIONAL_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class EducationalDTO : public oatpp::DTO {
	DTO_INIT(EducationalDTO, DTO);

	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("education.field.id");
	}
	
	DTO_FIELD(String, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("education.field.educode");
	}
	
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("education.field.eduname");
	}

};



/**
 * 示例分页传输对象
 */
class EducationalPageDTO : public PageDTO<EducationalDTO::Wrapper>
{
	DTO_INIT(EducationalPageDTO, PageDTO<EducationalDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !EDUCATIONAL_H_
