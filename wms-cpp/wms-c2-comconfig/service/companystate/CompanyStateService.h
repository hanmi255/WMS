#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: fycc
 @Date: 2025/2/23 21:10:33

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
#ifndef _COMPANYSTATE_SERVICE_
#define _COMPANYSTATE_SERVICE_
#include <list>
#include "domain/vo/companystate/CompanyStateVO.h"
#include "domain/dto/companystate/CompanyStateDTO.h"
#include "domain/do/companystate/CompanyStateDO.h"
#include "dao/companystate/CompanyStateDAO.h"


class CompanyStateService
{
public:
	// ±£´æÊý¾Ý
	uint64_t saveData(const CompanyAddStateDTO::Wrapper& dto, const PayloadDTO& payload);

	bool updateData(const CompanyUpdateStateDTO::Wrapper& dto, const PayloadDTO& payload);

	bool removeData1(vector<string>&& id);
};

#endif