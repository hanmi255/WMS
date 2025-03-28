#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: fycc
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
#ifndef _COMPANYSTATEDTO_H_
#define _COMPANYSTATEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 企业基础信息对象
 */
class CompanyStateDTO : public oatpp::DTO
{
	DTO_INIT(CompanyStateDTO, DTO);
	//公司id
	//API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("companyinfo.id"));
	// 客户id
	API_DTO_FIELD_DEFAULT(String, clientid, ZH_WORDS_GETTER("companystate.clientId"));
	// 客户名称
	API_DTO_FIELD_DEFAULT(String, clientname, ZH_WORDS_GETTER("companystate.clientname"));
	// 状态
	API_DTO_FIELD_DEFAULT(String, state, ZH_WORDS_GETTER("companystate.state"));



};

/*
*企业录入信息对象
*/
class CompanyAddStateDTO : public CompanyStateDTO
{
	DTO_INIT(CompanyAddStateDTO, CompanyStateDTO);
};

class CompanyUpdateStateDTO : public CompanyStateDTO
{
	DTO_INIT(CompanyUpdateStateDTO, CompanyStateDTO);
	//uuid
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("companystate.id"));
};

class CompanyRemoveStateDTO : public oatpp::DTO
{
	DTO_INIT(CompanyRemoveStateDTO, DTO);

	API_DTO_FIELD_DEFAULT(Vector<String>, companyId, ZH_WORDS_GETTER("companystate.companyIds"));
};

#include OATPP_CODEGEN_END(DTO)
#endif 