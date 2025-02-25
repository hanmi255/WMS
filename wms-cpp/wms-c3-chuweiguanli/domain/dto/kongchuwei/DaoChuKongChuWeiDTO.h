#pragma once
#ifndef _DAO_CHU_KONG_CHU_WEI_DTO_
#define _DAO_CHU_KONG_CHU_WEI_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 空储位传输数据对象
 */
class DaoChuKongChuWeiDTO : public oatpp::DTO
{
	DTO_INIT(DaoChuKongChuWeiDTO, DTO);
	// 空储位文件
	API_DTO_FIELD(String, url, ZH_WORDS_GETTER("file.field.file-url"), true, {});
	// 文件文字描述
	API_DTO_FIELD_DEFAULT(String, alt, ZH_WORDS_GETTER("file.field.file-alt"));
	// 文件链接地址
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