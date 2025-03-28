#ifndef _DAREAINFO_DTO_
#define _DAREAINFO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DareaInfoDTO : public oatpp::DTO
{
	DTO_INIT(DareaInfoDTO, DTO);

	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("DareaInfo.id");
	}
	DTO_FIELD(String, area_code);
	DTO_FIELD_INFO(area_code) {
		info->description = ZH_WORDS_GETTER("DareaInfo.area_code");
	}
	DTO_FIELD(String, area_name);
	DTO_FIELD_INFO(area_name) {
		info->description = ZH_WORDS_GETTER("DareaInfo.area_name");
	}
};

class DareaInfoAddDTO : public oatpp::DTO
{
	DTO_INIT(DareaInfoAddDTO, DTO);

	DTO_FIELD(String, area_code);
	DTO_FIELD_INFO(area_code) {
		info->description = ZH_WORDS_GETTER("DareaInfo.area_code");
	}
	DTO_FIELD(String, area_name);
	DTO_FIELD_INFO(area_name) {
		info->description = ZH_WORDS_GETTER("DareaInfo.area_name");
	}
};

class DareaInfoPageDTO : public PageDTO<DareaInfoDTO::Wrapper>
{
	DTO_INIT(DareaInfoPageDTO, PageDTO<DareaInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif