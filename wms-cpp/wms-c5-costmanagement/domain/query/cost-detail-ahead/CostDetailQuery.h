#pragma once

#ifndef _COST_QUERY_
#define _COST_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 费用明细分页查询对象   query这里相当于查询条件字段
 */
class CostDetailQuery : public PageQuery
{
	DTO_INIT(CostDetailQuery, PageQuery);
	
	// 客户编码
	DTO_FIELD(String, cusCode);
	DTO_FIELD_INFO(cusCode) {
		info->description = ZH_WORDS_GETTER("cost.field.cus_code");
	}
	// 客户名称
	DTO_FIELD(String, cusName);
	DTO_FIELD_INFO(cusName) {
		info->description = ZH_WORDS_GETTER("cost.field.cus_name");
	}
	// 费用编码
	DTO_FIELD(String, costCode);
	DTO_FIELD_INFO(costCode) {
		info->description = ZH_WORDS_GETTER("cost.field.cost_code");
	}
	// 费用名称
	DTO_FIELD(String, costName);
	DTO_FIELD_INFO(costName) {
		info->description = ZH_WORDS_GETTER("cost.field.cost_name");
	}
	// 费用日期开始
	DTO_FIELD(String, costDateBegin);
	DTO_FIELD_INFO(costDateBegin) {
		info->description = ZH_WORDS_GETTER("cost.field.cost_date_begin");
	}
	// 费用日期结束
	DTO_FIELD(String, costDateEnd);
	DTO_FIELD_INFO(costDateEnd) {
		info->description = ZH_WORDS_GETTER("cost.field.cost_date_end");
	}
	DTO_FIELD(String, costOrigin);
	DTO_FIELD_INFO(costOrigin) {
		info->description = ZH_WORDS_GETTER("cost.field.cost_ori");
	}
	// 备注
	DTO_FIELD(String, note);
	DTO_FIELD_INFO(note) {
		info->description = ZH_WORDS_GETTER("cost.field.beizhu");
	}
	// 状态
	DTO_FIELD(String, costState);
	DTO_FIELD_INFO(costState) {
		info->description = ZH_WORDS_GETTER("cos.field.cost_sta");
	}
	

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_COST_QUERY_

