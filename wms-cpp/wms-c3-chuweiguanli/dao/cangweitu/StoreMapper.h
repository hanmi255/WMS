#pragma once
#ifndef _STORE_MAPPER_
#define _STORE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/WvDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class StoreMapper : public Mapper<WvDO>
{
public:
	WvDO mapper(ResultSet* resultSet) const override
	{
		WvDO data;
		data.setBinStore(resultSet->getString(1));
		data.setBinId(resultSet->getString(2));
		data.setZnode(resultSet->getString(3));
		data.setXnode(resultSet->getString(4));
		data.setYnode(resultSet->getString(5));
		data.setColour(resultSet->getString(6));
		data.setTincount(resultSet->getString(7));
		return data;
	}
};



#endif // !_STORE_MAPPER_