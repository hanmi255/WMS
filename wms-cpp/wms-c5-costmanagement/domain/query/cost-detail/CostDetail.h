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
	DTO_FIELD(String, cus_code);
	DTO_FIELD_INFO(cus_code) {
		info->description = ZH_WORDS_GETTER("cost.field.cus_code");
	}
	// 客户名称
	DTO_FIELD(String, cus_name);
	DTO_FIELD_INFO(cus_name) {
		info->description = ZH_WORDS_GETTER("cost.field.cus_name");
	}
	// 费用编码
	DTO_FIELD(String, cost_code);
	DTO_FIELD_INFO(cost_code) {
		info->description = ZH_WORDS_GETTER("cost.field.cost_code");
	}
	// 费用名称
	DTO_FIELD(String, cost_name);
	DTO_FIELD_INFO(cost_name) {
		info->description = ZH_WORDS_GETTER("cost.field.cost_name");
	}
	// 费用日期
	DTO_FIELD(String, cost_data);
	DTO_FIELD_INFO(cost_data) {
		info->description = ZH_WORDS_GETTER("cost.field.cost_data");
	}
	// 费用来源
	DTO_FIELD(String, cost_ori);
	DTO_FIELD_INFO(cost_ori) {
		info->description = ZH_WORDS_GETTER("cost.field.cost_ori");
	}
	// 备注
	DTO_FIELD(String, beizhu);
	DTO_FIELD_INFO(beizhu) {
		info->description = ZH_WORDS_GETTER("cost.field.beizhu");
	}
	// 状态
	DTO_FIELD(String, cost_sta);
	DTO_FIELD_INFO(cost_sta) {
		info->description = ZH_WORDS_GETTER("cos.field.cost_sta");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_COST_QUERY_

