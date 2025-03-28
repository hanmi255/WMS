#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: Ann
 @Date: 2025/2/23 17:44
 
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


#ifndef _GOODCLASSQUERY_H_
#define _GOODCLASSQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * 定义一个查询用户信息的数据传输模型
 */
class GoodClassQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(GoodClassQuery, PageQuery);

	// 计费商品类代码
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("goodsclass.field.code"));

	// 计费商品类名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("goodsclass.field.name"));

	// 创建人名称
	API_DTO_FIELD_DEFAULT(String, createName, ZH_WORDS_GETTER("goodsclass.field.create_name"));

	// 创建人ID
	API_DTO_FIELD_DEFAULT(String, createBy, ZH_WORDS_GETTER("goodsclass.field.create_by"));

	// 更新人名称
	API_DTO_FIELD_DEFAULT(String, updateName, ZH_WORDS_GETTER("goodsclass.field.update_name"));

	// 更新人ID
	API_DTO_FIELD_DEFAULT(String, updateBy, ZH_WORDS_GETTER("goodsclass.field.update_by"));

	// 所属组织编码
	API_DTO_FIELD_DEFAULT(String, sysOrgCode, ZH_WORDS_GETTER("goodsclass.field.sys_org_code"));

	// 所属公司编码
	API_DTO_FIELD_DEFAULT(String, sysCompanyCode, ZH_WORDS_GETTER("goodsclass.field.sys_company_code"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GOODCLASSQUERY_H_
