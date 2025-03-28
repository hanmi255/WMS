#pragma once
#ifndef _ENTERPRISESTATUS_MAPPER_
#define _ENTERPRISESTATUS_MAPPER_

#include "Mapper.h"
#include "../../domain/do/enterprise-status/ba_cus_staDO.h"

/**
 * 示例表字段匹配映射
 */
class EnterpriseStatusMapper : public Mapper<CustomerStatusDO>
{
public:
	CustomerStatusDO mapper(ResultSet* resultSet) const override
	{
		CustomerStatusDO data;
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
class PtrEnterpriseStatusMapper : public Mapper<PtrCustomerStatusDO>
{
public:
	PtrCustomerStatusDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<CustomerStatusDO>();
		data->setName(resultSet->getString(1));
		data->setCode(resultSet->getString(2));
		data->setId(resultSet->getString(3));
		data->setBan(resultSet->getString(4));

		return data;
	}
};

#endif // !_ENTERPRISESTATUS_MAPPER_