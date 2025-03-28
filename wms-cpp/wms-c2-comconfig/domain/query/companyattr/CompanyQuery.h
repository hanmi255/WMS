#pragma once
#ifndef _ENTERPRISE_QUERY_
#define _ENTERPRISE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 企业分页查询对象
 */
class CompanyQuery : public PageQuery
{
	DTO_INIT(CompanyQuery, PageQuery);
	// 企业用户代码
	API_DTO_FIELD_DEFAULT(String, id, "com_type_code");
	//企业用户名称
	API_DTO_FIELD_DEFAULT(String, name, "com_type_name");
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_ENTERPRISE_QUERY_