#pragma once
#ifndef _ORDERTYPEQUERY_H_
#define _ORDERTYPEQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个获取订单类型列表的数据传输模型
 */
class OrderTypeQuery : public PageQuery
{
	DTO_INIT(OrderTypeQuery, PageQuery);
	// 订单类型代码
	API_DTO_FIELD_DEFAULT(String, order_type_code, ZH_WORDS_GETTER("order_type.field.order_type_code"));
	// 订单类型名称
	API_DTO_FIELD_DEFAULT(String, order_type_name, ZH_WORDS_GETTER("order_type.field.order_type_name"));
};

#include OATPP_CODEGEN_END(DTO)


#endif // !_ORDERTYPEQUERY_H_