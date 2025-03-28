#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/03/08 14:27:32

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
#ifndef _COMPANYNAMEDO_
#define _COMPANYNAMEDO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class CompanyNameDO
{
	// id
	CC_SYNTHESIZE(string, id, Id);
	// 编码
	CC_SYNTHESIZE(string, code, Code);
	// 名称
	CC_SYNTHESIZE(string, name, Name);
public:
	CompanyNameDO() {
		id = "";
		code = "";
		name = "";
	}
};

// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<CompanyNameDO> PtrCompanyNameDO;
#endif // !_SAMPLE_DO_
