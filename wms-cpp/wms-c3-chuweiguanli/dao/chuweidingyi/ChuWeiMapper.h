#pragma once
#ifndef _CHUWEI_MAPPER_
#define _CHUWEI_MAPPER_

#include "Mapper.h"
#include "../../domain/do/BinDO.h"

/**
 * 储位表字段匹配映射
 */
class ChuWeiMapper : public Mapper<BinDO>
{
public:
	BinDO mapper(ResultSet* resultSet) const override
	{
		BinDO data;
		data.setId(resultSet->getString(1));
		data.setBinStore(resultSet->getString(2));
		data.setKuWeiBianMa(resultSet->getString(3));
		data.setKuWeiTiaoMa(resultSet->getString(4));
		data.setKuWeiLeiXing(resultSet->getString(5));
		data.setKuWeiShuXing(resultSet->getString(6));
		data.setCHPShuXing(resultSet->getString(7));
		data.setShangJiaCiXu(resultSet->getString(8));
		data.setQuHuoCiXu(resultSet->getString(9));
		data.setZuiDaTiJi(resultSet->getString(10));
		data.setZuiDaZhongLiang(resultSet->getString(11));
		data.setZuiDaTuoPan(resultSet->getString(12));
		data.setChang(resultSet->getString(13));
		data.setKuan(resultSet->getString(14));
		data.setGao(resultSet->getString(15));
		data.setTingYong(resultSet->getString(16));
		data.setMingXi(resultSet->getString(17));
		data.setMingXi1(resultSet->getString(18));
		data.setMingXi2(resultSet->getString(19));
		data.setMingXi3(resultSet->getString(20));
		data.setLORABqid(resultSet->getString(21));
		data.setXNode(resultSet->getString(22));
		data.setYNode(resultSet->getString(23));
		data.setZNode(resultSet->getString(24));
		//data.setCreateName(resultSet->getString(2));
		//data.setCreateBy(resultSet->getString(3));
		//data.setCreateDate(resultSet->getString(4));
		//data.setUpdateName(resultSet->getString(5));
		//data.setUpdateBy(resultSet->getString(6));
		//data.setUpdateDate(resultSet->getString(7));
		//data.setSysOrgCode(resultSet->getString(8));
		//data.setSysCompanyCode(resultSet->getString(9));
		//data.setKuWeiMingCheng(resultSet->getString(10));
		//data.setSuoShuKeHu(resultSet->getString(17));
		//data.setTiJiDanWei(resultSet->getString(18));
		//data.setZhongLiangDanWei(resultSet->getString(19));
		//data.setMianJiDanWei(resultSet->getString(20));
		//data.setZuiDaMianJi(resultSet->getString(23));
		return data;
	}
};

/**
 * 表字段匹配映射-创建智能指针对象
 */
class PtrChuWeiMapper : public Mapper<std::shared_ptr<BinDO>>
{
public:
	std::shared_ptr<BinDO> mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<BinDO>();
		data->setId(resultSet->getString(1));
		data->setBinStore(resultSet->getString(2));
		data->setKuWeiBianMa(resultSet->getString(3));
		data->setKuWeiTiaoMa(resultSet->getString(4));
		data->setKuWeiLeiXing(resultSet->getString(5));
		data->setKuWeiShuXing(resultSet->getString(6));
		data->setCHPShuXing(resultSet->getString(7));
		data->setShangJiaCiXu(resultSet->getString(8));
		data->setQuHuoCiXu(resultSet->getString(9));
		data->setZuiDaTiJi(resultSet->getString(10));
		data->setZuiDaZhongLiang(resultSet->getString(11));
		data->setZuiDaTuoPan(resultSet->getString(12));
		data->setChang(resultSet->getString(13));
		data->setKuan(resultSet->getString(14));
		data->setGao(resultSet->getString(15));
		data->setTingYong(resultSet->getString(16));
		data->setMingXi(resultSet->getString(17));
		data->setMingXi1(resultSet->getString(18));
		data->setMingXi2(resultSet->getString(19));
		data->setMingXi3(resultSet->getString(20));
		data->setLORABqid(resultSet->getString(21));
		data->setXNode(resultSet->getString(22));
		data->setYNode(resultSet->getString(23));
		data->setZNode(resultSet->getString(24));
		return data;
	}
};

#endif // !_CHUWEI_MAPPER_