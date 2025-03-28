#pragma once

#ifndef _CostSum_MAPPER_
#define _CostSum_MAPPER_

#include "Mapper.h"
#include "../../domain/do/CostSumDO.h"
#endif

class CostSumMapper : public Mapper<CostSumDO>
{
public:
	CostSumDO mapper(ResultSet* resultSet) const override
	{
		CostSumDO data;
		data.setcost_date(resultSet->getString(1));
		data.setclient_c(resultSet->getString(2));
		data.setclient_name(resultSet->getString(3));
		data.setcost_c(resultSet->getString(4));
		data.setcost_name(resultSet->getString(5));
		data.setNumber(resultSet->getString(6));
		data.setUnit(resultSet->getString(7));
		data.setorg_price(resultSet->getString(8));
		data.setno_tax(resultSet->getString(9));
		data.setTax(resultSet->getString(10));
		data.settax_price(resultSet->getString(11));
		
		return data;
	}
};


