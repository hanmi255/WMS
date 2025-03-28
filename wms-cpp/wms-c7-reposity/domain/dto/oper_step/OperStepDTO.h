/*
/*@File Name         : OperStepDTO.h                                                     
/*@Author            : 智商局局长
/*@Description       :
*/

#ifndef _OperStep_DTO
#define _OperStep_DTO
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/// @brief 业务环节
class OperStepDTO : public oatpp::DTO {
	DTO_INIT(OperStepDTO, DTO);

	API_DTO_FIELD_DEFAULT(String, ID, ZH_WORDS_GETTER("business-link.field.ID"));
	API_DTO_FIELD_DEFAULT(String, create_name, ZH_WORDS_GETTER("business-link.field.create-name"));
	API_DTO_FIELD_DEFAULT(String, create_by, ZH_WORDS_GETTER("business-link.field.create-by"));
	API_DTO_FIELD_DEFAULT(String, create_date, ZH_WORDS_GETTER("business-link.field.create-date"));
	API_DTO_FIELD_DEFAULT(String, oper_step_code, ZH_WORDS_GETTER("business-link.field.oper-step-code"));
	API_DTO_FIELD_DEFAULT(String, oper_step_name, ZH_WORDS_GETTER("business-link.field.oper-step-name"));
	API_DTO_FIELD_DEFAULT(String, update_name, ZH_WORDS_GETTER("business-link.field.update-name"));
	API_DTO_FIELD_DEFAULT(String, update_by, ZH_WORDS_GETTER("business-link.field.update-by"));
	API_DTO_FIELD_DEFAULT(String, update_date, ZH_WORDS_GETTER("business-link.field.update-date"));
	API_DTO_FIELD_DEFAULT(String, sys_org_code, ZH_WORDS_GETTER("business-link.field.sys-org-code"));
	API_DTO_FIELD_DEFAULT(String, sys_company_code, ZH_WORDS_GETTER("business-link.field.sys-company-code"));
};

/// @brief 修改业务环节
class OperStepModifyDTO : public oatpp::DTO {
	DTO_INIT(OperStepModifyDTO, DTO);

	API_DTO_FIELD_DEFAULT(String, ID, ZH_WORDS_GETTER("business-link.field.ID"));
	API_DTO_FIELD_DEFAULT(String, oper_step_code, ZH_WORDS_GETTER("business-link.field.oper-step-code"));
	API_DTO_FIELD_DEFAULT(String, oper_step_name, ZH_WORDS_GETTER("business-link.field.oper-step-name"));
	API_DTO_FIELD_DEFAULT(String, update_name, ZH_WORDS_GETTER("business-link.field.update-name"));
	API_DTO_FIELD_DEFAULT(String, update_by, ZH_WORDS_GETTER("business-link.field.update-by"));
	API_DTO_FIELD_DEFAULT(String, update_date, ZH_WORDS_GETTER("business-link.field.update-date"));
	API_DTO_FIELD_DEFAULT(String, sys_org_code, ZH_WORDS_GETTER("business-link.field.sys-org-code"));
	API_DTO_FIELD_DEFAULT(String, sys_company_code, ZH_WORDS_GETTER("business-link.field.sys-company-code"));
};

/// @brief 删除业务环节
class OperStepDeleteDTO : public oatpp::DTO {
	DTO_INIT(OperStepDeleteDTO, DTO)
	// 使用列表，接受多个id删除
	API_DTO_FIELD_DEFAULT(String, ids, ZH_WORDS_GETTER("business-link.field.ids"));
};
using OperStepDTOList = oatpp::List<OperStepDTO::Wrapper>;

#include OATPP_CODEGEN_END(DTO)
#endif