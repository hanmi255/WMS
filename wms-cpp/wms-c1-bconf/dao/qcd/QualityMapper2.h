#pragma once
#ifndef _QUALITYMAPPER_H_
#define _QUALITYMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/qcd/QualityDO2.h"

/**
 * 示例表字段匹配映射
 */
class QualityMapper : public Mapper<QualityDO>
{
public:
	QualityDO mapper(ResultSet* resultSet) const override
	{
		QualityDO data;
		data.setId(resultSet->getString(1));
		data.setCreate_name(resultSet->getString(2));
		data.setCreate_by(resultSet->getString(3));
		data.setCreate_date(resultSet->getString(4));
		data.setUpdate_name(resultSet->getString(5));
		data.setUpdate_by(resultSet->getString(6));
		data.setUpdate_date(resultSet->getString(7));
		data.setSys_org_code(resultSet->getString(8));
		data.setSys_company_code(resultSet->getString(9));
		data.setQm_qa_code(resultSet->getString(10));
		data.setQm_qa_name(resultSet->getString(11));

		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrQualityMapper : public Mapper<std::shared_ptr<QualityDO>>
{
public:
	std::shared_ptr<QualityDO> mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<QualityDO>();
		data->setId(resultSet->getString(1));
		data->setCreate_name(resultSet->getString(2));
		data->setCreate_by(resultSet->getString(3));
		data->setCreate_date(resultSet->getString(4));
		data->setUpdate_name(resultSet->getString(5));
		data->setUpdate_by(resultSet->getString(6));
		data->setUpdate_date(resultSet->getString(7));
		data->setSys_org_code(resultSet->getString(8));
		data->setSys_company_code(resultSet->getString(9));
		data->setQm_qa_code(resultSet->getString(10));
		data->setQm_qa_name(resultSet->getString(11));
		return data;
	}
};

#endif // !_QUALITYMAPPER_H_