#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei

 @Date: 2025/2/22 14:33

*/
#ifndef _GOODS_DIFF_POST_QUERY_
#define _GOODS_DIFF_POST_QUERY_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 盘点企业等级分页查询对象
 */
class GoodsDiffPostQuery : public PageQuery
{
	DTO_INIT(GoodsDiffPostQuery, PageQuery);

	// 储位
	API_DTO_FIELD_DEFAULT(String, bin_id, ZH_WORDS_GETTER("goods.field.bin_id"));

	// 托盘
	API_DTO_FIELD_DEFAULT(String, tin_id, ZH_WORDS_GETTER("goods.field.tin_id"));

	// 商品编码
	API_DTO_FIELD_DEFAULT(String, goods_id, ZH_WORDS_GETTER("goods.field.goods_id"));

	// 商品名称
	API_DTO_FIELD_DEFAULT(String, goods_name, ZH_WORDS_GETTER("goods.field.goods_name"));

	// 生产日期
	API_DTO_FIELD_DEFAULT(String, goods_pro_data, ZH_WORDS_GETTER("goods.field.goods_pro_data"));

	// 批次
	API_DTO_FIELD_DEFAULT(String, goods_batch, ZH_WORDS_GETTER("goods.field.goods_batch"));

	// 货主名称--客户名称？
	API_DTO_FIELD_DEFAULT(String, cus_name, ZH_WORDS_GETTER("goods.field.cus_name"));

	// 货主--客户？
	API_DTO_FIELD_DEFAULT(String, cus, ZH_WORDS_GETTER("goods.field.cus"));

	// 盘点状态
	API_DTO_FIELD_DEFAULT(String, stt_sta, ZH_WORDS_GETTER("goods.field.stt_sta"));

	//创建日期--起始
	API_DTO_FIELD_DEFAULT(String, create_date_start, ZH_WORDS_GETTER("goods.field.create_date_start"));

	//创建日期--终止
	API_DTO_FIELD_DEFAULT(String, create_date_end, ZH_WORDS_GETTER("goods.field.create_date_end"));
};


/**
 * 导出盘点企业等级数据---有查询条件
 */
class ExportGoodsDiffPostQuery : public GoodsDiffPostQuery
{
	DTO_INIT(ExportGoodsDiffPostQuery, GoodsDiffPostQuery);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GOODS_DIFF_POST_QUERY_