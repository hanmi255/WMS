#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: maomao
 @Date: 2025/2/24 11:10:36

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
#ifndef _DEFPLAT_DTO_
#define _DEFPLAT_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 月台定义模块 删除月台功能 数据对象，包含要显示的基本数据
 */
class DefDelDto : public oatpp::DTO
{
	DTO_INIT(DefDelDto, DTO);

	// 月台id
	API_DTO_FIELD_DEFAULT(String, id, "id");

};
/**
 * 月台定义模块 月台修改功能 数据对象，包含要显示的基本数据
 */
class DefEditDto : public oatpp::DTO
{
	DTO_INIT(DefEditDto, DTO);

	// 要修改的月台的id
	API_DTO_FIELD_DEFAULT(String, id, "id");
	//宏的第三项里面的内容要和第二项一致
	// 修改后的月台代码
	API_DTO_FIELD_DEFAULT(String, platform_code, "platform_code");

	// 修改后的月台名称
	API_DTO_FIELD_DEFAULT(String, platform_name, " platform_name");

};
/**
 * 月台定义模块 导出月台功能 数据对象，包含要显示的基本数据
 */
class DefPutDto : public oatpp::DTO
{
	DTO_INIT(DefPutDto, DTO);

	// 月台id
	API_DTO_FIELD_DEFAULT(String, id, "PlatformIP");

};

#include OATPP_CODEGEN_END(DTO)
#endif //_DEFPLAT_DTO_