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
	// 创建人名称
	DTO_FIELD(String, create_name);
	DTO_FIELD_INFO(create_name) {
		info->description = ZH_WORDS_GETTER("ba_good_type.field.create_name");
	}
	//创建人登录名
	DTO_FIELD(String, create_by);
	DTO_FIELD_INFO(create_by) {
		info->description = ZH_WORDS_GETTER("ba_good_type.field.create_by");
	}
	// 创建日期
	DTO_FIELD(String, create_date);
	DTO_FIELD_INFO(create_date) {
		info->description = ZH_WORDS_GETTER("ba_good_type.field.create_date");
	}
	// 所属部门
	DTO_FIELD(String, sys_org_code);
	DTO_FIELD_INFO(sys_org_code) {
		info->description = ZH_WORDS_GETTER("ba_good_type.field.sys_org_code");
	}
	// 所属公司
	DTO_FIELD(String, sys_company_code);
	DTO_FIELD_INFO(sys_company_code) {
		info->description = ZH_WORDS_GETTER("ba_good_type.field.sys_company_code");
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
	//id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("ba_good_type.field.id");
	}
	//更新人名称
	DTO_FIELD(String, update_name);
	DTO_FIELD_INFO(update_name) {
		info->description = ZH_WORDS_GETTER("ba_good_type.field.update_name");
	}
	//更新人登录名称
	DTO_FIELD(String, update_by);
	DTO_FIELD_INFO(update_by) {
		info->description = ZH_WORDS_GETTER("ba_good_type.field.update_by");
	}
	//更新日期
	DTO_FIELD(String, update_date);
	DTO_FIELD_INFO(update_date) {
		info->description = ZH_WORDS_GETTER("ba_good_type.field.update_date");
	}

};

class BaGoodsTypeNameDTO : public oatpp::DTO
{
	DTO_INIT(BaGoodsTypeNameDTO, DTO);

	//产品属性名称
	DTO_FIELD(String, goods_type_name);
	DTO_FIELD_INFO(goods_type_name) {
		info->description = ZH_WORDS_GETTER("ba_good_type.field.goods_type_name");
	}

};

/**
 * 产品属性名称分页传输对象
 */
class BaGoodsTypeNamePageDTO : public PageDTO<BaGoodsTypeNameDTO::Wrapper>
{
	DTO_INIT(BaGoodsTypeNamePageDTO, PageDTO<BaGoodsTypeNameDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 