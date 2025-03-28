#pragma once
#ifndef _PRODUCT_MAPPER_
#define _PRODUCT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/goodcategory/ProductDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class ProductMapper : public Mapper<ProductDO>
{
public:
	ProductDO mapper(ResultSet* resultSet) const override
	{
		ProductDO data;
		data.setCategorynum(resultSet->getString(1));
		data.setCategoryname(resultSet->getString(2));
		data.setCategorylevel(resultSet->getInt(3));
		data.setPID(resultSet->getInt(4));
		data.setTopnode(resultSet->getString(5));
		return data;
	}
};
#endif // !_PRODUCT_MAPPER_