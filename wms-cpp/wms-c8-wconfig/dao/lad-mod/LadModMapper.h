#pragma once

#ifndef _LADMOD_MAPPER_
#define _LADMOD_MAPPER_

#include "Mapper.h"
#include "../../domain/do/lad-mod/LadModDO.h"

/**
 * 字段匹配映射
 */
class LadModMapper : public Mapper<LadModDO>
{
public:
	LadModDO mapper(ResultSet* resultSet) const override
	{
		LadModDO data;
		data.setId(resultSet->getUInt64(1));
		data.setCode(resultSet->getString(2));
		data.setName(resultSet->getString(3));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrLadModMapper : public Mapper<PtrLadModDO>
{
public:
	PtrLadModDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<LadModDO>();
		data->setId(resultSet->getUInt64(1));
		data->setCode(resultSet->getString(2));
		data->setName(resultSet->getString(3));
		return data;
	}
};

#endif // !_LadMod_MAPPER_