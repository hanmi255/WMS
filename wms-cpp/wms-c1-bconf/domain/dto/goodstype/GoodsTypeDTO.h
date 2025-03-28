#pragma once

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 产品属性新增数据传输对象
 */
class GoodsTypeAddDTO : public oatpp::DTO
{
	DTO_INIT(GoodsTypeAddDTO, DTO);
	// 名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("goods.field.name");
	}
	// 编号
	DTO_FIELD(String, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("goods.field.code");
	}
};

/**
 * 产品属性传输对象
 */
class GoodsTypeDTO : public GoodsTypeAddDTO
{
	DTO_INIT(GoodsTypeDTO, GoodsTypeAddDTO);
	// 编码
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("goods.field.id");
	}
};

#include OATPP_CODEGEN_END(DTO)