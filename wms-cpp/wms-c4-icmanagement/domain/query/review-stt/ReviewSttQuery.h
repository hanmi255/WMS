#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei

 @Date: 2025/3/10 14:33

*/
#ifndef _REVIEW_STT_QUERY_
#define _REVIEW_STT_QUERY_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 复盘分页查询对象
 */
class ReviewSttQuery : public PageQuery
{
	DTO_INIT(ReviewSttQuery, PageQuery);

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
};


/**
 * 导出复盘数据---有查询条件
 */
class ExportReviewSttQuery : public ReviewSttQuery
{
	DTO_INIT(ExportReviewSttQuery, ReviewSttQuery);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_REVIEW_STT_QUERY_