#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: yunyin

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
#ifndef _BUSINESS_LINK_DO_H_
#define _BUSINESS_LINK_DO_H_
#include "../DoInclude.h"


/**
	* 业务环节数据库实体类
	*/
class BusinessLinkDO
{
	using datetime = string;
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 创建人名称
	CC_SYNTHESIZE(string, create_name, CreateName);
	// 创建人登录名称
	CC_SYNTHESIZE(string, create_by, CreateBy);
	// 创建日期
	CC_SYNTHESIZE(datetime, create_date, CreateDate);
	// 更新人名称
	CC_SYNTHESIZE(string, update_name, UpdateName);
	// 更新人登录名称
	CC_SYNTHESIZE(string, update_by, UpdateBy);
	// 更新日期
	CC_SYNTHESIZE(datetime, update_date, UpdateDate);
	// 所属部门
	CC_SYNTHESIZE(string, sys_org_code, SysOrgCode);
	// 所属公司
	CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode);
	// 业务环节代码
	CC_SYNTHESIZE(string, oper_step_code, OperStepCode);
	// 业务环节名称
	CC_SYNTHESIZE(string, oper_step_name, OperStepName);
public:
	BusinessLinkDO() {
		id = "";
		create_name = "";
		create_by = "";
		create_date = "";
		update_name = "";
		update_by = "";
		update_date = "";
		sys_org_code = "";
		sys_company_code = "";
		oper_step_code = "";
		oper_step_name = "";
	}
};

using PtrBusinessLinkDO = std::shared_ptr<BusinessLinkDO>;

/*
* 业务环节表-业务名称
*/
class BusinessLinkNameDO
{
	// 业务环节名称
	CC_SYNTHESIZE(std::string, oper_step_name, OperStepName);
public:
	BusinessLinkNameDO() {
		oper_step_name = "";
	}
};

/*
* 业务环节表所需的用户表信息
*/
class UserDO
{
	// 用户名
	CC_SYNTHESIZE(string, realname, RealName);
	// 用户登录名
	CC_SYNTHESIZE(string, username, UserName);
	// 所属部门编码
	CC_SYNTHESIZE(string, departid, DepartId);
	// 所属公司编码
	CC_SYNTHESIZE(string, org_code, OrgCode);
public:
	UserDO() {
		realname = "";
		username = "";
		departid = "";
		org_code = "";
	}
};

using PtrUserDO = std::shared_ptr<UserDO>;



#endif // !_BUSINESS_LINK_DO_H_
