#ifndef _BAWORKST_MAPPER_
#define _BAWORKST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/baworkst/BaWorkStDO.h"

/**
 * 工作状态表字段匹配映射
 */
class BaWorkStMapper : public Mapper<BaWorkStDO>
{
public:
	BaWorkStDO mapper(ResultSet* resultSet) const override
	{
		BaWorkStDO data;
		//根据列索引来查询
		data.setId(resultSet->getString(1));
		data.setCreateName(resultSet->getString(2));
		data.setCreateBy(resultSet->getString(3));
		data.setCreateDate(resultSet->getString(4));
		data.setUpdateName(resultSet->getString(5));
		data.setUpdateBy(resultSet->getString(6));
		data.setUpdateDate(resultSet->getString(7));
		data.setSysOrgCode(resultSet->getString(8));
		data.setSysCompanyCode(resultSet->getString(9));
		data.setWorkStaCode(resultSet->getString(10));
		data.setWorkStaName(resultSet->getString(11));
		return data;
	}
};

/**
 * 工作状态表字段匹配映射-创建智能指针对象
 */
class PtrBaWorkStMapper : public Mapper<PtrBaWorkStDO>
{
public:
	PtrBaWorkStDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<BaWorkStDO>();
		data->setId(resultSet->getString(1));
		data->setCreateName(resultSet->getString(2));
		data->setCreateBy(resultSet->getString(3));
		data->setCreateBy(resultSet->getString(4));
		data->setUpdateName(resultSet->getString(5));
		data->setUpdateBy(resultSet->getString(6));
		data->setUpdateDate(resultSet->getString(7));
		data->setSysOrgCode(resultSet->getString(8));
		data->setSysCompanyCode(resultSet->getString(9));
		data->setWorkStaCode(resultSet->getString(10));
		data->setWorkStaName(resultSet->getString(11));
		return data;
	}
};

#endif // !_BAWORKST_MAPPER_