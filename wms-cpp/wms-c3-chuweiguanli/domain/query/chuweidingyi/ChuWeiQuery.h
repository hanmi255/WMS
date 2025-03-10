#pragma once
#ifndef _CHUWEI_QUERY_
#define _CHUWEI_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 储位分页查询对象
 */
class ChuWeiQuery : public PageQuery
{
	DTO_INIT(ChuWeiQuery, PageQuery);
	// 仓库
	DTO_FIELD(String, bin_store);
	DTO_FIELD_INFO(bin_store) {
		info->description = ZH_WORDS_GETTER("Chuwei.field.bin_store");
	}
	//上用原方式，下用宏
	//库位编码
	API_DTO_FIELD_DEFAULT(String, ku_wei_bian_ma, ZH_WORDS_GETTER("Chuwei.field.ku_wei_bian_ma"));
	//库位条码
	API_DTO_FIELD_DEFAULT(String, ku_wei_tiao_ma, ZH_WORDS_GETTER("Chuwei.field.ku_wei_tiao_ma"));
	//库位类型
	API_DTO_FIELD_DEFAULT(String, ku_wei_lei_xing, ZH_WORDS_GETTER("Chuwei.field.ku_wei_lei_xing"));
	//x坐标
	API_DTO_FIELD_DEFAULT(String, xnode, ZH_WORDS_GETTER("Chuwei.field.xnode"));
	//y坐标
	API_DTO_FIELD_DEFAULT(String, ynode, ZH_WORDS_GETTER("Chuwei.field.ynode"));
	//z坐标
	API_DTO_FIELD_DEFAULT(String, znode, ZH_WORDS_GETTER("Chuwei.field.znode"));	
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CHUWEI_QUERY_