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
#ifndef _MOVINGBIN_MAPPER_
#define _MOVINGBIN_MAPPER_

#include "Mapper.h"
#include "../../domain/do/moving-bin/MovingBinDO.h"

/**
 * 动仓盘点列表字段匹配映射
 */
class MovingBinMapper : public Mapper<MovingBinDO>
{
public:
	MovingBinDO mapper(ResultSet* resultSet) const override
	{
		MovingBinDO data;
		data.setId(resultSet->getString(1));
		data.setBinId(resultSet->getString(2));
		data.setTinId(resultSet->getString(3));
		data.setGoodsId(resultSet->getString(4));
		data.setGoodsName(resultSet->getString(5));
		//data.setGoodsSpecification(resultSet->getString(6));
		//data.setGoodsProDate(resultSet->getString(7));
		//data.setSaveDate(resultSet->getString(8));
		//data.setDueDate(resultSet->getString(9));
		//data.setTotalStock(resultSet->getString(10));
		//data.setLastPickTime(resultSet->getString(11));
		//data.setAvailStock(resultSet->getString(12));
		//data.setToBeTakenDown(resultSet->getString(13));
		//data.setGoodsUnit(resultSet->getString(14));
		return data;
	}
};

/**
 * 动仓盘点列表字段匹配映射-创建智能指针对象
 */
class PtrMovingBinMapper : public Mapper<PtrMovingBineDO>
{
public:
	PtrMovingBineDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<MovingBinDO>();
		data->setId(resultSet->getString(1));
		data->setBinId(resultSet->getString(2));
		data->setTinId(resultSet->getString(3));
		data->setGoodsId(resultSet->getString(4));
		data->setGoodsName(resultSet->getString(5));
		//data->setGoodsSpecification(resultSet->getString(6));
		//data->setGoodsProDate(resultSet->getString(7));
		//data->setSaveDate(resultSet->getString(8));
		//data->setDueDate(resultSet->getString(9));
		//data->setTotalStock(resultSet->getString(10));
		//data->setLastPickTime(resultSet->getString(11));
		//data->setAvailStock(resultSet->getString(12));
		//data->setToBeTakenDown(resultSet->getString(13));
		//data->setGoodsUnit(resultSet->getString(14));
		return data;
	}
};

#endif // !_MOVINGBIN_MAPPER_