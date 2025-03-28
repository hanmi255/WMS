#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: BigTomato
 @Date: 2025/02/20 15:27:26

*/
#ifndef _GOODSDTO_H_
#define _GOODSDTO_H_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class GoodsDTO : public oatpp::DTO
{
	DTO_INIT(GoodsDTO, DTO);
	// ID
	API_DTO_FIELD_DEFAULT(Int64, id, ZH_WORDS_GETTER("goods.id"));
	// 类目编码
	API_DTO_FIELD_DEFAULT(String, category_code, ZH_WORDS_GETTER("goods.category_code"));
	// 类目名称
	API_DTO_FIELD_DEFAULT(String, category_name, ZH_WORDS_GETTER("goods.category_name"));
	// 类目级别
	API_DTO_FIELD_DEFAULT(Int64, category_level, ZH_WORDS_GETTER("goods.category_level"));
	// 父id
	API_DTO_FIELD_DEFAULT(Int64, pid, ZH_WORDS_GETTER("goods.pid"));
	// 顶级节点
	API_DTO_FIELD_DEFAULT(String, top_node, ZH_WORDS_GETTER("goods.top_node"));

};
class CombineGoodsDTO : public GoodsDTO {
	DTO_INIT(CombineGoodsDTO, DTO);
	API_DTO_FIELD_DEFAULT(List<GoodsDTO::Wrapper>, DTOList, ZH_WORDS_GETTER("goods.DTOList"));
	API_DTO_FIELD_DEFAULT(Int64, total, ZH_WORDS_GETTER("goods.total"));
public:
	CombineGoodsDTO() {
		this->DTOList = List<GoodsDTO::Wrapper>::createShared();
		this->total = Int64(static_cast<int64_t>(0));
	}

	void addData(GoodsDTO::Wrapper dto) {
		DTOList->push_back(dto);
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_GOODSDTO_H_