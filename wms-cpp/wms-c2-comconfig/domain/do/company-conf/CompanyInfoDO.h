#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/03/13 11:52:32

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
#ifndef _COMPANYINFODO_
#define _COMPANYINFODO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class CompanyInfoDO
{
	// 唯一代码
	CC_SYNTHESIZE(string, id, Id);
	//公司代码
	CC_SYNTHESIZE(string, code, Code);
	// 公司中文简称
	CC_SYNTHESIZE(string, zh_name, Zh_name);
	// 公司中文全称
	CC_SYNTHESIZE(string, zh_aname, Zh_aname);
	// 公司中文地址
	CC_SYNTHESIZE(string, zh_addr, Zh_addr);
	//公司英文简称
	CC_SYNTHESIZE(string, en_name, En_name);
	//公司英文全称
	CC_SYNTHESIZE(string, en_aname, En_aname);
public:
	CompanyInfoDO() {
		code = "";
		zh_name = "";
		zh_aname = "";
		zh_addr = "";
		en_name = "";
		en_aname = "";
	}
};

// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<CompanyInfoDO> PtrCompanyInfoDO;
#endif // !_SAMPLE_DO_

