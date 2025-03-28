#pragma once

#ifndef _ORDERTYPEVO_H_
#define _ORDERTYPEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/order_type/OrderTypeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个订单类型的类型显示JsonVO对象
 */
class OrderTypeVO : public JsonVO<OrderTypeDTO::Wrapper> {
    DTO_INIT(OrderTypeVO, JsonVO<OrderTypeDTO::Wrapper>);
};

/**
 * 分页显示JsonVO对象，用于响应给客户端
 */
class OrderTypePageJsonVO : public JsonVO<OrderTypePageDTO::Wrapper> 
{
    DTO_INIT(OrderTypePageJsonVO, JsonVO<OrderTypePageDTO::Wrapper>);
};

/**
 * 订单类型名称列表显示JsonVO对象，用于响应给客户端
 */
class OrderTypeNameVO : public JsonVO<OrderTypeNamePageDTO::Wrapper> {
    DTO_INIT(OrderTypeNameVO, JsonVO<OrderTypeNamePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ORDERTYPEVO_H_
