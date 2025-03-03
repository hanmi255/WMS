#pragma once
#ifndef _QUERY_TP_DTO_H_
#define _QUERY_TP_DTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class QueryTPDTO : public oatpp::DTO {
	DTO_INIT(QueryTPDTO, DTO);
	// Ö÷¼ü
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("TP.field.id");
	}
	// ÍÐÅÌºÅ
	DTO_FIELD(String, tin_id);
	DTO_FIELD_INFO(tin_id) {
		info->description = ZH_WORDS_GETTER("TP.field.tin_id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_QUERY_TP_DTO_H_
