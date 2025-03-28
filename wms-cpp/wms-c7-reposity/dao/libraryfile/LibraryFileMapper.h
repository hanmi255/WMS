#pragma once
/*
 @Author: nanbowan
*/
#ifndef _SAMPLE_MAPPER_
#define _SAMPLE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/libraryfile/LibraryFileDO.h"

/**
 * 表字段匹配映射
 */
class LibraryFileMapper : public Mapper<LibraryFileDO>
{
public:
	LibraryFileDO mapper(ResultSet* resultSet) const override
	{
		LibraryFileDO data;
		data.setCode(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrLibraryFileMapper : public Mapper<PtrLibraryFileDO>
{
public:
	PtrLibraryFileDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<LibraryFileDO>();
		data->setCode(resultSet->getString(1));
		data->setName(resultSet->getString(2));
		return data;
	}
};

#endif //