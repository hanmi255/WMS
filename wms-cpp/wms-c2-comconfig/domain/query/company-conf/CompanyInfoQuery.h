#pragma once
#ifndef _COMPANY_QUERY_
#define _COMPANY_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 企业信息示例分页查询对象
 */
class CompanyInfoQuery : public PageQuery
{
	DTO_INIT(CompanyInfoQuery, PageQuery);
 	// 公司代码
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("company.field.code"));
	// 公司中文简称
	API_DTO_FIELD_DEFAULT(String, ChineseSampleName, ZH_WORDS_GETTER("company.field.ChineseSampleName"));
	// 公司中文全称
	API_DTO_FIELD_DEFAULT(String, ChineseFullName, ZH_WORDS_GETTER("company.field.ChineseFullName"));
	// 中文地址
	API_DTO_FIELD_DEFAULT(String, ChineseAddr, ZH_WORDS_GETTER("company.field.ChineseAddr"));
	// 公司英文简称
	API_DTO_FIELD_DEFAULT(String, EnglishSampleName, ZH_WORDS_GETTER("company.field.EnglishSampleName"));
	// 公司英文全称
	API_DTO_FIELD_DEFAULT(String, EnglishFullName, ZH_WORDS_GETTER("company.field.EnglishFullName"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_COMPANYQUERY_