#pragma once

#ifndef _COMPANY_DTO_
#define _COMPANY_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 企业基础数据对象
 */
class CompanyBaseDTO : public oatpp::DTO
{
	DTO_INIT(CompanyBaseDTO, oatpp::DTO);
	// 企业属性代码
	API_DTO_FIELD_DEFAULT(String, id,"com_type_code");

	// 企业属性名称
	API_DTO_FIELD_DEFAULT(String, name, "com_type_name");

};

/**
 * 企业基础数据对象
 */
class CompanyListDTO : public CompanyBaseDTO
{
	DTO_INIT(CompanyListDTO, CompanyBaseDTO);

};

/**
 * 企业属性分页传输对象
 */
class CompanyListPageDTO : public PageDTO<CompanyListDTO::Wrapper>
{
	DTO_INIT(CompanyListPageDTO, PageDTO<CompanyListDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_