#pragma once
#ifndef _ORDERTYPEDTO_H_
#define _ORDERTYPEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 录入订单类型DTO
*/ 
class OrderTypeAddDTO : public oatpp::DTO
{
	DTO_INIT(OrderTypeAddDTO, DTO);
	// 订单类型代码
	API_DTO_FIELD_DEFAULT(String, order_type_code, ZH_WORDS_GETTER("order_type.field.order_type_code"));
	// 订单类型名称
	API_DTO_FIELD_DEFAULT(String, order_type_name, ZH_WORDS_GETTER("order_type.field.order_type_name"));
};

/**
 * 定义一个获取订单类型的数据传输模型，包含id
 */
class OrderTypeDTO : public OrderTypeAddDTO
{
	DTO_INIT(OrderTypeDTO, OrderTypeAddDTO);
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("order_type.field.order_type_id"));
};

// 获取订单类型名称列表(包含id)
// ...
class InitDTO : public oatpp::DTO
{
	DTO_INIT(InitDTO, DTO);
};

class OrderTypeNameDTO : public oatpp::DTO
{
	DTO_INIT(OrderTypeNameDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("order_type.field.order_type_id"));
	API_DTO_FIELD_DEFAULT(String, order_type_name, ZH_WORDS_GETTER("order_type.field.order_type_name"));
};

class OrderTypeNamePageDTO : public PageDTO<OrderTypeNameDTO::Wrapper>
{
	DTO_INIT(OrderTypeNamePageDTO, PageDTO);
};

/**
*  订单类型列表分页传输对象
*/
class OrderTypePageDTO : public PageDTO<OrderTypeDTO::Wrapper>
{
	DTO_INIT(OrderTypePageDTO, PageDTO);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ORDERTYPEDTO_H_
