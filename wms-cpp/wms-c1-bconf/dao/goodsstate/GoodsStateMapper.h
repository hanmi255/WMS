#pragma once
#ifndef _GOODSSTATEMAPPER_
#define _GOODSSTATEMAPPER_

#include "Mapper.h"
#include "../../domain/do/GoodsStateControllerDO/GoodsStateControllerDO.h"

/**
 * 示例表字段匹配映射
 */
class GoodsStateMapper : public Mapper<GoodsStateControllerDO>
{
public:
	GoodsStateControllerDO mapper(ResultSet* resultSet) const override
	{
		GoodsStateControllerDO data;
		data.setId(resultSet->getString(1));
		data.setCreate_name(resultSet->getString(2));
		data.setCreate_by(resultSet->getString(3));
		data.setCreate_date(resultSet->getString(4));
		data.setUpdate_name(resultSet->getString(5));
		data.setUpdate_by(resultSet->getString(6));
		data.setUpdate_date(resultSet->getString(7));
		data.setSys_org_code(resultSet->getString(8));
		data.setSys_company_code(resultSet->getString(9));
		data.setQm_sta_code(resultSet->getString(10));
		data.setQm_sta_name(resultSet->getString(11));

		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrGoodsStateMapper : public Mapper<PtrGoodsStateControllerDO>
{
public:
	PtrGoodsStateControllerDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<GoodsStateControllerDO>();
		data->setId(resultSet->getString(1));
		data->setCreate_name(resultSet->getString(2));
		data->setCreate_by(resultSet->getString(3));
		data->setCreate_date(resultSet->getString(4));
		data->setUpdate_name(resultSet->getString(5));
		data->setUpdate_by(resultSet->getString(6));
		data->setUpdate_date(resultSet->getString(7));
		data->setSys_org_code(resultSet->getString(8));
		data->setSys_company_code(resultSet->getString(9));
		data->setQm_sta_code(resultSet->getString(10));
		data->setQm_sta_name(resultSet->getString(11));
		return data;
	}
};

#endif // !_GOODSSTATEMAPPER_