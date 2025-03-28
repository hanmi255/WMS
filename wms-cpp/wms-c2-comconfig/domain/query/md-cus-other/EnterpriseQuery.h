#pragma once
#ifndef _ENTERPRISEQUERY_
#define _ENTERPRISEQUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 企业分页查询对象
 */
class EnterpriseQuery: public PageQuery
{
	DTO_INIT(EnterpriseQuery, PageQuery);
	// 企业用户代码
	API_DTO_FIELD_DEFAULT(String, enterpriseid, ZH_WORDS_GETTER("get.enterpriseid"));

	//企业用户名称
	API_DTO_FIELD_DEFAULT(String, enterprisename, ZH_WORDS_GETTER("get.enterprisename"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ENTERPRISE_QUERY_