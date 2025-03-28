#ifndef _BAREAINFO_VO_
#define _BAREAINFO_VO_
#include "../../GlobalInclude.h"
#include "domain/dto/districtinfo/BareaInfoDTO.h"
#include "tree/TreeNode.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class BareaNameListJsonVO : public JsonVO<oatpp::List<BareaNameDTO::Wrapper>>
{
	DTO_INIT(BareaNameListJsonVO, JsonVO<oatpp::List<BareaNameDTO::Wrapper>>);
};

class BareaInfoJsonVO : public JsonVO<BareaInfoDTO::Wrapper>
{
	DTO_INIT(BareaInfoJsonVO, JsonVO<BareaInfoDTO::Wrapper>);
};
class BareaInfoPageJsonVO : public JsonVO<BareaInfoPageDTO::Wrapper> {
	DTO_INIT(BareaInfoPageJsonVO, JsonVO<BareaInfoPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_BAREAINFO_VO_
