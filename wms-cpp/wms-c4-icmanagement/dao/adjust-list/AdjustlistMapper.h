#pragma once
/*****************************************************************************
    *  @COPYRIGHT NOTICE
    *  @Copyright (c) 2013, kato1
    *  @All rights reserved
    *  @file	 : AdjustlistMapper.h
    *  @version  : ver 1.0
    *  @author   : kato1
    *  @date     : 2025/2/27 15:30
    *  @brief    : brief
*****************************************************************************/

#ifndef _ADJUSTLIST_MAPPER_
#define _ADJUSTLIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/adjust-list/AdjustlistDO.h"

/**
 * 示例表字段匹配映射(查询上架货物详细信息)
 */
class AdjustlistMapper : public Mapper<AdjustlistDO>
{
public:
	AdjustlistDO mapper(ResultSet* resultSet) const override
	{
		AdjustlistDO data;
		data.setId(resultSet->getString(1));
		data.setCreateDate(resultSet->getString(2));
		data.setGoodsId(resultSet->getString(3));
		data.setOrderId(resultSet->getString(4));
		data.setGoodsUnit(resultSet->getString(5));
		data.setCusCode(resultSet->getString(6));
		data.setGoodsQua(resultSet->getString(7));
		data.setGoodsProData(resultSet->getString(8));
		data.setKuWeiBianMa(resultSet->getString(9));
		data.setBinId(resultSet->getString(10));
		data.setBaseUnit(resultSet->getString(11));
		data.setBaseGoodscount(resultSet->getString(12));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrAdjustlistMapper : public Mapper<PtrAdjustlistDO>
{
public:
	PtrAdjustlistDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<AdjustlistDO>();
		data->setId(resultSet->getString(1));
		data->setCreateDate(resultSet->getString(2));
		data->setGoodsId(resultSet->getString(3));
		data->setOrderId(resultSet->getString(4));
		data->setGoodsUnit(resultSet->getString(5));
		data->setCusCode(resultSet->getString(6));
		data->setGoodsQua(resultSet->getString(7));
		data->setGoodsProData(resultSet->getString(8));
		data->setKuWeiBianMa(resultSet->getString(9));
		data->setBinId(resultSet->getString(10));
		data->setBaseUnit(resultSet->getString(11));
		data->setBaseGoodscount(resultSet->getString(12));
		return data;
	}
};



/**
 * 示例表字段匹配映射(分页查询上架货物信息)
 */
class AdjustlistpageMapper : public Mapper<AdjustlistDO>
{
public:
	AdjustlistDO mapper(ResultSet* resultSet) const override
	{
		AdjustlistDO data;
		data.setId(resultSet->getString(1));
		data.setCreateDate(resultSet->getString(2));
		data.setGoodsQua(resultSet->getString(3));
		data.setKuWeiBianMa(resultSet->getString(4));
		data.setBinId(resultSet->getString(5));
		data.setGoodsId(resultSet->getString(6));
		data.setBaseGoodscount(resultSet->getString(7));
		data.setBaseUnit(resultSet->getString(8));
		data.setGoodsName(resultSet->getString(9));
		data.setOrderId(resultSet->getString(10));
		data.setGoodsUnit(resultSet->getString(11));
		data.setCusCode(resultSet->getString(12));
		
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrAdjustlistpageMapper : public Mapper<PtrAdjustlistDO>
{
public:
	PtrAdjustlistDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<AdjustlistDO>();
		data->setId(resultSet->getString(1));
		data->setCreateDate(resultSet->getString(2));
		data->setGoodsQua(resultSet->getString(3));
		data->setKuWeiBianMa(resultSet->getString(4));
		data->setBinId(resultSet->getString(5));
		data->setGoodsId(resultSet->getString(6));
		data->setBaseGoodscount(resultSet->getString(7));
		data->setBaseUnit(resultSet->getString(8));
		data->setGoodsName(resultSet->getString(9));
		data->setOrderId(resultSet->getString(10));
		data->setGoodsUnit(resultSet->getString(11));
		data->setCusCode(resultSet->getString(12));

		return data;
	}
};



#endif // !_ADJUSTLIST_MAPPER_