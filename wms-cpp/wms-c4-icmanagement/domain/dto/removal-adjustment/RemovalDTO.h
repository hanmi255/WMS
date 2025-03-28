#pragma once
#ifndef _REMOVAL_DTO_
#define _REMOVAL_DTO_

#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 下架列表数据对象
 */
class RemovalBaseDTO : public oatpp::DTO
{
	DTO_INIT(RemovalBaseDTO, DTO);
	// 原始单据编码
	DTO_FIELD(String, order_id)="CK20240925-0002";
	DTO_FIELD_INFO(order_id) {
		info->description = ZH_WORDS_GETTER("removal-adjustment.query.order_id");
	}
	// 商品编码
	DTO_FIELD(String, goods_id)="20222";
	DTO_FIELD_INFO(goods_id) {
		info->description = ZH_WORDS_GETTER("removal-adjustment.query.goods_id");
	}
	DTO_FIELD(String, goods_name) = "abc";
	DTO_FIELD_INFO(goods_name) {
		info->description = ZH_WORDS_GETTER("removal-adjustment.query.goods_name");
	}
};
class RemovalListDTO : public RemovalBaseDTO
{
	//API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("removal-adjustment.query.id"));
	DTO_INIT(RemovalListDTO,RemovalBaseDTO);
	//API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("removal-adjustment.query.id"));
	DTO_FIELD(String, id) = "2c9efaca91697e980192270b5efa1c66";
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("removal-adjustment.query.id");
	}
};
class RemovalDetailDTO : public RemovalListDTO
{
	DTO_INIT(RemovalDetailDTO, RemovalListDTO);
	// 原始单据编码
	DTO_FIELD(String, order_id)="CK20240925-0002";
	DTO_FIELD_INFO(order_id) {
		info->description = ZH_WORDS_GETTER("removal-adjustment.query.order_id");
	}
	// 商品编码
	DTO_FIELD(String, goods_id)="20222";
	DTO_FIELD_INFO(goods_id) {
		info->description = ZH_WORDS_GETTER("removal-adjustment.query.goods_id");
	}
	DTO_FIELD(String, goods_name) = "abc";
	DTO_FIELD_INFO(goods_name) {
		info->description = ZH_WORDS_GETTER("removal-adjustment.query.goods_name");
	}
	//API_DTO_FIELD_DEFAULT(String, goods_name, ZH_WORDS_GETTER("removal-adjustment.query.goods_name"));
	//数量goods_qua
	DTO_FIELD(String, goods_qua) = "0";
	DTO_FIELD_INFO(goods_qua) {
		info->description = ZH_WORDS_GETTER("removal-adjustment.query.goods_qua");
	}
	//API_DTO_FIELD_DEFAULT(String, goods_qua, ZH_WORDS_GETTER("removal-adjustment.query.goods_qua"));
    
};
class RemovalDetailPageDTO : public  PageDTO<RemovalDetailDTO::Wrapper>
{
	DTO_INIT(RemovalDetailPageDTO, PageDTO<RemovalDetailDTO::Wrapper>);


};
class RemovalPageDTO : public PageDTO<RemovalListDTO::Wrapper> 
{
	DTO_INIT(RemovalPageDTO, PageDTO<RemovalListDTO::Wrapper>);
	
};
#include OATPP_CODEGEN_END(DTO)
#endif // 