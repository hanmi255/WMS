#pragma once

#ifndef _SHUXINGMAPPER_
#define _SHUXINGMAPPER_

#include "Mapper.h"
#include "../../domain/do/chanpingshuxing/ShuxingDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class ShuxingMapper : public Mapper<ShuxingDO>
{
public:
	ShuxingDO mapper(ResultSet* resultSet) const override
	{
		ShuxingDO data;
		 
		data.setGoods_type_code(resultSet->getString(1));
		data.setGoods_type_name(resultSet->getString(2));
		return data;
	}
};
 
#endif 