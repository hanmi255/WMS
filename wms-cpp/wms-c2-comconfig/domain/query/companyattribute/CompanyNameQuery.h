#pragma once
#ifndef _ENTERPRISE_QUERY_
#define _ENTERPRISE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 企业状态信息列表  包括名称，编码，唯一标识
 */

class CompanyNameQueryStatus : public PageQuery
{
	DTO_INIT(CompanyNameQueryStatus, PageQuery);
	// 企业状态名称
	API_DTO_FIELD_DEFAULT(String, inform, ZH_WORDS_GETTER("company.field.name"));


};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ENTERPRISE_QUERY_
