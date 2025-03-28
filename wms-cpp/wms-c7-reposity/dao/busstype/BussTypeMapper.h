#pragma once
#ifndef _BUSSTYPE_MAPPER_
#define _BUSSTYPE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/busstype/BussTypeDO.h"

/**
 * ba_buss_type表字段匹配映射
 */
class BussTypeMapper : public Mapper<BussTypeDO>
{
public:
	BussTypeDO mapper(ResultSet* resultSet) const override
	{
		BussTypeDO data;
		data.setId(resultSet->getString(1));
		data.setBussTypeCode(resultSet->getString(2));
		data.setBussTypeName(resultSet->getString(3));
		data.setBussTypeText(resultSet->getString(4));
		return data;
	}
};
/**
 * ba_buss_type字段匹配映射-创建智能指针对象
 */
class PtrBussTypeMapper : public Mapper<PtrBussTypeDO>
{
public:
	PtrBussTypeDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<BussTypeDO>();
		data->setId(resultSet->getString(1));
		data->setBussTypeCode(resultSet->getString(2));
		data->setBussTypeName(resultSet->getString(3));
		data->setBussTypeText(resultSet->getString(4));
		return data;
	}
};

#endif // !BUSSTYPE_MAPPER