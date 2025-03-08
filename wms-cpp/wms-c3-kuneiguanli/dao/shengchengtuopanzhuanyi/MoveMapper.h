#pragma once
#ifndef _MOVE_MAPPER_
#define _MOVE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/MoveDO.h"

/**
 * 示例表字段匹配映射
 */
class MoveMapper : public Mapper<MoveDO>
{
public:
	MoveDO mapper(ResultSet* resultSet) const override
	{
		MoveDO data;
		//data.setMoveDate(resultSet->getString(1));
		data.setKucType(resultSet->getString(1));
		data.setKuWeiBianMa(resultSet->getString(2));
		data.setBinId(resultSet->getString(3));
		data.setCusCode(resultSet->getString(4));
		data.setZhongWenQch(resultSet->getString(5));
		data.setGoodsId(resultSet->getString(6));
		data.setGoodsQua(resultSet->getString(7));
		data.setShpMingCheng(resultSet->getString(8));
		data.setGoodsProData(resultSet->getString(9));
		data.setBzhiQi(resultSet->getString(10));
		data.setGoodsUnit(resultSet->getString(11));
		//data.setSttSta(resultSet->getString(13));
		
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrMoveMapper : public Mapper<PtrMoveDO>
{
public:
	PtrMoveDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<MoveDO>();
		data->setMoveDate(resultSet->getString(1));
		data->setKucType(resultSet->getString(2));
		data->setKuWeiBianMa(resultSet->getString(3));
		data->setBinId(resultSet->getString(4));
		data->setCusCode(resultSet->getString(5));
		data->setZhongWenQch(resultSet->getString(6));
		data->setGoodsId(resultSet->getString(7));
		data->setGoodsQua(resultSet->getString(8));
		data->setShpMingCheng(resultSet->getString(9));
		data->setGoodsProData(resultSet->getString(10));
		data->setBzhiQi(resultSet->getString(11));
		data->setGoodsUnit(resultSet->getString(12));
		data->setSttSta(resultSet->getString(13));
		return data;
	}
};

#endif // !_MOVE_MAPPER_