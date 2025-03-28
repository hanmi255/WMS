#pragma once

#ifndef _INVENTORYP_MAPPER_
#define _INVENTORYP_MAPPER_

#include "Mapper.h"
#include "../../domain/do/inentorydifference/InventoryPDO.h"

/**
 * 示例表字段匹配映射
 */
class InventoryPMapper : public Mapper<InventoryPDO>
{
public:
	InventoryPDO mapper(ResultSet* resultSet) const override
	{
		InventoryPDO data;
		data.setId(resultSet->getString(1));
		data.setStt_name(resultSet->getString(2));
		data.setStt_date(resultSet->getString(3));
		data.setBin_id(resultSet->getString(4));
		data.setTin_id(resultSet->getString(5));
		data.setGoods_id(resultSet->getString(6));
		data.setGoods_name(resultSet->getString(7));
		data.setGoods_qua(resultSet->getString(8));
		data.setGoods_unit(resultSet->getString(9));
		data.setGoods_pro_data(resultSet->getString(10));
		data.setStt_qua(resultSet->getString(11));
		data.setCus_code(resultSet->getString(12));
		data.setCus_id(resultSet->getString(13));
		data.setStt_sta(resultSet->getString(14));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrInventoryPMapper : public Mapper<PtrInventoryPDO>
{
public:
	PtrInventoryPDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<InventoryPDO>();
		data->setId(resultSet->getString(1));
		data->setStt_name(resultSet->getString(2));
		data->setStt_date(resultSet->getString(3));
		data->setBin_id(resultSet->getString(4));
		data->setTin_id(resultSet->getString(5));
		data->setGoods_id(resultSet->getString(6));
		data->setGoods_name(resultSet->getString(7));
		data->setGoods_qua(resultSet->getString(8));
		data->setGoods_unit(resultSet->getString(9));
		data->setGoods_pro_data(resultSet->getString(10));
		data->setStt_qua(resultSet->getString(11));
		data->setCus_code(resultSet->getString(12));
		data->setCus_id(resultSet->getString(13));
		data->setStt_sta(resultSet->getString(14));
		return data;
	}
};

#endif // !_INVENTORYP_MAPPER_