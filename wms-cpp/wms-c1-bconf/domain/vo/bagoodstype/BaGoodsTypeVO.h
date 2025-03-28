#ifndef _BAGOODSTYPE_VO_
#define _BAGOODSTYPE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/bagoodstype/BaGoodsTypeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class BaGoodsTypePageJsonVO : public JsonVO<BaGoodsTypePageDTO::Wrapper> {
	DTO_INIT(BaGoodsTypePageJsonVO, JsonVO<BaGoodsTypePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 