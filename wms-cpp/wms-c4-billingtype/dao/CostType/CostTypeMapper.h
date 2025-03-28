#pragma once
#ifndef _COST_TYPE_MAPPER_
#define _COST_TYPE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/CostType/CostTypeDO.h"

/**
 * 示例表字段匹配映射
 */
class CostTypeMapper : public Mapper<CostTypeDO>
{
public:
	CostTypeDO mapper(ResultSet* resultSet) const override
	{
		CostTypeDO data; 
		data.setId(resultSet->getUInt64(1));
		data.setCost_code(resultSet->getString(2));
		data.setCost_name(resultSet->getString(3));
		data.setCost_type(resultSet->getString(4));
		data.setCreate_name(resultSet->getString(5));
		data.setCreate_date(resultSet->getString(6));
		data.setUpdate_name(resultSet->getString(7));
		data.setUpdate_date(resultSet->getString(8));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrCostTypeMapper : public Mapper<PtrCostTypeDO>
{
public:
	PtrCostTypeDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<CostTypeDO>();
		data->setId(resultSet->getUInt64(1));
		data->setCost_code(resultSet->getString(2));
		data->setCost_name(resultSet->getString(3));
		data->setCost_type(resultSet->getString(4));
		data->setCreate_name(resultSet->getString(5));
		data->setCreate_date(resultSet->getString(6));
		data->setUpdate_name(resultSet->getString(7));
		data->setUpdate_date(resultSet->getString(8));
		return data;
	}
};

#endif // !_COST_TYPE_MAPPER_