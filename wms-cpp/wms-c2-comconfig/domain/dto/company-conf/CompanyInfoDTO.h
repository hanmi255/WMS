#pragma once
#ifndef _COMPANYINFODTO_
#define _COMPANYINFODTO_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 企业基础信息数据传输对象
 */
class CompanyBaseeDTO : public oatpp::DTO
{
	// 初始化
	DTO_INIT(CompanyBaseeDTO, DTO);

	// 公司代码
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("company.field.code"));

	// 公司中文简称
	API_DTO_FIELD_DEFAULT(String, ChineseFullName, ZH_WORDS_GETTER("company.field.ChineseFullName"));

	// 公司中文全称
	API_DTO_FIELD_DEFAULT(String, ChineseSampleName, ZH_WORDS_GETTER("company.field.ChineseSampleName"));

	// 公司地址
	API_DTO_FIELD_DEFAULT(String, ChineseAddr, ZH_WORDS_GETTER("company.field.ChineseAddr"));

	// 公司英文简称
	API_DTO_FIELD_DEFAULT(String, EnglishSampleName, ZH_WORDS_GETTER("company.field.EnglishSampleName"));

	// 公司英文全称
	API_DTO_FIELD_DEFAULT(String, EnglishFullName, ZH_WORDS_GETTER("company.field.EnglishFullName"));
};


class CompanyListDTO : public CompanyBaseeDTO
{
	// 初始化
	DTO_INIT(CompanyListDTO, CompanyBaseeDTO);
	// 唯一标识
 	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("company.field.id"));
};



//公司信息分页传输对象
class CompanyListPageDTO : public PageDTO<CompanyListDTO::Wrapper>
{
	DTO_INIT(CompanyListPageDTO, PageDTO<CompanyListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_COMPANY_DTO_