#pragma once



#ifndef _customer_DTO_
#define _customer_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例新增数据传输对象,这个用不到，但需要
 */
class CustomerBillDTO : public oatpp::DTO
{
	DTO_INIT(CustomerBillDTO, DTO);
	// 客户编码;
	DTO_FIELD(String, customercode);
	DTO_FIELD_INFO(customercode) {
		info->description = ZH_WORDS_GETTER("field.customer-code");
	}
	// 中文全称
	DTO_FIELD(String, fullchinesename);;
	DTO_FIELD_INFO(fullchinesename) {
		info->description = ZH_WORDS_GETTER("field.full-chinese-name");
	}
};



/**
 * 示例分页传输对象
 */
class CustomerBillPageDTO : public PageDTO<CustomerBillDTO::Wrapper>
{

	DTO_INIT(CustomerBillPageDTO, PageDTO<CustomerBillDTO::Wrapper>);



};




#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_