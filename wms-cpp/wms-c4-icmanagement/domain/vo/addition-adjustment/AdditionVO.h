#ifndef _ADDITION_VO_
#define _ADDITION_VO_

#include "../../GlobalInclude.h"
#include "../../dto/addition-adjustment/AdditionDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class AdditionJsonVO : public JsonVO<AdditionDTO::Wrapper> {
	DTO_INIT(AdditionJsonVO, JsonVO<AdditionDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // 
