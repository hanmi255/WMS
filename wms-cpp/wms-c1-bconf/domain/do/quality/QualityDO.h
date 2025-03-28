#pragma once
/*
 @Author: S4turday
 @Date: 2025年3月8日15:40:17

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
#ifndef _QUALITY_DO_
#define _QUALITY_DO_
#include "../DoInclude.h"

/**
 * 品质代码数据库实体类
 */
class QualityDO
{
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 创建人名称
	CC_SYNTHESIZE(string, create_name, Create_Name);
	// 创建人登录名称
	CC_SYNTHESIZE(string, create_by, Create_By);
	// 创建时间
	CC_SYNTHESIZE(string, create_date, Create_Date);
	// 更新人名称
	CC_SYNTHESIZE(string, update_name, Update_Name);
	// 更新人登录名称
	CC_SYNTHESIZE(string, update_by, Update_By);
	// 更新时间
	CC_SYNTHESIZE(string, update_date, Update_Date);
	// 品质代码名称
	CC_SYNTHESIZE(string, qm_qa_name, Name);
	// 品质代码
	CC_SYNTHESIZE(string, qm_qa_code, Code);
	// 所属部门
	CC_SYNTHESIZE(string, sys_org_code, Sys_Org_Code);
	// 所属公司
	CC_SYNTHESIZE(string, sys_company_code, Sys_Company_Code);	
public:
	QualityDO() {
		id = "";
		qm_qa_name = "";
		qm_qa_code = "";
	}
};

// 给QualityDO智能指针设定一个别名方便使用
typedef std::shared_ptr<QualityDO> PtrQualityDO;
#endif // !_QUALITY_DO_
