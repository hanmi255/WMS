#pragma once
#ifndef _REMOVAL_QUERY_
#define _REMOVAL_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class RemovalQuery : public PageQuery
{
	DTO_INIT(RemovalQuery, PageQuery);
	// 原始单据编码
	DTO_FIELD(String, order_id);
	DTO_FIELD_INFO(order_id) {
		info->description = ZH_WORDS_GETTER("removal-adjustment.query.order_id");
	}
	// 商品编码
	DTO_FIELD(String, goods_id);
	DTO_FIELD_INFO(goods_id) {
		info->description = ZH_WORDS_GETTER("removal-adjustment.query.goods_id");
	}
	//商品名称
	DTO_FIELD(String, goods_name);
	DTO_FIELD_INFO(goods_name) {
		info->description = ZH_WORDS_GETTER("removal-adjustment.query.goods_name");
	}
	//API_DTO_FIELD_DEFAULT(String, goods_name, ZH_WORDS_GETTER("removal-adjustment.query.goods_name"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // 