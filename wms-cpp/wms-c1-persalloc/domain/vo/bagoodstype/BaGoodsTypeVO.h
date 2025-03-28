#ifndef _BAGOODSTYPE_VO_
#define _BAGOODSTYPE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/bagoodstype/BaGoodsTypeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class BaGoodsTypeJsonVO : public JsonVO<BaGoodsTypeDTO::Wrapper> {
	DTO_INIT(BaGoodsTypeJsonVO, JsonVO<BaGoodsTypeDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class BaGoodsTypeNamePageJsonVO : public JsonVO<BaGoodsTypeNamePageDTO::Wrapper> {
	DTO_INIT(BaGoodsTypeNamePageJsonVO, JsonVO<BaGoodsTypeNamePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 