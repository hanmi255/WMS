#pragma once
#ifndef _EDU_MAPPER_
#define _EDU_MAPPER_

#include "Mapper.h"
#include "../domain/do/education/EducationDO.h"

/**
 * 学历表字段匹配映射
 */
class EduMapper : public Mapper<EducationDO>
{
public:
	EducationDO mapper(ResultSet* resultSet) const override
	{
		EducationDO data;
		data.setEduCode(resultSet->getString(1));
		data.setEduName(resultSet->getString(2));
		return data;
	}
};

class EduBaseMapper : public Mapper<EduBaseDO>
{
public:
	EduBaseDO mapper(ResultSet* resultSet) const override
	{
		EduBaseDO data;
		data.setEduCode(resultSet->getString(1));
		data.setEduName(resultSet->getString(2));
		return data;
	}
};

/**
 * 学历表字段匹配映射-创建智能指针对象
 */
class PtrEduMapper : public Mapper<PtrEducationDO>
{
public:
	PtrEducationDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<EducationDO>();
		data->setEduCode(resultSet->getString(1));
		data->setEduName(resultSet->getString(2));
		return data;
	}
};

#endif // !_EDU_MAPPER_