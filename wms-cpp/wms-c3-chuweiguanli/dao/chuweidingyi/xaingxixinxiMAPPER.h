#pragma once

#ifndef _XIANGXIXINXIMAPPER_
#define _XIANGXIXINXIMAPPER_

#include "Mapper.h"
#include "../../domain/do/BinDO.h"



class xiangxixinxiMapper : public Mapper<BinDO>
{
public:
	BinDO mapper(ResultSet* resultSet) const override
	{
		BinDO data;
		data.setId(resultSet->getString(1));
		data.setCreateName(resultSet->getString(2));
		data.setCreateBy(resultSet->getString(3));
		data.setCreateDate(resultSet->getString(4));
		data.setUpdateName(resultSet->getString(5));
		data.setUpdateBy(resultSet->getString(6));
		data.setUpdateDate(resultSet->getString(7));
		data.setSysOrgCode(resultSet->getString(8));
		data.setSysCompanyCode(resultSet->getString(9));
		data.setKuWeiMingCheng(resultSet->getString(10));

		data.setKuWeiBianMa(resultSet->getString(11));
		data.setKuWeiTiaoMa(resultSet->getString(12));
		data.setKuWeiLeiXing(resultSet->getString(13));
		data.setKuWeiShuXing(resultSet->getString(14));
		data.setShangJiaCiXu(resultSet->getString(15));
		data.setQuHuoCiXu(resultSet->getString(16));
		data.setSuoShuKeHu(resultSet->getString(17));
		data.setTiJiDanWei(resultSet->getString(18));
		data.setZhongLiangDanWei(resultSet->getString(19));
		data.setMianJiDanWei(resultSet->getString(20));
		data.setZuiDaTiJi(resultSet->getString(21));
		data.setZuiDaZhongLiang(resultSet->getString(22));
		data.setZuiDaMianJi(resultSet->getString(23));
		data.setZuiDaTuoPan(resultSet->getString(24));
		data.setChang(resultSet->getString(25));
		data.setKuan(resultSet->getString(26));
		data.setGao(resultSet->getString(27));
		data.setTingYong(resultSet->getString(28));
		data.setMingXi(resultSet->getString(29));

		data.setBinStore(resultSet->getString(30));//²Ö¿â

		data.setCHPShuXing(resultSet->getString(31));
		data.setMingXi1(resultSet->getString(32));
		data.setMingXi2(resultSet->getString(33));
		data.setMingXi3(resultSet->getString(34));
		data.setLORABqid(resultSet->getString(35));
		data.setXNode(resultSet->getString(36));
		data.setYNode(resultSet->getString(37));
		data.setZNode(resultSet->getString(38));

		return data;
	}
};


class ptrxiangxixinxiMapper : public Mapper<std::shared_ptr<BinDO>>
{
public:
	std::shared_ptr<BinDO> mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<BinDO>();
		data->setId(resultSet->getString(1));
		data->setCreateName(resultSet->getString(2));
		data->setCreateBy(resultSet->getString(3));
		data->setCreateDate(resultSet->getString(4));
		data->setUpdateName(resultSet->getString(5));
		data->setUpdateBy(resultSet->getString(6));
		data->setUpdateDate(resultSet->getString(7));
		data->setSysOrgCode(resultSet->getString(8));
		data->setSysCompanyCode(resultSet->getString(9));
		data->setKuWeiMingCheng(resultSet->getString(10));

		data->setKuWeiBianMa(resultSet->getString(11));
		data->setKuWeiTiaoMa(resultSet->getString(12));
		data->setKuWeiLeiXing(resultSet->getString(13));
		data->setKuWeiShuXing(resultSet->getString(14));
		data->setShangJiaCiXu(resultSet->getString(15));
		data->setQuHuoCiXu(resultSet->getString(16));
		data->setSuoShuKeHu(resultSet->getString(17));
		data->setTiJiDanWei(resultSet->getString(18));
		data->setZhongLiangDanWei(resultSet->getString(19));
		data->setMianJiDanWei(resultSet->getString(20));
		data->setZuiDaTiJi(resultSet->getString(21));
		data->setZuiDaZhongLiang(resultSet->getString(22));
		data->setZuiDaMianJi(resultSet->getString(23));
		data->setZuiDaTuoPan(resultSet->getString(24));
		data->setChang(resultSet->getString(25));
		data->setKuan(resultSet->getString(26));
		data->setGao(resultSet->getString(27));
		data->setTingYong(resultSet->getString(28));
		data->setMingXi(resultSet->getString(29));

		data->setBinStore(resultSet->getString(30));//²Ö¿â

		data->setCHPShuXing(resultSet->getString(31));
		data->setMingXi1(resultSet->getString(32));
		data->setMingXi2(resultSet->getString(33));
		data->setMingXi3(resultSet->getString(34));
		data->setLORABqid(resultSet->getString(35));
		data->setXNode(resultSet->getString(36));
		data->setYNode(resultSet->getString(37));
		data->setZNode(resultSet->getString(38));

		return data;
	}
};




#endif // !_XIANGXIXINXIMAPPER_
