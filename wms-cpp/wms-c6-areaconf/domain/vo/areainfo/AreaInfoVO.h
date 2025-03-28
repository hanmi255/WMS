#ifndef _AREAINFO_VO_
#define _AREAINFO_VO_
#include "../../GlobalInclude.h"
#include "domain/dto/areainfo/AreaInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class AreaInfoJsonVO : public JsonVO<AreaInfoUpdDTO::Wrapper> {
	DTO_INIT(AreaInfoJsonVO, JsonVO<AreaInfoUpdDTO::Wrapper>);
};

class AreaNameTreeJsonVO : public JsonVO<List<AreaNameTreeDTO::Wrapper>>
{
	DTO_INIT(AreaNameTreeJsonVO, JsonVO<List<AreaNameTreeDTO::Wrapper>>);
public:
	// 在构造函数中实例化data列表
	AreaNameTreeJsonVO() {
		this->data = {};
	}
};

class AreaInfoListJsonVO : public JsonVO<oatpp::List<AreaInfoUpdDTO::Wrapper>>
{
	DTO_INIT(AreaInfoListJsonVO, JsonVO<oatpp::List<AreaInfoUpdDTO::Wrapper>>);
};

class AreaInfoPageJsonVO : public JsonVO<AreaInfoPageDTO::Wrapper> {
	DTO_INIT(AreaInfoPageJsonVO, JsonVO<AreaInfoPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_AREAINFO_VO_
