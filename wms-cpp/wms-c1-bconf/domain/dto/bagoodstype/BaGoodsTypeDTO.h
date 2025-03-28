#ifndef _BAGOODSTYPE_DTO_
#define _BAGOODSTYPE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 产品属性对象
 */
class BaGoodsTypeDTO : public oatpp::DTO
{
	DTO_INIT(BaGoodsTypeDTO, DTO);
	//id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("ba_good_type.field.id");
	}
	//产品属性编码
	DTO_FIELD(String, goods_type_code);
	DTO_FIELD_INFO(goods_type_code) {
		info->description = ZH_WORDS_GETTER("ba_good_type.field.goods_type_code");
	}
	//产品属性名称
	DTO_FIELD(String, goods_type_name);
	DTO_FIELD_INFO(goods_type_name) {
		info->description = ZH_WORDS_GETTER("ba_good_type.field.goods_type_name");
	}
	
};

/**
 * 产品属性分页传输对象
 */
class BaGoodsTypePageDTO : public PageDTO<BaGoodsTypeDTO::Wrapper>
{
	DTO_INIT(BaGoodsTypePageDTO, PageDTO<BaGoodsTypeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 