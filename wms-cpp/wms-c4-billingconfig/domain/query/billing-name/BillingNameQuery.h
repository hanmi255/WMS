#pragma once
#ifndef _BILLING_QUERY_
#define _BILLING_QUERY_
#include "../../GlobalInclude.h"
//#include "domain/query/PageQuery.h"
#include "../../../../lib-oatpp/include/domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 上架货物分页查询对象(继承用)
 */
class BillingNameQuery : public PageQuery
{
	//初始化
	DTO_INIT(BillingNameQuery, PageQuery);

	//唯一id
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("Billing-Name.field.id"));
	API_DTO_FIELD_DEFAULT(String, cost_code, ZH_WORDS_GETTER("Billing-Name.field.cost_code"));
	API_DTO_FIELD_DEFAULT(String, cost_name, ZH_WORDS_GETTER("Billing-Name.field.cost_name"));
	API_DTO_FIELD_DEFAULT(String, cost_type_code, ZH_WORDS_GETTER("Billing-Name.field.cost_type_code"));
};







#include OATPP_CODEGEN_END(DTO)
#endif // !_LISTGOODS_QUERY_

