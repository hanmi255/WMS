#pragma once
#ifndef _MOVEGOODS_MAPPER_
#define _MOVEGOODS_MAPPER_

#include "Mapper.h"
#include "../../domain/do/MoveGoodsDO.h"

/**
* 示例表字段匹配映射
*/
class MoveGoodsMapper : public Mapper<MoveGoodsDO>
{
public:
	MoveGoodsDO mapper(ResultSet* resultSet) const override
	{
		MoveGoodsDO data;
		data.setId(resultSet->getString(1));
		data.setCreateName(resultSet->getString(2));
		data.setCreateBy(resultSet->getString(3));
		data.setCreateDate(resultSet->getString(4));
		data.setUpdateName(resultSet->getString(5));
		data.setUpdateBy(resultSet->getString(6));
		data.setUpdateDate(resultSet->getString(7));
		data.setSysOrgCode(resultSet->getString(8));
		data.setSysCompanyCode(resultSet->getString(9));
		data.setOrderTypeCode(resultSet->getString(10));
		data.setOrderId(resultSet->getString(11));
		data.setOrderIdI(resultSet->getString(12));
		data.setGoodsId(resultSet->getString(13));
		data.setGoodsName(resultSet->getString(14));
		data.setGoodsQua(resultSet->getString(15));
		data.setGoodsProData(resultSet->getString(16));
		data.setGoodsUnit(resultSet->getString(17));
		data.setCusCode(resultSet->getString(18));
		data.setCusName(resultSet->getString(19));
		data.setTinFrom(resultSet->getString(20));
		data.setTinId(resultSet->getString(21));
		data.setBinFrom(resultSet->getString(22));
		data.setBinTo(resultSet->getString(23));
		data.setMoveSta(resultSet->getString(24));
		data.setToCusCode(resultSet->getString(25));
		data.setToCusName(resultSet->getString(26));
		data.setBaseUnit(resultSet->getString(27));
		data.setBaseGoodscount(resultSet->getString(28));
		data.setToGoodsProData(resultSet->getString(29));
		data.setRunSta(resultSet->getString(30));
		return data;
	}
};

class PtrMoveGoodsDetailedMapper : public Mapper<PtrMoveGoodsDO>
{
public:
	PtrMoveGoodsDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<MoveGoodsDO>();
		data->setGoodsId(resultSet->getString(1));
		data->setGoodsName(resultSet->getString(2));
		data->setGoodsQua(resultSet->getString(3));
		data->setGoodsProData(resultSet->getString(4));
		data->setGoodsUnit(resultSet->getString(5));
		data->setCusCode(resultSet->getString(6));
		data->setCusName(resultSet->getString(7));
		data->setTinFrom(resultSet->getString(8));
		data->setTinId(resultSet->getString(9));
		data->setBinFrom(resultSet->getString(10));
		data->setBinTo(resultSet->getString(11));
		data->setMoveSta(resultSet->getString(12));
		data->setToCusCode(resultSet->getString(13));
		data->setToCusName(resultSet->getString(14));
		data->setBaseGoodscount(resultSet->getString(15));
		data->setToGoodsProData(resultSet->getString(16));
		return data;
	}
};

/**
* 转移任务文件导出字段匹配映射
*/
class MoveGoodsDownLoadMapper : public Mapper<MoveGoodsDO>
{
public:
	MoveGoodsDO mapper(ResultSet* resultSet) const override
	{
		MoveGoodsDO data;
		data.setCreateBy(resultSet->getString(1));
		data.setCreateDate(resultSet->getString(2));
		data.setOrderIdI(resultSet->getString(3));
		data.setGoodsId(resultSet->getString(4));
		data.setGoodsName(resultSet->getString(5));
		data.setGoodsQua(resultSet->getString(6));
		data.setGoodsProData(resultSet->getString(7));
		data.setGoodsUnit(resultSet->getString(8));
		data.setCusCode(resultSet->getString(9));
		data.setCusName(resultSet->getString(10));
		data.setTinFrom(resultSet->getString(11));
		data.setTinId(resultSet->getString(12));
		data.setBinFrom(resultSet->getString(13));
		data.setBinTo(resultSet->getString(14));
		data.setMoveSta(resultSet->getString(15));
		data.setToCusCode(resultSet->getString(16));
		data.setToCusName(resultSet->getString(17));
		data.setBaseUnit(resultSet->getString(18));
		data.setBaseGoodscount(resultSet->getString(19));
		data.setToGoodsProData(resultSet->getString(20));
		return data;
	}
};


#endif // !_MOVEGOODS_MAPPER_