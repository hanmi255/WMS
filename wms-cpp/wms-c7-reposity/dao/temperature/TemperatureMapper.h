#pragma once
/*
 @Author:gutianxuan

*/
#ifndef _TEMPERATURE_MAPPER_
#define _TEMPERATURE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/temperature/TemperatureDO.h"

/**
 * 字段匹配映射
 */
class TemperatureDetailMapper : public Mapper<TemperatureDO>
{
public:
	TemperatureDO mapper(ResultSet* resultSet) const override
	{
		TemperatureDO data;
		data.setId(resultSet->getString(1));
		data.setCreate_Name(resultSet->getString(2));
		data.setCreate_By(resultSet->getString(3));
		data.setCreate_Date(resultSet->getString(4));
		data.setUpdate_Name(resultSet->getString(5));
		data.setUpdate_By(resultSet->getString(6));
		data.setUpdate_Date(resultSet->getString(7));
		data.setSys_Org_Code(resultSet->getString(8));
		data.setSys_Company_Code(resultSet->getString(9));
		data.setDeg_Type_Code(resultSet->getString(10));
		data.setDeg_Type_Name(resultSet->getString(11));
		return data;
	}
};


class PtrTemperatureDetailMapper : public Mapper<PtrTemperatureDO>
{
public:
	PtrTemperatureDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<TemperatureDO>();
		data->setId(resultSet->getString(1));
		data->setCreate_Name(resultSet->getString(2));
		data->setCreate_By(resultSet->getString(3));
		data->setCreate_Date(resultSet->getString(4));
		data->setUpdate_Name(resultSet->getString(5));
		data->setUpdate_By(resultSet->getString(6));
		data->setUpdate_Date(resultSet->getString(7));
		data->setSys_Org_Code(resultSet->getString(8));
		data->setSys_Company_Code(resultSet->getString(9));
		data->setDeg_Type_Code(resultSet->getString(10));
		data->setDeg_Type_Name(resultSet->getString(11));

		return data;
	}
};


class TemperatureNameMapper : public Mapper<TemperatureNameDO>
{
public:
	TemperatureNameDO mapper(ResultSet* resultSet) const override
	{
		TemperatureNameDO data;
		data.setId(resultSet->getString(1));
		data.setDeg_Type_Name(resultSet->getString(2));
		return data;
	}
};

class PtrTemperatureNameMapper : public Mapper<PtrTemperatureNameDO>
{
public:
	PtrTemperatureNameDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<TemperatureNameDO>();
		data->setId(resultSet->getString(1));
		data->setDeg_Type_Name(resultSet->getString(11));

		return data;
	}
};





class TemperatureMapper : public Mapper<TemperatureDO>
{
public:
	TemperatureDO mapper(ResultSet* resultSet) const override
	{
		TemperatureDO data;
		data.setId(resultSet->getString(1));
		data.setCreate_Name(resultSet->getString(2));
		data.setCreate_By(resultSet->getString(3));
		data.setCreate_Date(resultSet->getString(4));
		data.setUpdate_Name(resultSet->getString(5));
		data.setUpdate_By(resultSet->getString(6));
		data.setUpdate_Date(resultSet->getString(7));
		data.setSys_Org_Code(resultSet->getString(8));
		data.setSys_Company_Code(resultSet->getString(9));
		data.setDeg_Type_Code(resultSet->getString(10));
		data.setDeg_Type_Name(resultSet->getString(11));

		return data;
	}
};

class PtrTemperatureMapper : public Mapper<PtrTemperatureDO>
{
public:
	PtrTemperatureDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<TemperatureDO>();
		data->setId(resultSet->getString(1));
		data->setCreate_Name(resultSet->getString(2));
		data->setCreate_By(resultSet->getString(3));
		data->setCreate_Date(resultSet->getString(4));
		data->setUpdate_Name(resultSet->getString(5));
		data->setUpdate_By(resultSet->getString(6));
		data->setUpdate_Date(resultSet->getString(7));
		data->setSys_Org_Code(resultSet->getString(8));
		data->setSys_Company_Code(resultSet->getString(9));
		data->setDeg_Type_Code(resultSet->getString(10));
		data->setDeg_Type_Name(resultSet->getString(11));

		return data;
	}
};



#endif // !_TEMPERATURE_MAPPER_