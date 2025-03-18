#pragma once

#include "Mapper.h"
#include "../../domain/do/StoreDO.h"

//²Ö¿â×Ö¶ÎÆ¥ÅäÓ³Éä 

class StoreMapper : public Mapper<StoreDO>
{
public:
	StoreDO mapper(ResultSet* resultSet) const override
	{
		StoreDO data;
		data.setStoreCode(resultSet->getString(1));
		data.setStoreName(resultSet->getString(2));
		data.setStoreText(resultSet->getString(3));
		return data;
	}
};
