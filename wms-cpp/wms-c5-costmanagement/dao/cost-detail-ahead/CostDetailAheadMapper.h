#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: whx
 @Date: 2025/3/5 14:23:49

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
#ifndef _COSTDETAILAHEAD_MAPPER_
#define _COSTDETAILAHEAD_MAPPER_

#include "Mapper.h"
#include "../../domain/do/public-do/DayCostDO.h"



/**
 * 示例表字段匹配映射
 */
class CostDetailMapper : public Mapper<DayCostDO>
{
public:
	DayCostDO mapper(ResultSet* resultSet) const override
	{
		DayCostDO data;
		data.setId(resultSet->getString(1));
		data.setCreateName(resultSet->getString(2));
		data.setCreateBy(resultSet->getString(3));
		data.setCreateDate(resultSet->getString(4));
		data.setUpdateName(resultSet->getString(5));
		data.setUpdateBy(resultSet->getString(6));
		data.setUpdateDate(resultSet->getString(7));
		data.setSysOrgCode(resultSet->getString(8));
		data.setSysCompanyCode(resultSet->getString(9));
		data.setCusCode(resultSet->getString(10));
		data.setCusName(resultSet->getString(11));
		data.setCostCode(resultSet->getString(12));
		data.setCostName(resultSet->getString(13));
		data.setCostDate(resultSet->getString(14));
		data.setDayCostYj(resultSet->getString(15));
		data.setDayCostBhs(resultSet->getString(16));
		data.setDayCostSe(resultSet->getString(17));
		data.setDayCostHsj(resultSet->getString(18));
		data.setCostOri(resultSet->getString(19));
		data.setBeiZhu(resultSet->getString(20));
		data.setCostSta(resultSet->getString(21));
		data.setCostSl(resultSet->getString(22));
		data.setCostUnit(resultSet->getString(23));
		data.setCostJs(resultSet->getString(24));
	

		return data;
	}
};


/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrCostDetailMapper : public Mapper<PtrDayCostDO>
{
public:
	PtrDayCostDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<DayCostDO>();
		data->setId(resultSet->getString(1));
		data->setCreateName(resultSet->getString(2));
		data->setCreateBy(resultSet->getString(3));
		data->setCreateDate(resultSet->getString(4));
		data->setUpdateName(resultSet->getString(5));
		data->setUpdateBy(resultSet->getString(6));
		data->setUpdateDate(resultSet->getString(7));
		data->setSysOrgCode(resultSet->getString(8));
		data->setSysCompanyCode(resultSet->getString(9));
		data->setCusCode(resultSet->getString(10));
		data->setCusName(resultSet->getString(11));
		data->setCostCode(resultSet->getString(12));
		data->setCostName(resultSet->getString(13));
		data->setCostDate(resultSet->getString(14));
		data->setDayCostYj(resultSet->getString(15));
		data->setDayCostBhs(resultSet->getString(16));
		data->setDayCostSe(resultSet->getString(17));
		data->setDayCostHsj(resultSet->getString(18));
		data->setCostOri(resultSet->getString(19));
		data->setBeiZhu(resultSet->getString(20));
		data->setCostSta(resultSet->getString(21));
		data->setCostSl(resultSet->getString(22));
		data->setCostUnit(resultSet->getString(23));
		data->setCostJs(resultSet->getString(24));
		return data;
	}
};

#endif // !_COSTDETAILAHEAD_MAPPER_