#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: greent
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
#ifndef _COMPANYINFO_DO_
#define _COMPANYINFO_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class CompanyInfoDO
{
	//id号
	CC_SYNTHESIZE(string, id, Id);
	// 公司代码
	CC_SYNTHESIZE(string, companyid, CompanyId);
	// 公司中文简称
	CC_SYNTHESIZE(string, zhabbr, ZhAbbr);
	// 公司中文全称
	CC_SYNTHESIZE(string, zhful, ZhFul);
	// 中文地址
	CC_SYNTHESIZE(string, zhaddr, ZhAddr);
	// 公司英文简称
	CC_SYNTHESIZE(string, enabbr, EnAbbr);
	// 公司英文全称
	CC_SYNTHESIZE(string, enful, EnFul);
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
	CompanyInfoDO() {
		id = "";
		companyid = "";
		zhabbr = "";
		zhful = "";
		zhaddr = "";
		enabbr = "";
		enful = "";
		username = "";
		loginname = "";
		date = "";
		orgdept = "";
		orgcompany = "";
	}
};

// 给CompanyInfoDO智能指针设定一个别名方便使用
typedef std::shared_ptr<CompanyInfoDO> PtrCompanyInfoDO;
#endif 
