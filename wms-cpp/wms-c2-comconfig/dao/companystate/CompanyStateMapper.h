#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: greent
 @Date: 2025/2/23 22:21:34

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
#ifndef _COMPANYSTATE_MAPPER_
#define _COMPANYSTATE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/companystate/CompanyStateDO.h"

/**
 * 示例表字段匹配映射
 */
class CompanyStateMapper : public Mapper<CompanyStateDO>
{
public:
	CompanyStateDO mapper(ResultSet* resultSet) const override
	{
		CompanyStateDO data;
		data.setId(resultSet->getString(1));
		data.setClientName(resultSet->getString(2));
		data.setState(resultSet->getString(3));

		data.setClientId(resultSet->getString(7));
		data.setUserName(resultSet->getString(8));
		data.setLoginName(resultSet->getString(9));
		data.setDate(resultSet->getString(10));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrCompanyInfoMapper : public Mapper<PtrCompanyStateDO>
{
public:
	PtrCompanyStateDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<CompanyStateDO>();
		data->setId(resultSet->getString(1));
		data->setClientName(resultSet->getString(2));
		data->setState(resultSet->getString(3));
		data->setClientId(resultSet->getString(7));
		data->setUserName(resultSet->getString(8));
		data->setLoginName(resultSet->getString(9));
		data->setDate(resultSet->getString(10));
		return data;
	}
};

#endif // !_COMPANYINFO_MAPPER_