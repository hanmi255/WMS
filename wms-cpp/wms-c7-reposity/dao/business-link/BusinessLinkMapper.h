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
#ifndef _BUSINESS_LINK_MAPPER_H_
#define _BUSINESS_LINK_MAPPER_H_

#include "Mapper.h"
#include"../../domain/do/bussiness-link/BusinessLinkDO.h"

/**
 * 业务环节表字段匹配映射
 */

class BusinessLinkMapper : public Mapper<BusinessLinkDO>
{
public:
	BusinessLinkDO mapper(ResultSet* resultSet) const override
	{
		BusinessLinkDO data;
		data.setId(resultSet->getString(1));
		data.setCreateName(resultSet->getString(2));
		data.setCreateBy(resultSet->getString(3));
		data.setCreateDate(resultSet->getString(4));
		data.setUpdateName(resultSet->getString(5));
		data.setUpdateBy(resultSet->getString(6));
		data.setUpdateDate(resultSet->getString(7));
		data.setSysOrgCode(resultSet->getString(8));
		data.setSysCompanyCode(resultSet->getString(9));
		data.setOperStepCode(resultSet->getString(10));
		data.setOperStepName(resultSet->getString(11));
		return data;
	}
};

/**
	* 业务环节表字段匹配映射-创建智能指针对象
	*/
class PtrBusinessLinkMapper : public Mapper<PtrBusinessLinkDO>
{
public:
	PtrBusinessLinkDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<BusinessLinkDO>();
		data->setId(resultSet->getString(1));
		data->setCreateName(resultSet->getString(2));
		data->setCreateBy(resultSet->getString(3));
		data->setCreateDate(resultSet->getString(4));
		data->setUpdateName(resultSet->getString(5));
		data->setUpdateBy(resultSet->getString(6));
		data->setUpdateDate(resultSet->getString(7));
		data->setSysOrgCode(resultSet->getString(8));
		data->setSysCompanyCode(resultSet->getString(9));
		data->setOperStepCode(resultSet->getString(10));
		data->setOperStepName(resultSet->getString(11));
		return data;
	}
};


/**
	* 业务环节表-业务名称映射
	*/
class BusinessLinkNameMapper : public Mapper<BusinessLinkNameDO>
{
public:
	BusinessLinkNameDO mapper(ResultSet* resultSet) const override
	{
		BusinessLinkNameDO data;
		data.setOperStepName(resultSet->getString(1));
		return data;
	}
};


#endif // !_BUSINESS_LINK_MAPPER_H_