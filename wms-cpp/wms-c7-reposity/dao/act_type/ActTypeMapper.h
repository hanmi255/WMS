#pragma once
#ifndef _ACTTYPEMAPPER_H_
#define _ACTTYPEMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/act_type/ActTypeDO.h"

/**
 * ba_act_type表字段匹配映射
 */
class ActTypeMapper : public Mapper<ActTypeDO>
{
public:
	ActTypeDO mapper(ResultSet* resultSet) const override
	{
		ActTypeDO data;
		data.setId(resultSet->getString(1));
		data.setActTypeCode(resultSet->getString(2));
		data.setActTypeName(resultSet->getString(3));
		data.setOperStepCode(resultSet->getString(4));
		return data;
	}
};

/**
 * ba_act_type表字段匹配映射-创建智能指针对象
 */
class PtrActTypeMapper : public Mapper<PtrActTypeDO>
{
public:
	PtrActTypeDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<ActTypeDO>();
		data->setId(resultSet->getString(1));
		data->setActTypeCode(resultSet->getString(2));
		data->setActTypeName(resultSet->getString(3));
		data->setOperStepCode(resultSet->getString(4));
		return data;
	}
};

#endif // !_ACTTYPEMAPPER_H_
