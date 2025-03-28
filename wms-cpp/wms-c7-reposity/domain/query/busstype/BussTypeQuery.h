#pragma once
#ifndef _BUSSTYPE_QUERY_
#define _BUSSTYPE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ҵ�����ͷ�ҳ��ѯ����
 */
class BussTypeQuery : public PageQuery
{
	DTO_INIT(BussTypeQuery, PageQuery);
	
	//API_DTO_FIELD_DEFAULT(String, create_name, ZH_WORDS_GETTER("buss-type.field.create-name"));
	//API_DTO_FIELD_DEFAULT(String, create_by, ZH_WORDS_GETTER("buss-type.field.create-by"));
	//API_DTO_FIELD_DEFAULT(String, create_date, ZH_WORDS_GETTER("buss-type.field.create-date"));

	//API_DTO_FIELD_DEFAULT(String, update_name, ZH_WORDS_GETTER("buss-type.field.update-name"));
	//API_DTO_FIELD_DEFAULT(String, update_by, ZH_WORDS_GETTER("buss-type.field.update-by"));
	//API_DTO_FIELD_DEFAULT(String, update_date, ZH_WORDS_GETTER("buss-type.field.update-date"));
	//
	//API_DTO_FIELD_DEFAULT(String, sys_org_code, ZH_WORDS_GETTER("buss-type.field.sys-org-code"));
	//API_DTO_FIELD_DEFAULT(String, sys_company_code, ZH_WORDS_GETTER("buss-type.field.sys-company-code"));
	//
	// ����
	API_DTO_FIELD_DEFAULT(String, buss_type_name, ZH_WORDS_GETTER("buss-type.field.buss-type-code"));
	// ����
	API_DTO_FIELD_DEFAULT(String, buss_type_code, ZH_WORDS_GETTER("buss-type.field.buss-type-name"));
	// ��ע
	API_DTO_FIELD_DEFAULT(String, buss_type_text, ZH_WORDS_GETTER("buss-type.field.buss-type-text"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_BUSSTYPE_QUERY_
