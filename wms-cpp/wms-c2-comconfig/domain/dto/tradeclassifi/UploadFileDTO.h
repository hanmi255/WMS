#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/03/11 17:03:38

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
#ifndef _UPLOADFILEDTO_
#define _UPLOADFILEDTO_
#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
*  id : 行业分类ID
   typecode : 行业分类代码
   typenames : 行业分类名称
   createname : 创建人
   createby : 创建人登录名称
   createdate : 创建日期
   sysorgcode : 所属部门
   syscompanycode : 所属公司
 */
class UploadFileDTO : public oatpp::DTO
{
	DTO_INIT(UploadFileDTO, DTO);
	// 行业分类ID
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("sample.chengfeng.id"));
	// 行业分类代码
	API_DTO_FIELD_DEFAULT(String, typecodes, ZH_WORDS_GETTER("sample.chengfeng.code"));
	// 行业分类名称
	API_DTO_FIELD_DEFAULT(String, typenames, ZH_WORDS_GETTER("sample.chengfeng.name"));
	// 创建人
	API_DTO_FIELD_DEFAULT(String, creadename, ZH_WORDS_GETTER("attrikq.remove-attri.field.createname"));
	// 创建人登录名称
	API_DTO_FIELD_DEFAULT(String, createby, ZH_WORDS_GETTER("attrikq.remove-attri.field.createby"));
	// 创建日期
	API_DTO_FIELD_DEFAULT(String, createdate, ZH_WORDS_GETTER("attrikq.remove-attri.field.createdate"));
	// 所属部门
	API_DTO_FIELD_DEFAULT(String, sysorgcode, ZH_WORDS_GETTER("attrikq.remove-attri.field.sysorgcode"));
	// 所属公司
	API_DTO_FIELD_DEFAULT(String, syscompanycode, ZH_WORDS_GETTER("attrikq.remove-attri.field.syscompanycode"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAM
