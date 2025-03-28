#ifndef _DAREAINFO_VO_
#define _DAREAINFO_VO_
#include "../../GlobalInclude.h"
#include "domain/dto/regioninfo/DareaInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DareaInfoJsonVO : public JsonVO<DareaInfoDTO::Wrapper> 
{
	DTO_INIT(DareaInfoJsonVO, JsonVO<DareaInfoDTO::Wrapper>);
};

class DareaInfoAddJsonVO : public JsonVO<DareaInfoAddDTO::Wrapper>
{
	DTO_INIT(DareaInfoAddJsonVO, JsonVO<DareaInfoAddDTO::Wrapper>);
};

class DareaInfoPageJsonVO : public JsonVO<DareaInfoPageDTO::Wrapper> 
{
	DTO_INIT(DareaInfoPageJsonVO, JsonVO<DareaInfoPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DAREAINFO_VO_
