#pragma once
/*
 @Author: laughter
*/
#ifndef _COMPANYATTR_DTO_
#define _COMPANYATTR_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 企业新增基础数据对象
 */
class CompanyattrDTO : public oatpp::DTO
{
	DTO_INIT(CompanyattrDTO, oatpp::DTO);
	// 企业属性代码
	API_DTO_FIELD_DEFAULT(String, com_type_code, ZH_WORDS_GETTER("company.attribute.id"));

	// 企业属性名称
	API_DTO_FIELD_DEFAULT(String, com_type_name, ZH_WORDS_GETTER("company.attribute.name"));

};

/**
 * 企业基础数据对象
 */
class CompanyattrListDTO : public CompanyattrDTO
{
	DTO_INIT(CompanyattrListDTO, CompanyattrDTO);
	//唯一id
	//API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("company.attribute.onlyid"));
};
/**
 * 企业基础Id数据对象
 */
class CompanyattrIdListDTO : public CompanyattrDTO
{
	DTO_INIT(CompanyattrIdListDTO, CompanyattrDTO);
	//唯一id
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("company.attribute.onlyid"));
};
/**
 * 企业属性分页传输对象
 */
class CompanyattrListPageDTO : public PageDTO<CompanyattrListDTO::Wrapper>
{
	DTO_INIT(CompanyattrListPageDTO, PageDTO<CompanyattrListDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_