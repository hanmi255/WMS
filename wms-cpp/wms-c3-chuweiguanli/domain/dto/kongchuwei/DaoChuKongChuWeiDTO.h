#pragma once
#ifndef _DAO_CHU_KONG_CHU_WEI_DTO_
#define _DAO_CHU_KONG_CHU_WEI_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �մ�λ�������ݶ���
 */
class DaoChuKongChuWeiDTO : public oatpp::DTO
{
	DTO_INIT(DaoChuKongChuWeiDTO, DTO);
	// �մ�λ�ļ�
	API_DTO_FIELD(String, url, ZH_WORDS_GETTER("file.field.file-url"), true, {});
	// �ļ���������
	API_DTO_FIELD_DEFAULT(String, alt, ZH_WORDS_GETTER("file.field.file-alt"));
	// �ļ����ӵ�ַ
	API_DTO_FIELD_DEFAULT(String, href, ZH_WORDS_GETTER("file.field.file-href"));
public:
	DaoChuKongChuWeiDTO() {}
	DaoChuKongChuWeiDTO(String url, String alt = "", String href = "")
	{
		this->url = url;
		this->alt = alt;
		this->href = href;
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DAO_CHU_KONG_CHU_WEI_DTO_