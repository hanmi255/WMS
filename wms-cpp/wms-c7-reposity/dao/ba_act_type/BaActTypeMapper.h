#pragma once

#ifndef _SAMPLE_MAPPER_
#define _SAMPLE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/ba_act_type/BaActTypeDO.h"

/**
 * 示例表字段匹配映射
 */
class BaActTypeMapper : public Mapper<BaActTypeDO>
{
public:
	BaActTypeDO mapper(ResultSet* resultSet) const override
	{
		BaActTypeDO data;
		data.setId(resultSet->getString(1));
		data.setActTypeCode(resultSet->getString(2));
		data.setActTypeName(resultSet->getString(3));
		data.setOperStepCode(resultSet->getString(4));
		return data;
	}
};


class BaActTypeMapperAll : public Mapper<BaActTypeDO> {
public:
	BaActTypeDO mapper(ResultSet* resultSet) const override {
		BaActTypeDO data;
		data.setId(resultSet->getString(1));           // 主键
		data.setCreateName(resultSet->getString(2));   // 创建人名称
		data.setCreateBy(resultSet->getString(3));     // 创建人登录名称
		data.setCreateDate(resultSet->getString(4));   // 创建日期
		data.setUpdateName(resultSet->getString(5));   // 更新人名称
		data.setUpdateBy(resultSet->getString(6));     // 更新人登录名称
		data.setUpdateDate(resultSet->getString(7));   // 更新日期
		data.setSysOrgCode(resultSet->getString(8));   // 所属部门
		data.setSysCompanyCode(resultSet->getString(9)); // 所属公司
		data.setActTypeCode(resultSet->getString(10)); // 作业类型代码
		data.setActTypeName(resultSet->getString(11)); // 作业类型名称
		data.setOperStepCode(resultSet->getString(12)); // 业务环节代码
		return data;
	}
};


/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrBaActTypeMapper : public Mapper<PtrBaActTypeDO>
{
public:
	PtrBaActTypeDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<BaActTypeDO>();
		data->setId(resultSet->getString(1));
		data->setActTypeCode(resultSet->getString(2));
		data->setActTypeName(resultSet->getString(3));
		data->setOperStepCode(resultSet->getString(4));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_