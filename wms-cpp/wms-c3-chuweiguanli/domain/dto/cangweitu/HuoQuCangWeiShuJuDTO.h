#pragma once
#ifndef _HUO_QU_CANG_WEI_SHU_JU_DTO_
#define _HUO_QU_CANG_WEI_SHU_JU_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��λ���ݲ�ѯ����
 */
class HuoQuCangWeiShuJuDTO : public oatpp::DTO
{
	DTO_INIT(HuoQuCangWeiShuJuDTO, DTO);
	// id
	API_DTO_FIELD_DEFAULT(String, id, "id");
	// �ֿ�
	API_DTO_FIELD_DEFAULT(String, bin_store, ZH_WORDS_GETTER("store.field.bin_store"));

	//��λ
	API_DTO_FIELD_DEFAULT(String, ku_wei_bian_ma, ZH_WORDS_GETTER("store.field.ku_wei_bian_ma"));
	//����
	API_DTO_FIELD_DEFAULT(String, other, ZH_WORDS_GETTER("store.field.other"));
	//����
	API_DTO_FIELD_DEFAULT(String, znode, ZH_WORDS_GETTER("store.field.znode"));
	//����
	API_DTO_FIELD_DEFAULT(String, xnode, ZH_WORDS_GETTER("store.field.xnode"));
	//����
	API_DTO_FIELD_DEFAULT(String, ynode, ZH_WORDS_GETTER("store.field.ynode"));
	//ͣ��
	API_DTO_FIELD_DEFAULT(String, ting_yong, ZH_WORDS_GETTER("store.field.ting_yong"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_HUO_QU_CANG_WEI_SHU_JU_DTO_