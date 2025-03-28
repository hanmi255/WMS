#pragma once
#ifndef CITYTYPE_H_
#define CITYTYPE_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CityTypeNameDTO : public oatpp::DTO {
	DTO_INIT(CityTypeNameDTO, DTO);

	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("citytype.uniq_id");
	}

	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("citytype.name");
	}
};


class CityTypeDTO : public oatpp::DTO {
	DTO_INIT(CityTypeDTO, DTO);

	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("citytype.uniq_id");
	}

	DTO_FIELD(String, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("citytype.code");
	}

	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("citytype.name");
	}

};

class CitytypeBaseDTO : public oatpp::DTO
{
	DTO_INIT(CitytypeBaseDTO, DTO);
	// 名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("citytype.name");
	}
	// 代码
	DTO_FIELD(String, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("citytype.code");
	}
};


/**
 * 示例分页传输对象
 */
class CityTypePageDTO : public PageDTO<CityTypeDTO::Wrapper>
{
	DTO_INIT(CityTypePageDTO, PageDTO<CityTypeDTO::Wrapper>);
};

/**
 * 城市类型删除数据传输对象
 */
class CitytypeDeleteDTO : public CitytypeBaseDTO
{
	DTO_INIT(CitytypeDeleteDTO, CitytypeBaseDTO); // 注意这里的父类需要正确填充
	// 唯一标识
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("citytype.uniq_id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif 
