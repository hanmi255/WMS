#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: tudou
 @Date: 2022/10/25 11:36:29

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
#ifndef _COSTCONFIG_QUERY_
#define _COSTCONFIG_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 客户计费方式查询对象
 */
class CostConfigQuery : public PageQuery
{
	DTO_INIT(CostConfigQuery, PageQuery);
	// 计费方式代码
	API_DTO_FIELD_DEFAULT(String, costconfigcode, ZH_WORDS_GETTER("CostConfigQuery.way.code"));
	// 计费方式编码
	API_DTO_FIELD_DEFAULT(String, costconfignumber, ZH_WORDS_GETTER("CostConfigQuery.way.number"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_