#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Jane
 @Date: 2025/2/22 11:36:29

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
#ifndef _BILLINGPRODUCTCATEGORY_QUERY_
#define _BILLINGPRODUCTCATEGORY_QUERY_

#include "domain/GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 计费商品类查询对象
 */
class BillingProductCategoryQuery : public PageQuery
{
	DTO_INIT(BillingProductCategoryQuery, PageQuery);
	// 计费商品类代码
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("BillingProductCategoryQuery.way.code"));
	// 计费商品类编码
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("BillingProductCategoryQuery.way.name"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_BILLINGPRODUCTCATEGORY_QUERY_