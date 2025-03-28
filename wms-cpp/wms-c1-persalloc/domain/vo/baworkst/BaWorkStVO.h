#ifndef _BAWORKST_VO_
#define _BAWORKST_VO_

#include "../../GlobalInclude.h"
#include "../../dto/baworkst/BaWorkStDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class BaWorkStJsonVO : public JsonVO<BaWorkStDTO::Wrapper> {
	DTO_INIT(BaWorkStJsonVO, JsonVO<BaWorkStDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class BaWorkStPageJsonVO : public JsonVO<BaWorkStPageDTO::Wrapper> {
	DTO_INIT(BaWorkStPageJsonVO, JsonVO<BaWorkStPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 