#pragma once
/*
 @Author: laughter
*/
#ifndef _COMPANYATTR_QUERY_
#define _COMPANYATTR_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 企业分页查询对象
 */
class CompanyattrQuery : public PageQuery
{
	DTO_INIT(CompanyattrQuery, PageQuery);
	// 企业用户代码
	API_DTO_FIELD_DEFAULT(String, com_type_code, ZH_WORDS_GETTER("company.attribute.id"));
	//企业用户名称
	API_DTO_FIELD_DEFAULT(String, com_type_name, ZH_WORDS_GETTER("company.attribute.name"));
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_COMPANYATTR_QUERY_