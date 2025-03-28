#pragma once
#ifndef _MODIFY_MAPPER_
#define _MODIFY_MAPPER_

#include "Mapper.h"
#include "../../domain/do/modify-industry-class/ModifyDO.h"

/**
 * 示例表字段匹配映射
 */
class ModifyMapper : public Mapper<ModifyDO>
{
public:
	ModifyDO mapper(ResultSet* resultSet) const override
	{
		ModifyDO data;
		
		data.setId(resultSet->getString(1));
		data.setClassfl_code(resultSet->getString(2));
		data.setClassfl_name(resultSet->getString(3));
		data.setClassfl_del(resultSet->getString(4));

		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrModifyMapper : public Mapper<PtrModifyDO>
{
public:
	PtrModifyDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<ModifyDO>();
		data->setId(resultSet->getString(1));
		data->setClassfl_code(resultSet->getString(2));
		data->setClassfl_name(resultSet->getString(3));
		data->setClassfl_del(resultSet->getString(4));
		return data;
	}
};


#endif // !_MODIFY_MAPPER_
