#pragma once
/*
 @Author: nanbowan
*/
#include"../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* 修改订单类型对象
*/
class ModifyOrderTypeDTO :public oatpp::DTO
{
	DTO_INIT(ModifyOrderTypeDTO, DTO);

	//要修改的订单类型的唯一id
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("dictionary.order.id.summary"));

	//新订单类型代码
	API_DTO_FIELD_DEFAULT(String, order_type_code, ZH_WORDS_GETTER("dictionary.order.code.summary"));

	//新订单类型名称
	API_DTO_FIELD_DEFAULT(String, order_type_name, ZH_WORDS_GETTER("dictionary.order.type.summary"));

};


#include OATPP_CODEGEN_END(DTO)
