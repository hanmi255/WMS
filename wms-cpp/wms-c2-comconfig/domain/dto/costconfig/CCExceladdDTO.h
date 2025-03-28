#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: tudou
 @Date: 2023/09/18 15:01:29

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _CCEXCELDTOADD_H_
#define _CCEXCELDTOADD_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * excel文件传输数据对象
 */
class CCExceladdDTO : public oatpp::DTO
{
	DTO_INIT(CCExceladdDTO, DTO);
	// excel文件名
	API_DTO_FIELD_DEFAULT(String, filename, ZH_WORDS_GETTER("file.field.excel-filename"));
	// excel文字描述
	API_DTO_FIELD_DEFAULT(String, alt, ZH_WORDS_GETTER("file.field.excel-alt"));
	// excel地址
	API_DTO_FIELD_DEFAULT(String, href, ZH_WORDS_GETTER("file.field.excel-href"));
public:
	CCExceladdDTO() {}
	CCExceladdDTO(String filename, String alt = "", String href = "")
	{
		this->filename = filename;
		this->alt = alt;
		this->href = href;
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // _CCEXCELDTOADD_H_