#ifndef _BAGOODSTYPE_QUERY_
#define _BAGOODSTYPE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 分页查询产品属性
 */
class BaGoodsTypeQuery : public PageQuery
{
	DTO_INIT(BaGoodsTypeQuery, PageQuery);
	// id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("ba_goods_type.field.id");
	}
	// 创建人名称
	DTO_FIELD(String, create_name);
	DTO_FIELD_INFO(create_name) {
		info->description = ZH_WORDS_GETTER("ba_goods_type.create_name");
	}
	// 更新人名称
	DTO_FIELD(String, update_name);
	DTO_FIELD_INFO(update_name) {
		info->description = ZH_WORDS_GETTER("ba_goods_type.field.age");
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

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_