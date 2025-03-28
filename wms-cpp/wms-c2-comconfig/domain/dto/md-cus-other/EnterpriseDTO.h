#pragma once

#ifndef _ENTERPRISEDTO_
#define _ENTERPRISEDTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 企业基础数据对象
 */
class EnterpriseListDTO : public oatpp::DTO
{
	DTO_INIT(EnterpriseListDTO, oatpp::DTO);
	// 企业状态代码
	API_DTO_FIELD_DEFAULT(String, enterpriseid, ZH_WORDS_GETTER("get.enterpriseid"));

	// 企业状态名称
	API_DTO_FIELD_DEFAULT(String, enterprisename, ZH_WORDS_GETTER("get.enterprisename"));

	//状态
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("enterprise.field.status"));


};


/**
 * 企业状态分页传输对象
 */
class EnterpriseListPageDTO : public PageDTO<EnterpriseListDTO::Wrapper>
{
	DTO_INIT(EnterpriseListPageDTO, PageDTO<EnterpriseListDTO::Wrapper>);
};

//企业状态下拉菜单，只有停用和启用两个状态 
class EnterpriseStatusDTO : public  oatpp::DTO
{ 
	DTO_INIT(EnterpriseStatusDTO, oatpp::DTO);
	//唯一id
	API_DTO_FIELD_DEFAULT(String, statusonlyid, ZH_WORDS_GETTER("enterprise.field.only"));
	// 企业状态代码
	API_DTO_FIELD_DEFAULT(String, enterpriseid, ZH_WORDS_GETTER("get.enterpriseid"));

	// 企业状态名称
	API_DTO_FIELD_DEFAULT(String, enterprisename, ZH_WORDS_GETTER("get.enterprisename"));
}; 

/**
 * 企业基础数据对象
 */
class EnterpriseStatusListDTO : public EnterpriseStatusDTO
{
	DTO_INIT(EnterpriseStatusListDTO, oatpp::DTO);
	DTO_FIELD(List<EnterpriseStatusDTO::Wrapper>, items);

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_