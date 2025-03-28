#pragma once
#ifndef _PRODUCT_VO_
#define _PRODUCT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/goodcategory/ProductDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 商品显示JsonVO，用于响应给客户端的Json对象
 */
class ProductJsonVO : public JsonVO<ProductListDTO::Wrapper> {
	DTO_INIT(ProductJsonVO, JsonVO<ProductListDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_PRODUCT_VO_