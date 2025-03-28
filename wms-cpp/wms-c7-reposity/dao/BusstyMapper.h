#pragma once
#include "../lib-mysql/include/Mapper.h"
#include "../wms-c7-reposity/domain/do/ba_buss_typeDO.h"
/**
 * Ê¾Àı±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class BusstyMapper : public Mapper<ba_buss_typeDO>
{
public:
	ba_buss_typeDO mapper(ResultSet* resultSet) const override
	{
		ba_buss_typeDO data;
		data.setId(resultSet->getInt(1));
		data.setNum(resultSet->getString(2));
		data.setName(resultSet->getString(3));
		data.setDesc(resultSet->getString(4));
		return data;
	}
};