#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: Ann
 @Date: 2025/2/23 17:45
 
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

#ifndef _GOODCLASSDTO_H_
#define _GOODCLASSDTO_H_

#include "../../GlobalInclude.h"
// 

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 计费商品类基础传输对象（前端传入字段）
 */
class GoodsClassBaseAddDTO : public oatpp::DTO
{
	DTO_INIT(GoodsClassBaseAddDTO, oatpp::DTO);

	API_DTO_FIELD(String, name, ZH_WORDS_GETTER("goodsclass.filed.name"), true, "goodsclass-name");
	API_DTO_FIELD(String, code, ZH_WORDS_GETTER("goodsclass.filed.code"), true, "goodsclass-code");

};


/**
 * 计费商品类基础传输对象（前端传入字段）
 */
class GoodsClassBaseModifyDTO : public oatpp::DTO
{
	DTO_INIT(GoodsClassBaseModifyDTO, oatpp::DTO);

	API_DTO_FIELD(String, id, ZH_WORDS_GETTER("goodsclass.filed.id"), true, "12243185291950690304");
	API_DTO_FIELD(String, name, ZH_WORDS_GETTER("goodsclass.filed.name"), false, "goodsclass-name");
	API_DTO_FIELD(String, code, ZH_WORDS_GETTER("goodsclass.filed.code"), false, "goodsclass-code");
	API_DTO_FIELD(String, sysOrgCode, ZH_WORDS_GETTER("goodsclass.filed.sys_org_code"), false, "sys-org-code");
	API_DTO_FIELD(String, sysCompanyCode, ZH_WORDS_GETTER("goodsclass.filed.sys_company_code"), false, "sys-company-code");
};


/**
 * 修改计费商品类
 */
class GoodsClassModifyDTO : public oatpp::DTO
{
	DTO_INIT(GoodsClassModifyDTO, oatpp::DTO);

	// 操作ID
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("goodsclass.filed.id"));

	// 计费商品类名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("goodsclass.filed.name"));

	// 计费商品类编码
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("goodsclass.filed.code"));

	// 更新人名称
	API_DTO_FIELD_DEFAULT(String, update_name, ZH_WORDS_GETTER("goodsclass.filed.update_name"));

	// 更新人登录账号
	API_DTO_FIELD_DEFAULT(String, update_by, ZH_WORDS_GETTER("goodsclass.filed.update_by"));

	// 所属组织
	API_DTO_FIELD_DEFAULT(String, sys_org_code, ZH_WORDS_GETTER("goodsclass.filed.sys_org_code"));

	// 所属公司
	API_DTO_FIELD_DEFAULT(String, sys_company_code, ZH_WORDS_GETTER("goodsclass.filed.sys_company_code"));

	// 更新时间
	API_DTO_FIELD_DEFAULT(String, update_date, ZH_WORDS_GETTER("goodsclass.filed.update_date"));

	// 创建人名称
	API_DTO_FIELD_DEFAULT(String, create_name, ZH_WORDS_GETTER("goodsclass.filed.create_name"));

	// 创建人登录账号
	API_DTO_FIELD_DEFAULT(String, create_by, ZH_WORDS_GETTER("goodsclass.filed.create_by"));

	// 创建时间
	API_DTO_FIELD_DEFAULT(String, create_date, ZH_WORDS_GETTER("goodsclass.filed.create_date"));
};

/**
 * 计费商品类新增
 */

class GoodsClassAddDTO : public GoodsClassModifyDTO
{
	DTO_INIT(GoodsClassAddDTO, GoodsClassModifyDTO);
};



/**
 * 计费商品类名称列表（只包含名称）
 */
class GoodsClassNameListDTO : public oatpp::DTO
{
	DTO_INIT(GoodsClassNameListDTO, oatpp::DTO);

	// ID
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("goodsclass.filed.id"));
	// 计费商品类名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("goodsclass.filed.name"));
};

// 分页对象
class GoodsClassNameListPageDTO : public PageDTO<GoodsClassNameListDTO::Wrapper>
{
	DTO_INIT(GoodsClassNameListPageDTO, PageDTO<GoodsClassNameListDTO::Wrapper>);
};

/**
 * 计费商品类列表（包含ID和各属性）
 */
class GoodsClassDTO : public GoodsClassAddDTO
{
	DTO_INIT(GoodsClassDTO, GoodsClassAddDTO);

	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("goodsclass.filed.id"));
};

/**
 * 计费商品类分页列表（包含ID、名称以及各属性）
 */
class GoodsClassPageDTO : public PageDTO<GoodsClassDTO::Wrapper>
{
	DTO_INIT(GoodsClassPageDTO, PageDTO<GoodsClassDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_GOODCLASSDTO_H_