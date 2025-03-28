#pragma once


#ifndef _customer_QUERY_
#define _customer_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class CustomerBillQuery : public PageQuery
{
	DTO_INIT(CustomerBillQuery, PageQuery);

	


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
 * 导出未清账单对象
 */
	
class UnsettledQuery : public oatpp::DTO
{
	DTO_INIT(UnsettledQuery, PageQuery);



	// 客户编码;
	DTO_FIELD(String, customercode);
	DTO_FIELD_INFO(customercode) {
		info->description = ZH_WORDS_GETTER("field.customer-code");
	}
	// 文件名称
	DTO_FIELD(String, filename);;
	DTO_FIELD_INFO(filename) {
		info->description = ZH_WORDS_GETTER("bill.filename");
	}

};

	

/**
 * 导出期间账单对象
 */ 
class PeriodQuery : public oatpp::DTO
{
		DTO_INIT(PeriodQuery, PageQuery);

		// 客户编码;
		DTO_FIELD(String, customercode);
		DTO_FIELD_INFO(customercode) {
			info->description = ZH_WORDS_GETTER("field.customer-code");
		}

		// 开始时间
		DTO_FIELD(String, startdate);
		DTO_FIELD_INFO(startdate) {
			info->description = ZH_WORDS_GETTER("field.begin");
		}
		// 结束时间
		DTO_FIELD(String, enddate);;
		DTO_FIELD_INFO(enddate) {
			info->description = ZH_WORDS_GETTER("bill.end");
		}


		// 文件名称
		DTO_FIELD(String, filename);;
		DTO_FIELD_INFO(filename) {
			info->description = ZH_WORDS_GETTER("bill.filename");
		}

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_