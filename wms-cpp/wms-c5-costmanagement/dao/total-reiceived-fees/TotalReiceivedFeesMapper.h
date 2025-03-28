#pragma once

#ifndef _TOTAL_MAPPER_
#define _TOTAL_MAPPER_
#include "domain/do/public-do/DayCostDO.h"

class TotalReiceivedFeesMapper :public Mapper<DayCostDO> {
public:
	DayCostDO mapper(ResultSet* resultSet)const override {
		DayCostDO data;
		data.setId(resultSet->getString(12));
		data.setCostDate(resultSet->getString(1));
		data.setCusCode(resultSet->getString(2));
		data.setCusName(resultSet->getString(3));
		data.setCostCode(resultSet->getString(4));
		data.setCostName(resultSet->getString(5));
		data.setCostSl(resultSet->getString(6));
		data.setCostUnit(resultSet->getString(7));
		data.setDayCostYj(resultSet->getString(8));
		data.setDayCostBhs(resultSet->getString(9));
		data.setDayCostSe(resultSet->getString(10));
		data.setDayCostHsj(resultSet->getString(11));
		return data;
	}
};


#endif // !_TOTAL_MAPPER_


