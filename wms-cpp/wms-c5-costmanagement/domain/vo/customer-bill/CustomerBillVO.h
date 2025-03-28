#pragma once

#ifndef _customer_VO_
#define _customer_VO_

#include "../../GlobalInclude.h"
#include "../../dto/customer-bill/CustomerBillDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象--------------不用先留着
 */
class CustomerBillJsonVO : public JsonVO<CustomerBillDTO::Wrapper> {
	DTO_INIT(CustomerBillJsonVO, JsonVO<CustomerBillDTO::Wrapper>);
};

/**
 * 分页显示JsonVO，用于响应给客户端的Json对象
 */
class CustomerBillPageJsonVO : public JsonVO<CustomerBillPageDTO::Wrapper> {
	DTO_INIT(CustomerBillPageJsonVO, JsonVO<CustomerBillPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_