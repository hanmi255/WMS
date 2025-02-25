#pragma once
#ifndef _HUO_QU_CANG_WEI_SHU_JU_QUERY_
#define _HUO_QU_CANG_WEI_SHU_JU_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��λ���ݲ�ѯ����
 */
class HuoQuCangWeiShuJuQuery : public PageQuery
{
	DTO_INIT(HuoQuCangWeiShuJuQuery, PageQuery);
	// �ֿ�
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("store.field.bin_store");
	}

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
	
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_HUO_QU_CANG_WEI_SHU_JU_QUERY_