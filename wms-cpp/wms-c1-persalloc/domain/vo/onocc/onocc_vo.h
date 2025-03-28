#ifndef _ONOCC_VO_
#define _ONOCC_VO_

#include "../../GlobalInclude.h"
#include "../../dto/onocc/onocc_dto.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class EsJsonVO :public JsonVO<EsAddDTO::Wrapper> {
	DTO_INIT(EsJsonVO, JsonVO<EsAddDTO::Wrapper>)
};

class EsPageJsonVO : public JsonVO<EsPageDTO::Wrapper>
{
	DTO_INIT(EsPageJsonVO, JsonVO<EsPageDTO::Wrapper>);
};
#endif