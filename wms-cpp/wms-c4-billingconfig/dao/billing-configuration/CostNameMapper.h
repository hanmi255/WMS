#pragma once
#ifndef _COST_NAME_MAPPER_
#define _COST_NAME_MAPPER_

#include "Mapper.h"
#include "../../domain/do/billing-configuration/CostNameDO.h"

/**
 * 费用名称映射器
 */
class CostNameMapper : public Mapper<CostNameDO>
{
public:
	CostNameDO mapper(ResultSet* resultSet) const override
	{
		CostNameDO data;
		data.setId(resultSet->getString(1));
		data.setCostCode(resultSet->getString(2));
		data.setCostName(resultSet->getString(3));
		data.setCostTypeCode(resultSet->getString(4));
		data.setCreateName(resultSet->getString(5));
		data.setCreateBy(resultSet->getString(6));
		data.setCreateDate(resultSet->getString(7));
		data.setUpdateName(resultSet->getString(8));
		data.setUpdateBy(resultSet->getString(9));
		data.setUpdateDate(resultSet->getString(10));
		data.setSysOrgCode(resultSet->getString(11));
		data.setSysCompanyCode(resultSet->getString(12));
		return data;
	}
};

/**
 * 费用名称映射器（指针类型）
 */
class PtrCostNameMapper : public Mapper<PtrCostNameDO>
{
public:
	PtrCostNameDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<CostNameDO>();
		data->setId(resultSet->getString(1));
		data->setCostCode(resultSet->getString(2));
		data->setCostName(resultSet->getString(3));
		data->setCostTypeCode(resultSet->getString(4));
		data->setCreateName(resultSet->getString(5));
		data->setCreateBy(resultSet->getString(6));
		data->setCreateDate(resultSet->getString(7));
		data->setUpdateName(resultSet->getString(8));
		data->setUpdateBy(resultSet->getString(9));
		data->setUpdateDate(resultSet->getString(10));
		data->setSysOrgCode(resultSet->getString(11));
		data->setSysCompanyCode(resultSet->getString(12));
		return data;
	}
};

#endif // !_COST_NAME_MAPPER_