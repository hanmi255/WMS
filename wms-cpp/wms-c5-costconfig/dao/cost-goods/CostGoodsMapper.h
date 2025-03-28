#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Jane
 @Date: 2025/03/05 14:21:55

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
#ifndef _COSTGOODS_MAPPER_
#define _COSTGOODS_MAPPER_

#include "Mapper.h"
#include "domain/do/public-do/GoodsClassDO.h"

/**
 * 示例表字段匹配映射
 */
class CostGoodsMapper : public Mapper<GoodsClassDO>
{
public:
	GoodsClassDO mapper(ResultSet* resultSet) const override
	{
		GoodsClassDO data;
		data.setGoodsClassCode(resultSet->getString(1));
		data.setGoodsClassName(resultSet->getString(2));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrSampleMapper : public Mapper<PtrGoodsClassDO>
{
public:
	PtrGoodsClassDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<GoodsClassDO>();
		data->setGoodsClassCode(resultSet->getString(1));
		data->setGoodsClassName(resultSet->getString(2));
		return data;
	}
};

#endif // !_COSTGOOD_MAPPER_