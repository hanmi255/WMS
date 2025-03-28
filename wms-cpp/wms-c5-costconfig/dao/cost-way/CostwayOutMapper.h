#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: tudou
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
#ifndef _COSTWAYOUT_MAPPER_
#define _COSTWAYOUT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/cost-way/CostwayDO.h"

/**
 * 示例表字段匹配映射
 */
class CostwayOutMapper : public Mapper<CostwayDO>
{
public:
	CostwayDO mapper(ResultSet* resultSet) const override
	{
		CostwayDO data;
		data.setPronut_code(resultSet->getString(1));
		data.setPronut_name(resultSet->getString(2));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrCostwayOutyMapper : public Mapper<PtrCostwayDO>
{
public:
	PtrCostwayDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<CostwayDO>();
		data->setPronut_code(resultSet->getString(1));
		data->setPronut_name(resultSet->getString(2));
		return data;
	}
};

#endif // !_COSTWAYOUT_MAPPER_
#pragma once
