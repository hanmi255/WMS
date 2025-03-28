#pragma once

#ifndef _BUSSTYPE_DTO_
#define _BUSSTYPE_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ҵ�����ͻ����б����
 */
class BussTypeBaseDTO : public oatpp::DTO
{
	DTO_INIT(BussTypeBaseDTO, DTO);
	//API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("buss-type.field.id"));
	// ����
	API_DTO_FIELD_DEFAULT(String, buss_type_name, ZH_WORDS_GETTER("buss-type.field.buss-type-code"));
	// ����
	API_DTO_FIELD_DEFAULT(String, buss_type_code, ZH_WORDS_GETTER("buss-type.field.buss-type-name"));
	// ��ע
	API_DTO_FIELD_DEFAULT(String, buss_type_text, ZH_WORDS_GETTER("buss-type.field.buss-type-text"));
};
/**
 * ҵ��������ϸ�б����
 */
class BussTypeDTO : public BussTypeBaseDTO
{
	DTO_INIT(BussTypeDTO, BussTypeBaseDTO);
	//API_DTO_FIELD_DEFAULT(String, create_name, ZH_WORDS_GETTER("buss-type.field.create-name"));
	//API_DTO_FIELD_DEFAULT(String, create_by, ZH_WORDS_GETTER("buss-type.field.create-by"));
	//API_DTO_FIELD_DEFAULT(String, create_date, ZH_WORDS_GETTER("buss-type.field.create-date"));

	//API_DTO_FIELD_DEFAULT(String, update_name, ZH_WORDS_GETTER("buss-type.field.update-name"));
	//API_DTO_FIELD_DEFAULT(String, update_by, ZH_WORDS_GETTER("buss-type.field.update-by"));
	//API_DTO_FIELD_DEFAULT(String, update_date, ZH_WORDS_GETTER("buss-type.field.update-date"));

	//API_DTO_FIELD_DEFAULT(String, sys_org_code, ZH_WORDS_GETTER("buss-type.field.sys-org-code"));
	//API_DTO_FIELD_DEFAULT(String, sys_company_code, ZH_WORDS_GETTER("buss-type.field.sys-company-code"));
};
/**
 * ¼��ҵ�������б����
 */
class BussTypeAddDTO : public BussTypeDTO
{
	DTO_INIT(BussTypeAddDTO, BussTypeDTO);
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("buss-type.field.id"));
};

/**
 * ҵ�������б��ҳ�������
 */
class BussTypeListPageDTO : public PageDTO<BussTypeBaseDTO::Wrapper>
{
	DTO_INIT(BussTypeListPageDTO, PageDTO<BussTypeBaseDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_BUSSTYPE_DTO_