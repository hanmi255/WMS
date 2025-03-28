
#ifndef _ONOCC_DTO_
#define _ONOCC_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class EsAddDTO :public oatpp::DTO 
{
	DTO_INIT(EsAddDTO, DTO);

	API_DTO_FIELD_DEFAULT(String, pos_sta_code, ZH_WORDS_GETTER("es.field.pos_sta_code"));
	API_DTO_FIELD_DEFAULT(String, pos_sta_name, ZH_WORDS_GETTER("es.field.pos_sta_name"));
};

class EsDTO :public EsAddDTO
{
	DTO_INIT(EsDTO,EsAddDTO);
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("es.field.id"));
};

class EsPageDTO :public PageDTO<EsDTO::Wrapper>
{
	DTO_INIT(EsPageDTO, PageDTO<EsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)














#endif
