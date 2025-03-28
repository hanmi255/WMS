#pragma once

#ifndef BUSINESS_LINK_DTO
#define BUSINESS_LINK_DTO

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class BusinessLinkAddDTO : public oatpp::DTO {
	DTO_INIT(BusinessLinkAddDTO, DTO);

	DTO_FIELD(String, ID);
	DTO_FIELD_INFO(ID) {
		info->description = ZH_WORDS_GETTER("business-link.field.ID");
	}
	DTO_FIELD(String, oper_step_code);
	DTO_FIELD_INFO(oper_step_code) {
		info->description = ZH_WORDS_GETTER("business-link.field.oper-step-code");
	}
	DTO_FIELD(String, oper_step_name);
	DTO_FIELD_INFO(oper_step_name) {
		info->description = ZH_WORDS_GETTER("business-link.field.oper-step-name");
	}
};

class BusinessLinkDTO : public oatpp::DTO {
	DTO_INIT(BusinessLinkDTO, DTO);

	DTO_FIELD(String, create_name);
	DTO_FIELD_INFO(create_name) {
		info->description = ZH_WORDS_GETTER("business-link.field.create-name");
	}
	DTO_FIELD(String, create_by);
	DTO_FIELD_INFO(create_by) {
		info->description = ZH_WORDS_GETTER("business-link.field.create-by");
	}
	DTO_FIELD(String, create_date);
	DTO_FIELD_INFO(create_date) {
		info->description = ZH_WORDS_GETTER("business-link.field.create-date");
	}
	DTO_FIELD(String, update_name);
	DTO_FIELD_INFO(update_name) {
		info->description = ZH_WORDS_GETTER("business-link.field.update-name");
	}
	DTO_FIELD(String, update_by);
	DTO_FIELD_INFO(update_by) {
		info->description = ZH_WORDS_GETTER("business-link.field.update-by");
	}
	DTO_FIELD(String, update_date);
	DTO_FIELD_INFO(update_date) {
		info->description = ZH_WORDS_GETTER("business-link.field.update-date");
	}
	DTO_FIELD(String, sys_org_code);
	DTO_FIELD_INFO(sys_org_code) {
		info->description = ZH_WORDS_GETTER("business-link.field.sys-org-code");
	}
	DTO_FIELD(String, sys_company_code);
	DTO_FIELD_INFO(sys_company_code) {
		info->description = ZH_WORDS_GETTER("business-link.field.sys-company-code");
	}
	DTO_FIELD(String, oper_step_code);
	DTO_FIELD_INFO(oper_step_code) {
		info->description = ZH_WORDS_GETTER("business-link.field.oper-step-code");
	}
	DTO_FIELD(String, oper_step_name);
	DTO_FIELD_INFO(oper_step_name) {
		info->description = ZH_WORDS_GETTER("business-link.field.oper-step-name");
	}
};

class BusinessLinkPageDTO : public PageDTO<BusinessLinkDTO::Wrapper> {
	DTO_INIT(BusinessLinkPageDTO, PageDTO<BusinessLinkDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif //BUSINESS_LINK_DTO