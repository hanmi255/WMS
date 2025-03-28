#pragma once

#ifndef _FILEDTO_H_
#define _FILEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * editor图片信息传输数据对象
 */
class EditorImageDTO : public oatpp::DTO
{
	DTO_INIT(EditorImageDTO, DTO);
	// 图片src
	API_DTO_FIELD(String, url, ZH_WORDS_GETTER("file.field.img-url"), true, {});
	// 图片文字描述
	API_DTO_FIELD_DEFAULT(String, alt, ZH_WORDS_GETTER("file.field.img-alt"));
	// 图片链接地址
	API_DTO_FIELD_DEFAULT(String, href, ZH_WORDS_GETTER("file.field.img-href"));
public:
	EditorImageDTO() {}
	EditorImageDTO(String url, String alt = "", String href = "")
	{
		this->url = url;
		this->alt = alt;
		this->href = href;
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_FILEDTO_H_