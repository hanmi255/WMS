#ifndef _COMDEGFIG_MAPPER_
#define _COMDEGFIG_MAPPER_

#include "Mapper.h"
#include "domain/do/condegfig/ComdegfigDO.h"

/**
 * 示例表字段匹配映射
 */
class ComdegfigMapper : public Mapper<ComdegfigDO>
{
public:
	ComdegfigDO mapper(ResultSet* resultSet) const override
	{
		ComdegfigDO data;
		data.setDegCode(resultSet->getString(1));
		data.setDegName(resultSet->getString(2));
		data.setDegDel(resultSet->getString(3));
		data.setId(resultSet->getString(4));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrComdegfigMapper : public Mapper<PtrComdegfigDO>
{
public:
	PtrComdegfigDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<ComdegfigDO>();
		data->setDegCode(resultSet->getString(1));
		data->setDegName(resultSet->getString(2));
		data->setDegDel(resultSet->getString(3));
		data->setId(resultSet->getString(4));
		return data;
	}
};

#endif //_COMDEGFIG_MAPPER_