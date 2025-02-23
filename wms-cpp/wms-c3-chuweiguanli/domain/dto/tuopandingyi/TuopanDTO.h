#pragma once

#ifndef _TUOPAN_DTO_
#define _TUOPAN_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����б������
 */

class TuopanDTO : public oatpp::DTO
{
	DTO_INIT(TuopanDTO, DTO);
	// ���̺�
	DTO_FIELD(String, tin_id);
	DTO_FIELD_INFO(tin_id) {
		info->description = ZH_WORDS_GETTER("tuopan.field.id");
	}
	// ����˳��
	DTO_FIELD(String, tin_sort);
	DTO_FIELD_INFO(tin_sort) {
		info->description = ZH_WORDS_GETTER("tuopan.field.order");
	}
	// ��λ
	DTO_FIELD(String, bin_id);
	DTO_FIELD_INFO(bin_id) {
		info->description = ZH_WORDS_GETTER("tuopan.field.place");
	}
	// ����״̬
	DTO_FIELD(String, tin_status);
	DTO_FIELD_INFO(tin_status) {
		info->description = ZH_WORDS_GETTER("tuopan.field.status");
	}
};


/*
* ���̷�ҳ�������
*/
class TuopanPageDTO : public PageDTO<TuopanDTO::Wrapper>
{
	DTO_INIT(TuopanPageDTO, PageDTO<TuopanDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TUOPAN_DTO_