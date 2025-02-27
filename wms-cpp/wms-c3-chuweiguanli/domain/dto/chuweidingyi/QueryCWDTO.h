#pragma once
#ifndef _QUERY_CW_DTO_
#define _QUERY_CW_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 储位列表基础数据
 */
class ChuWeiBaseDTO : public oatpp::DTO
{
	DTO_INIT(ChuWeiBaseDTO, DTO);
	// 仓库
	DTO_FIELD(String, store);
	DTO_FIELD_INFO(store) {
		info->description = ZH_WORDS_GETTER("chuwei.field.store");
	}
	//上用原方式，下用宏
	//库位编码
	API_DTO_FIELD_DEFAULT(String, store_code, ZH_WORDS_GETTER("chuwei.field.store_code"));
	//库位条码
	API_DTO_FIELD_DEFAULT(String, store_barcode, ZH_WORDS_GETTER("chuwei.field.store_barcode"));
	//库位类型
	API_DTO_FIELD_DEFAULT(String, store_type, ZH_WORDS_GETTER("chuwei.field.store_type"));
	//库位属性
	API_DTO_FIELD_DEFAULT(String, store_attribute, ZH_WORDS_GETTER("chuwei.field.store_attribute"));
	//产品属性
	API_DTO_FIELD_DEFAULT(String, goods_attribute, ZH_WORDS_GETTER("chuwei.field.goods_attribute"));
	//所属客户
	API_DTO_FIELD_DEFAULT(String, customer, ZH_WORDS_GETTER("chuwei.field.customer"));
	//是否停用
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("chuwei.field.state"));
	//备注
	API_DTO_FIELD_DEFAULT(String, notes, ZH_WORDS_GETTER("chuwei.field.notes"));


};

/**
 * 储位列表传输对象
 */
class ChuWeiDTO : public PageDTO<ChuWeiBaseDTO::Wrapper>
{
	DTO_INIT(ChuWeiDTO, PageDTO<ChuWeiBaseDTO::Wrapper>);
	// 主键
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("chuwei.id"));
};


/**
 * 储位列表分页数据对象
 */
class QueryCWPageDTO : public PageDTO<ChuWeiDTO::Wrapper>
{
	DTO_INIT(QueryCWPageDTO, PageDTO<ChuWeiDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_QUERY_CW_DTO_