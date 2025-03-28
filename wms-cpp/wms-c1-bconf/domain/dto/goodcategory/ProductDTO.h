#pragma once
#ifndef _PRPODUCTDTO_
#define _PRPODUCTDTO_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 商品列表
 */

class ProductListDTO : public oatpp::DTO
{
	DTO_INIT(ProductListDTO, DTO);
	// 商品名称
	API_DTO_FIELD_DEFAULT(String, categoryname, ZH_WORDS_GETTER("product.field.categoryname"));
	// 商品编码
	API_DTO_FIELD_DEFAULT(String, categorynum, ZH_WORDS_GETTER("product.field.categorynum"));
	// 创建时间
	API_DTO_FIELD_DEFAULT(String, createtime, ZH_WORDS_GETTER("product.field.createtime"));
	// 商品级别
	API_DTO_FIELD_DEFAULT(UInt64, categorylevel, ZH_WORDS_GETTER("product.field.categorylevel"));
	// 父级目录
	API_DTO_FIELD_DEFAULT(UInt64, pid, ZH_WORDS_GETTER("product.field.pid"));
	// 顶级目录
	API_DTO_FIELD_DEFAULT(String, topnode, ZH_WORDS_GETTER("product.field.top"));
	
	
};


class ProductAddDTO : public oatpp::DTO
{
	DTO_INIT(ProductAddDTO, DTO);
	// 商品类目名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("product.field.categoryname");
	}
	// 编码
	DTO_FIELD(String, categorynum);
	DTO_FIELD_INFO(categorynum) {
		info->description = ZH_WORDS_GETTER("product.field.categorynum");
	}
	// 商品级别
	DTO_FIELD(UInt64, categorylevel);
	DTO_FIELD_INFO(categorylevel) {
		info->description = ZH_WORDS_GETTER("product.field.categorylevel");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PRPODUCTDTO_