#pragma once

#include"../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//	��ȡ�ֿ��б� ���ݴ������
class CangkuListDTO : public oatpp::DTO
{
	DTO_INIT(CangkuListDTO, DTO);

	//	�ֿ�ID
	DTO_FIELD(Int64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("Cangku.info.id");
	}

	//	�ֿ�����
	DTO_FIELD(String, store_name);
	DTO_FIELD_INFO(store_name) {
		info->description = ZH_WORDS_GETTER("Cangku.info.store_name");
	}

	//	�ֿ����
	DTO_FIELD(String, store_code);
	DTO_FIELD_INFO(store_code) {
		info->description = ZH_WORDS_GETTER("Cangku.info.store_code");
	}

	//	�ֿ�����
	DTO_FIELD(String, store_text);
	DTO_FIELD_INFO(store_text) {
		info->description = ZH_WORDS_GETTER("Cangku.info.store_text");
	}
};

#include OATPP_CODEGEN_END(DTO)

