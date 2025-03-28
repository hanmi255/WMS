#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: wrzljrj
 @Date: 2025/02/22 17:34:28

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

#ifndef _COSTSX_DTO_
#define _COSTSX_DTO_

#include "../../GlobalInclude.h"
#include "domain/query/cost-attribute/CostSxQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * 客户计费属性基础传输对象（前端传入字段）
 */
class CostSxBaseAddDTO : public oatpp::DTO
{
	DTO_INIT(CostSxBaseAddDTO, oatpp::DTO);

	API_DTO_FIELD(String, name, ZH_WORDS_GETTER("CostSxQuery.filed.name"), true, "attribute-name");
	API_DTO_FIELD(String, code, ZH_WORDS_GETTER("CostSxQuery.filed.code"), true, "attribute-code");
	/*API_DTO_FIELD(String, sysOrgCode, ZH_WORDS_GETTER("CostSxQuery.filed.sys_org_code"), true, "sys-org-code");
	API_DTO_FIELD(String, sysCompanyCode, ZH_WORDS_GETTER("CostSxQuery.filed.sys_company_code"), true, "sys-company-code");*/
};

/**
 * 客户计费属性基础传输对象（前端传入字段）
 */
class CostSxBaseModifyDTO : public oatpp::DTO
{
	DTO_INIT(CostSxBaseModifyDTO, oatpp::DTO);

	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("CostSxQuery.filed.id"), true, "12243185291950690304");
	API_DTO_FIELD(String, name, ZH_WORDS_GETTER("CostSxQuery.filed.name"), false, "attribute-name");
	API_DTO_FIELD(String, code, ZH_WORDS_GETTER("CostSxQuery.filed.code"), false, "attribute-code");
	//API_DTO_FIELD(String, sysOrgCode, ZH_WORDS_GETTER("CostSxQuery.filed.sys_org_code"), false, "sys-org-code");
	//API_DTO_FIELD(String, sysCompanyCode, ZH_WORDS_GETTER("CostSxQuery.filed.sys_company_code"), false, "sys-company-code");
};



/**
 * 修改客户计费属性
 */
class CostSxModifyDTO : public oatpp::DTO
{
	DTO_INIT(CostSxModifyDTO, oatpp::DTO);

	// 操作ID
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("CostSxQuery.filed.id"));

	// 客户属性名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("CostSxQuery.filed.name"));

	// 客户属性编码
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("CostSxQuery.filed.code"));

   // 更新人名称
	API_DTO_FIELD_DEFAULT(String, update_name, ZH_WORDS_GETTER("CostSxQuery.filed.update_name"));

	// 更新人登录账号
	API_DTO_FIELD_DEFAULT(String, update_by, ZH_WORDS_GETTER("CostSxQuery.filed.update_by"));

	// 所属组织
	API_DTO_FIELD_DEFAULT(String, sys_org_code, ZH_WORDS_GETTER("CostSxQuery.filed.sys_org_code"));

	// 所属公司
	API_DTO_FIELD_DEFAULT(String, sys_company_code, ZH_WORDS_GETTER("CostSxQuery.filed.sys_company_code"));

	// 更新时间
	API_DTO_FIELD_DEFAULT(String, update_date, ZH_WORDS_GETTER("CostSxQuery.filed.update_date"));

	// 创建人名称
	API_DTO_FIELD_DEFAULT(String, create_name, ZH_WORDS_GETTER("CostSxQuery.filed.create_name"));

	// 创建人登录账号
	API_DTO_FIELD_DEFAULT(String, create_by, ZH_WORDS_GETTER("CostSxQuery.filed.create_by"));

   // 创建时间
	API_DTO_FIELD_DEFAULT(String, create_date, ZH_WORDS_GETTER("CostSxQuery.filed.create_date"));
};

/**
 * 客户属性新增
 */

class CostSxAddDTO : public CostSxModifyDTO
{
	DTO_INIT(CostSxAddDTO, CostSxModifyDTO);
};



/**
 * 客户计费属性名称列表（只包含名称）
 */
class CostSxNameListDTO : public oatpp::DTO
{
	DTO_INIT(CostSxNameListDTO, oatpp::DTO);

	// ID
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("CostSxQuery.filed.id"));
	// 客户属性名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("CostSxQuery.filed.name"));
};

template <class T>
class CostSxNameDTO : public oatpp::DTO
{
	// 初始化
	DTO_INIT(CostSxNameDTO, DTO);
	DTO_FIELD(List<T>, rows) = {};
	DTO_FIELD_INFO(rows) {

		info->description = "page data list";

	}
public:
	CostSxNameDTO() {
		
	}
	// 初始化所有内容
	void initAll( List<T> rows) {
		this->rows = rows;
	}
	// 添加一条数据
	void addData(T one) {
		this->rows->push_back(one);
	}
};

// 分页对象
class CostSxNameListPageDTO : public CostSxNameDTO<CostSxNameListDTO::Wrapper>
{
	DTO_INIT(CostSxNameListPageDTO, CostSxNameDTO<CostSxNameListDTO::Wrapper>);
};

/**
 * 客户计费属性列表（包含ID和各属性）
 */
class CostSxDTO : public CostSxAddDTO
{
	DTO_INIT(CostSxDTO, CostSxAddDTO);

	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("CostSxQuery.filed.id"));
};

/**
 * 客户计费属性分页列表（包含ID、名称以及各属性）
 */
class CostSxPageDTO : public PageDTO<CostSxDTO::Wrapper>
{
	DTO_INIT(CostSxPageDTO, PageDTO<CostSxDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_COSTSX_DTO_