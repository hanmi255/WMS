#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:21:55

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
#ifndef _costtype_MAPPER_
#define _costtype_MAPPER_

#include "Mapper.h"
#include "../../domain/do/costtype/costtypeDO.h"

/**
 * 示例表字段匹配映射
 */
class costtypeMapper : public Mapper<costtypeDO>
{
public:
	costtypeDO mapper(ResultSet* resultSet) const override
	{
		costtypeDO data;
		data.setId(resultSet->getUInt64(1));
		data.setName(resultSet->getString(2));
		data.setSex(resultSet->getString(3));
		data.setAge(resultSet->getInt(4));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrcosttypeMapper : public Mapper<PtrcosttypeDO>
{
public:
	PtrcosttypeDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<costtypeDO>();
		data->setId(resultSet->getUInt64(1));
		data->setName(resultSet->getString(2));
		data->setSex(resultSet->getString(3));
		data->setAge(resultSet->getInt(4));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_