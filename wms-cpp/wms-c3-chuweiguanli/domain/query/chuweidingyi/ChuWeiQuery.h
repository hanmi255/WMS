#pragma once
#ifndef _CHUWEI_QUERY_
#define _CHUWEI_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��λ��ҳ��ѯ����
 */
class ChuWeiQuery : public PageQuery
{
	DTO_INIT(ChuWeiQuery, PageQuery);
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
	//x��
	API_DTO_FIELD_DEFAULT(String, x_axis, ZH_WORDS_GETTER("chuwei.field.x_axis"));
	//y��
	API_DTO_FIELD_DEFAULT(String, y_axis, ZH_WORDS_GETTER("chuwei.field.y_axis"));
	//z��
	API_DTO_FIELD_DEFAULT(String, z_axis, ZH_WORDS_GETTER("chuwei.field.z_axis"));

	
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CHUWEI_QUERY_