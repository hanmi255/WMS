/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/03/08 19:18:11

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
#include "stdafx.h"
#include "CompanyNameService.h"
#include "../../dao/companyattribute/CompanyNameDAO.h"

//获取行业名称
CompanyNameDTO::Wrapper CompanyNameService::getCompanyName()
{
	auto res = CompanyNameDTO::createShared();
	CompanyNameDAO dao;
	auto ans = dao.getCompanyName();
	for (const auto& i : ans) {
		res->id->push_back(i.getId());
		res->code->push_back(i.getCode());
		res->name->push_back(i.getName());
	}
	return res;
}


