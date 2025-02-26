#pragma once
#ifndef _BINMAPPER_
#define _BINMAPPER_
#include "Mapper.h"
#include "domain/do/BinDO.h"

class BinMapper : public Mapper<BinDO>
{
public:
	BinDO mapper(ResultSet* resultSet) const override
	{
		BinDO data;
		data.setId(resultSet->getString(1));
		data.setBinStore(resultSet->getString(2));
		data.setKuWeiShuXing(resultSet->getString(3));
		data.setKuWeiBianMa(resultSet->getString(4));
		data.setSuoShuKeHu(resultSet->getString(5));
		data.setZuiDaTiJi(resultSet->getString(6));
		data.setShangJiaCiXu(resultSet->getString(7));
		data.setChang(resultSet->getString(8));
		data.setKuan(resultSet->getString(9));
		data.setGao(resultSet->getString(10));
		data.setZuiDaTuoPan(resultSet->getString(11));
		return data;
	}
};

class BinFileMapper : public Mapper<BinDO>
{
public:
	BinDO mapper(ResultSet* resultSet) const override
	{
		BinDO data;
		data.setBinStore(resultSet->getString(1));
		data.setKuWeiShuXing(resultSet->getString(2));
		data.setKuWeiBianMa(resultSet->getString(3));
		data.setSuoShuKeHu(resultSet->getString(4));
		data.setZuiDaTiJi(resultSet->getString(5));
		data.setShangJiaCiXu(resultSet->getString(6));
		data.setChang(resultSet->getString(7));
		data.setKuan(resultSet->getString(8));
		data.setGao(resultSet->getString(9));
		data.setZuiDaTuoPan(resultSet->getString(10));
		return data;
	}
};

#endif // !_BINMAPPER_
