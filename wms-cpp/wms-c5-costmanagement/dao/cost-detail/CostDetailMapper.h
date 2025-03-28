#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: epiphany
 @Date: 2025/3/5 23:30

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
#ifndef _COST_DETAIL_MAPPER_
#define _COST_DETAIL_MAPPER_

#include "Mapper.h"
#include "../../domain/do/public-do/DayCostDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class CostDetailMapper : public Mapper<DayCostDO>
{
public:
	DayCostDO mapper(ResultSet* resultSet) const override
	{
		DayCostDO data;
		data.setCreateName(resultSet->getString(1));
		data.setCreateDate(resultSet->getString(2));
		data.setUpdateName(resultSet->getString(3));
		data.setUpdateDate(resultSet->getString(4));
		data.setCusCode(resultSet->getString(5));
		data.setCusName(resultSet->getString(6));
		data.setCostCode(resultSet->getString(7));
		data.setCostName(resultSet->getString(8));
		data.setCostDate(resultSet->getString(9));
		data.setDayCostYj(resultSet->getString(10));
		data.setDayCostBhs(resultSet->getString(11));
		data.setDayCostSe(resultSet->getString(12));
		data.setDayCostHsj(resultSet->getString(13));
		data.setCostOri(resultSet->getString(14));
		data.setBeiZhu(resultSet->getString(15));
		data.setCostSta(resultSet->getString(16));
		data.setCostJs(resultSet->getString(17));
		data.setCostSl(resultSet->getString(18));
		data.setCostUnit(resultSet->getString(19));
		return data;
	}
};

#endif // !_COST_DETAIL_MAPPER_