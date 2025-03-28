#pragma once
/*
Copyright Zero One Star.All rights reserved.

@Author: z
@Date : 2025/2/22 10 : 01

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

https ://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#ifndef _ENTERPRISE_INFO_
#define _ENTERPRISE_INFO_
#include "DoInclude.h"

/** 
* ÐÞ¸ÄDO
*/
class EnterpriseDO
{
	
	CC_SYNTHESIZE(string, id, Id);
	CC_SYNTHESIZE(string, create_name, CreateName);
	CC_SYNTHESIZE(string, create_by, CreateBy);
	CC_SYNTHESIZE(string, create_date, CreateDate);
	CC_SYNTHESIZE(string, update_name, UpdateName);
	CC_SYNTHESIZE(string, update_by, UpdateBy);
	CC_SYNTHESIZE(string , update_date , UpdateDate);
	CC_SYNTHESIZE(string, sys_org_code, SysOrgCode);
	CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode);
	CC_SYNTHESIZE(string, com_type_code, ComTypeCode);
	CC_SYNTHESIZE(string, com_type_name, ComTypeName);
	CC_SYNTHESIZE(uint64_t, com_type_del, ComTypeDel);
public : 
	EnterpriseDO()
	{
		this->id = "0000";
		this->create_name = "";
		this->create_by = "";
		this->create_date = "";
		this->update_name = "";
		this->update_by = "";
		this->sys_company_code = "";
		this->sys_org_code = "";
		this->com_type_code = "";
		this->com_type_name = "";

		this->com_type_del = 0;
	}
};

#endif // !_ENTERPRISE_INFO_

