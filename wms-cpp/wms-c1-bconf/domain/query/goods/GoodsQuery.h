/*
 Copyright Zero One Star. All rights reserved.

 @Author: BigTomato
 @Date: 2025/03/01 13:45:24
 
*/
#ifndef _GOODSQUERY_H_
#define _GOODSQUERY_H_

#include "../../GlobalInclude.h"
#include "../../../../lib-oatpp/include/domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class GoodsQuery : public PageQuery
{
	DTO_INIT(GoodsQuery, PageQuery);
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("goods.id");
	}
	DTO_FIELD(String, category_code);
	DTO_FIELD_INFO(category_code) {
		info->description = ZH_WORDS_GETTER("goods.category_code");
	}
	DTO_FIELD(String, category_name);
	DTO_FIELD_INFO(category_name) {
		info->description = ZH_WORDS_GETTER("goods.category_name");
	}
	DTO_FIELD(String, category_level);
	DTO_FIELD_INFO(category_level) {
		info->description = ZH_WORDS_GETTER("goods.category_level");
	}
	DTO_FIELD(String, pid);
	DTO_FIELD_INFO(pid) {
		info->description = ZH_WORDS_GETTER("goods.pid");
	}
	DTO_FIELD(String, top_node);
	DTO_FIELD_INFO(top_node) {
		info->description = ZH_WORDS_GETTER("goods.top_node");
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_GOODSQUERY_H_