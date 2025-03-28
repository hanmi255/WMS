#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: greent
 @Date: 2025/02/22 19:23:06

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
#ifndef _COMPANYINFODTO_H_
#define _COMPANYINFODTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 企业基础信息对象
 */
class CompanyInfoDTO : public oatpp::DTO
{
	DTO_INIT(CompanyInfoDTO, DTO);
	//公司id
	//API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("companyinfo.id"));
	// 公司代码
	API_DTO_FIELD_DEFAULT(String, companyId, ZH_WORDS_GETTER("companyinfo.companyId"));
	// 公司中文简称
	API_DTO_FIELD_DEFAULT(String, zhabbr, ZH_WORDS_GETTER("companyinfo.zhabbr"));
	// 公司中文全称
	API_DTO_FIELD_DEFAULT(String, zhful, ZH_WORDS_GETTER("companyinfo.zhful"));
	//中文地址
	API_DTO_FIELD_DEFAULT(String, zhaddr, ZH_WORDS_GETTER("companyinfo.zhaddr"));
	//公司英文简称
	API_DTO_FIELD_DEFAULT(String, enabbr, ZH_WORDS_GETTER("companyinfo.enabbr"));
	//公司英文全称
	API_DTO_FIELD_DEFAULT(String, enful, ZH_WORDS_GETTER("companyinfo.enful"));

};

/*
*企业录入信息对象
*/
class CompanyAddInfoDTO : public CompanyInfoDTO
{
	DTO_INIT(CompanyAddInfoDTO, CompanyInfoDTO);
};

class CompanyUpdateInfoDTO : public CompanyInfoDTO
{
	DTO_INIT(CompanyUpdateInfoDTO, CompanyInfoDTO);
	//uuid
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("companyinfo.id"));
};

class CompanyRemoveInfoDTO : public oatpp::DTO
{
	DTO_INIT(CompanyRemoveInfoDTO, DTO);

	API_DTO_FIELD_DEFAULT(Vector<String>, companyId, ZH_WORDS_GETTER("companyinfo.companyIds"));
};

#include OATPP_CODEGEN_END(DTO)
#endif 