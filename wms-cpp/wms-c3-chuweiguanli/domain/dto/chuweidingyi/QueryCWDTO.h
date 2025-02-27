#pragma once
#ifndef _QUERY_CW_DTO_
#define _QUERY_CW_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��λ�б��������
 */
class ChuWeiBaseDTO : public oatpp::DTO
{
	DTO_INIT(ChuWeiBaseDTO, DTO);
	// �ֿ�
	DTO_FIELD(String, store);
	DTO_FIELD_INFO(store) {
		info->description = ZH_WORDS_GETTER("chuwei.field.store");
	}
	//����ԭ��ʽ�����ú�
	//��λ����
	API_DTO_FIELD_DEFAULT(String, store_code, ZH_WORDS_GETTER("chuwei.field.store_code"));
	//��λ����
	API_DTO_FIELD_DEFAULT(String, store_barcode, ZH_WORDS_GETTER("chuwei.field.store_barcode"));
	//��λ����
	API_DTO_FIELD_DEFAULT(String, store_type, ZH_WORDS_GETTER("chuwei.field.store_type"));
	//��λ����
	API_DTO_FIELD_DEFAULT(String, store_attribute, ZH_WORDS_GETTER("chuwei.field.store_attribute"));
	//��Ʒ����
	API_DTO_FIELD_DEFAULT(String, goods_attribute, ZH_WORDS_GETTER("chuwei.field.goods_attribute"));
	//�����ͻ�
	API_DTO_FIELD_DEFAULT(String, customer, ZH_WORDS_GETTER("chuwei.field.customer"));
	//�Ƿ�ͣ��
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("chuwei.field.state"));
	//��ע
	API_DTO_FIELD_DEFAULT(String, notes, ZH_WORDS_GETTER("chuwei.field.notes"));


};

/**
 * ��λ�б������
 */
class ChuWeiDTO : public PageDTO<ChuWeiBaseDTO::Wrapper>
{
	DTO_INIT(ChuWeiDTO, PageDTO<ChuWeiBaseDTO::Wrapper>);
	// ����
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("chuwei.id"));
};


/**
 * ��λ�б��ҳ���ݶ���
 */
class QueryCWPageDTO : public PageDTO<ChuWeiDTO::Wrapper>
{
	DTO_INIT(QueryCWPageDTO, PageDTO<ChuWeiDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_QUERY_CW_DTO_