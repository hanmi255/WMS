#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: z
 @Date: 2025/2/22 15:37

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
#ifndef _ENTERPRISE_PAGE_QUERY_
#define _ENTERPRISE_PAGE_QUERY_

#include "../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class enterprisePageQuery : public PageQuery
{
	DTO_INIT(enterprisePageQuery, PageQuery);

	//企业分类代码
	DTO_FIELD(String, enterpriseClassificationCode);
	DTO_FIELD_INFO(enterpriseClassificationCode) {
		info->description = "addenterpriseClassificationCode";//ZH_WORDS_GETTER("addenterpriseClassificationCode");//之后更改成yaml格式
	}
	//企业分类名称
	DTO_FIELD(String, enterpriseClassificationName);
	DTO_FIELD_INFO(enterpriseClassificationName) {
		info->description = "addenterpriseClassificationName";//ZH_WORDS_GETTER("addenterpriseClassificationName");//之后更改成yaml格式
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_