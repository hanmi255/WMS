#pragma once
#ifndef _DOWNGOODS_QUERY_
#define _DOWNGOODS_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 下架调整查询对象，专用于导出文件
 */
class DownGoodsQuery : public PageQuery
{
	DTO_INIT(DownGoodsQuery, PageQuery);
	// 原始单据编码
	DTO_FIELD(String, order_id);
	DTO_FIELD_INFO(order_id) {
		info->description = ZH_WORDS_GETTER("goods.field.order_id");
	}
	// 商品编码
	DTO_FIELD(String, goods_id);
	DTO_FIELD_INFO(goods_id) {
		info->description = ZH_WORDS_GETTER("goods.field.goods_id");
	}
	//商品名称
	DTO_FIELD(String, goods_name);
	DTO_FIELD_INFO(goods_name) {
		info->description = ZH_WORDS_GETTER("goods.field.goods_name");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // 