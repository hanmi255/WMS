#pragma once
/*
 @Author: nanbowan
*/

#include"../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 新增数据传输对象
 */
class FileAddDTO : public oatpp::DTO
{
	DTO_INIT(FileAddDTO, DTO);
	// 订单类型编码
	DTO_FIELD(String, order_type_code);
	DTO_FIELD_INFO(order_type_code) {
		info->description = ZH_WORDS_GETTER("dictionary.order.code.summary");
	}
	// 订单类型名称
	DTO_FIELD(String, order_type_name);
	DTO_FIELD_INFO(order_type_name) {
		info->description = ZH_WORDS_GETTER("dictionary.order.type.summary");
	}
};

/*
* 文件类型对象
*/
class FileDTO :public oatpp::DTO
{
	DTO_INIT(FileDTO, DTO);

	//订单类型代码
	API_DTO_FIELD_DEFAULT(String, order_type_code, ZH_WORDS_GETTER("dictionary.order.code.summary"));

	//订单类型名称
	API_DTO_FIELD_DEFAULT(String, order_name_name, ZH_WORDS_GETTER("dictionary.order.type.summary"));

};


#include OATPP_CODEGEN_END(DTO)
