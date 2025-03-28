#pragma once
#ifndef _ADDITION_DTO_
#define _ADDITION_DTO_

#include "../../GlobalInclude.h"

//#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 下架列表数据对象
 */
class AdditionDTO : public oatpp::DTO
{
	DTO_INIT(AdditionDTO, DTO);
	// 原始单据编码
	DTO_FIELD(String, order_id)="aaa";
	DTO_FIELD_INFO(order_id) {
		info->description = ZH_WORDS_GETTER("addition-adjustment.post.order_id");
	}
	// 商品编码
	DTO_FIELD(String, goods_id)="20222";
	DTO_FIELD_INFO(goods_id) {
		info->description = ZH_WORDS_GETTER("addition-adjustment.post.goods_id");
	}
	//API_DTO_FIELD_DEFAULT(String, goods_name, ZH_WORDS_GETTER("addition-adjustment.post.goods_name"));
	//API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("addition-adjustment.post.id"));
	DTO_FIELD(String, goods_name) = "abc";
	DTO_FIELD_INFO(goods_name) {
		info->description = ZH_WORDS_GETTER("addition-adjustment.post.goods_name");
	}
	DTO_FIELD(String, id) = "2c9efaca91697e98019227cddf1d1cb1";
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("addition-adjustment.post.id");
	}

};  
class AdditionBatchDTO : public oatpp::DTO {
	DTO_INIT(AdditionBatchDTO, DTO)
		DTO_FIELD(Vector<AdditionDTO::Wrapper>, dtoList);  ///< 批量修改的数据列表
};

#include OATPP_CODEGEN_END(DTO)
#endif // 
