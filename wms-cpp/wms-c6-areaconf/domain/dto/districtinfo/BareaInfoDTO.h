#ifndef _BAREAINFO_DTO_
#define _BAREAINFO_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class BareaNameDTO : public oatpp::DTO
{
	DTO_INIT(BareaNameDTO, DTO);

	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("region.field.id"));
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("region.field.name"));
};

class BareaInfoDTO : public oatpp::DTO
{
	DTO_INIT(BareaInfoDTO, DTO);

	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("region.field.id"));
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("region.field.name"));
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("region.field.code"));
	API_DTO_FIELD_DEFAULT(Float64, rdata, ZH_WORDS_GETTER("region.field.rdate"));
};

class BareaInfoPageDTO : public PageDTO<BareaInfoDTO::Wrapper>
{
	DTO_INIT(BareaInfoPageDTO, PageDTO<BareaInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 