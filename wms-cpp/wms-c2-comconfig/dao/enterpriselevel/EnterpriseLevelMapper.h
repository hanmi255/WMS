#pragma once
#ifndef _ENTERPRISELEVEL_MAPPER_
#define _ENTERPRISELEVEL_MAPPER_

#include "Mapper.h"
#include "../../domain/do/customerlevel/ba_com_degDO.h"

/**
 * 示例表字段匹配映射
 */
class EnterpriseLevelMapper : public Mapper<CustomerLevelDO>
{
public:
	CustomerLevelDO mapper(ResultSet* resultSet) const override
	{
		CustomerLevelDO data;
		data.setName(resultSet->getString(1));
		data.setCode(resultSet->getString(2));
		data.setId(resultSet->getString(3));
		data.setBan(resultSet->getString(4));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrEnterpriseLevelMapper : public Mapper<PtrCustomerLevelDO>
{
public:
	PtrCustomerLevelDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<CustomerLevelDO>();
		data->setName(resultSet->getString(1));
		data->setCode(resultSet->getString(2));
		data->setId(resultSet->getString(3));
		data->setBan(resultSet->getString(4));

		return data;
	}
};

#endif // !_ENTERPRISELEVEL_MAPPER_