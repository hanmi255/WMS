#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: killerqueen
 @Date: 2025/2/24 11:21:55

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
#ifndef _ATTRIINFO_MAPPER_
#define _ATTRIINFO_MAPPER_

#include "Mapper.h"
#include "../../domain/do/companyattributes/AttriInfoDO.h"

/**
 * 示例表字段匹配映射
 */
class AttriInfoMapper : public Mapper<AttriInfoDO>
{
public:
	AttriInfoDO mapper(ResultSet* resultSet) const override
	{
		AttriInfoDO data;
		data.setID(resultSet->getString(1)); 
		data.setCreateName(resultSet->getString(2));
		data.setCreateBy(resultSet->getString(3));
		data.setCreateDate(resultSet->getString(4));
		data.setSysorgCode(resultSet->getString(5));
		data.setSysCompanyCode(resultSet->getString(6));
		data.setTypeCode(resultSet->getString(7));
		data.setTypeNames(resultSet->getString(8));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrSampleMapper : public Mapper<PtrAttriInfoDO>
{
public:
	PtrAttriInfoDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<AttriInfoDO>();
		data->setID(resultSet->getString(1));
		data->setCreateName(resultSet->getString(2));
		data->setCreateBy(resultSet->getString(3));
		data->setCreateDate(resultSet->getString(4));
		data->setSysorgCode(resultSet->getString(5));
		data->setSysCompanyCode(resultSet->getString(6));
		data->setTypeCode(resultSet->getString(7));
		data->setTypeNames(resultSet->getString(8));
		return data;
	}
};

#endif // !_SAMPLE_MAPPE
