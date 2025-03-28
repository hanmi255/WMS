#pragma once
/*
 @Author: 002
 @Date: 2025.3.7
*/
#ifndef _CITY_TYPE_MAPPER_
#define _CITY_TYPE_MAPPER_

#include "Mapper.h"
#include "domain/do/citytype/CityTypeDO.h"

class CityTypeBaseMapper : public Mapper<CityTypeBaseDO>
{
public:
	CityTypeBaseDO mapper(ResultSet* resultSet) const override
	{
		CityTypeBaseDO data;
		data.setCode(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		return data;
	}
};

class CityTypeMapper : public Mapper<CityTypeDO>
{
public:
	CityTypeDO mapper(ResultSet* resultSet) const override
	{
		CityTypeDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setCode(resultSet->getString(3));
		return data;
	}
};

class CityTypeNameMapper : public Mapper<CityTypeNameDO>
{
public:
	CityTypeNameDO mapper(ResultSet* resultSet) const override
	{
		CityTypeNameDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		return data;
	}
};

#endif 