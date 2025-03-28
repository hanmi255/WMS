#pragma once

/*
 Copyright Zero One Star. All rights reserved.

 @Author: tudou
 @Date: 2022/10/25 11:52:32

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
#ifndef _COSTWAY_DO_
#define _COSTWAY_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class CostwayDO
{
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 计费方式代码
	CC_SYNTHESIZE(string, pronut_code, Pronut_code);
	// 计费方式名称
	CC_SYNTHESIZE(string, pronut_name, Pronut_name);
	CC_SYNTHESIZE(string, create_name, Create_name);
	CC_SYNTHESIZE(string, create_by, Create_by);
	CC_SYNTHESIZE(string, create_date, Create_date);
	CC_SYNTHESIZE(string, update_name, Update_name);
	CC_SYNTHESIZE(string, update_by, Update_by);
	CC_SYNTHESIZE(string, update_date, Update_date);
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	CC_SYNTHESIZE(string, sys_company_code, Sys_company_code);

public:
	CostwayDO() {
		id = "";
		pronut_code = "";
		pronut_name = "";
		create_name = "";
		create_by = "";
		create_date = "";
		update_name = "";
		update_by = "";
		update_date = "";
		sys_org_code = "";
		sys_company_code = "";
	}
};

// 给CostwayDO智能指针设定一个别名方便使用
typedef std::shared_ptr<CostwayDO> PtrCostwayDO;
typedef CostwayDO MethodDO;
#endif // _COSTWAY_DO_
