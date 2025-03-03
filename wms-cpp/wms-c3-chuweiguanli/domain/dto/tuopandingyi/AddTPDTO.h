#pragma once
#ifndef _ADD_TP_DTO_H_
#define _ADD_TP_DTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class AddTPDTO: public oatpp::DTO {
	DTO_INIT(AddTPDTO, DTO);
	// ÍÐÅÌºÅ
	DTO_FIELD(String, tin_id);
	DTO_FIELD_INFO(tin_id) {
		info->description = ZH_WORDS_GETTER("TP.field.tin_id");
	}
	// ËùÊô²¿ÃÅ
	DTO_FIELD(String, sys_org_code);
	DTO_FIELD_INFO(sys_org_code) {
		info->description = ZH_WORDS_GETTER("TP.field.sys_org_code");
	}
	// ËùÊô¹«Ë¾
	DTO_FIELD(String, sys_company_code);
	DTO_FIELD_INFO(sys_company_code) {
		info->description = ZH_WORDS_GETTER("TP.field.sys_company_code");
	}
	// ÍÐÅÌË³Ðò
	DTO_FIELD(String, tin_sort);
	DTO_FIELD_INFO(tin_sort) {
		info->description = ZH_WORDS_GETTER("TP.field.tin_sort");
	}
	// ´¢Î»
	DTO_FIELD(String, bin_id);
	DTO_FIELD_INFO(bin_id) {
		info->description = ZH_WORDS_GETTER("TP.field.bin_id");
	}
	// ÍÐÅÌ×´Ì¬
	DTO_FIELD(String, tin_status);
	DTO_FIELD_INFO(tin_status) {
		info->description = ZH_WORDS_GETTER("TP.field.tin_status");
	}
	// Á÷³Ì×´Ì¬
	DTO_FIELD(String, bpm_status);
	DTO_FIELD_INFO(bpm_status) {
		info->description = ZH_WORDS_GETTER("TP.field.bpm_status");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // _ADD_TP_DTO_H_