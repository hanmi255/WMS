#pragma once
/*
 @Author: nanbowan
*/
#ifndef _SAMPLE_MAPPER_
#define _SAMPLE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/file/FileDO.h"

/**
 * 表字段匹配映射
 */
class FileMapper : public Mapper<FileDO>
{
public:
	FileDO mapper(ResultSet* resultSet) const override
	{
		FileDO data;
		data.setCode(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrFileMapper : public Mapper<PtrFileDO>
{
public:
	PtrFileDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<FileDO>();
		data->setCode(resultSet->getString(1));
		data->setName(resultSet->getString(2));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_