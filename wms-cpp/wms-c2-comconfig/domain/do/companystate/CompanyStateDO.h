#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: fycc
 @Date: 2025/2/23 20:50:21

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
#ifndef _COMPANYSTATE_DO_
#define _COMPANYSTATE_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class CompanyStateDO
{
	//id号
	CC_SYNTHESIZE(string, id, Id);
	// 客户代码
	CC_SYNTHESIZE(string, clientid, ClientId);
	// 客户名称
	CC_SYNTHESIZE(string, clientname, ClientName);
	// 装态
	CC_SYNTHESIZE(string, state, State);

	//payload相关大礼包
	//用户名称
	CC_SYNTHESIZE(string, username, UserName);
	//用户登录名称
	CC_SYNTHESIZE(string, loginname, LoginName);
	//日期
	CC_SYNTHESIZE(string, date, Date);
	//所属部门
	CC_SYNTHESIZE(string, orgdept, OrgDept);
	//所属公司
	CC_SYNTHESIZE(string, orgcompany, OrgCompany);
public:
	CompanyStateDO() {
		id = "";
		clientid = "";
		clientname = "";
		state = "";

		username = "";
		loginname = "";
		date = "";
		orgdept = "";
		orgcompany = "";
	}
};

// 给CompanyInfoDO智能指针设定一个别名方便使用
typedef std::shared_ptr<CompanyStateDO> PtrCompanyStateDO;
#endif 
