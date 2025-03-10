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
	//x轴
	API_DTO_FIELD_DEFAULT(String, x_axis, ZH_WORDS_GETTER("chuwei.field.x_axis"));
	//y轴
	API_DTO_FIELD_DEFAULT(String, y_axis, ZH_WORDS_GETTER("chuwei.field.y_axis"));
	//z轴
	API_DTO_FIELD_DEFAULT(String, z_axis, ZH_WORDS_GETTER("chuwei.field.z_axis"));

	
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CHUWEI_QUERY_