#pragma once

#ifndef _EXPIRATION_MAPPER_
#define _EXPIRATION_MAPPER_

#include "domain/do/StockYJDO.h"
class ExpirationDateEarlyWarningMapper :Mapper<StockYJDO> {
public:
	StockYJDO mapper(ResultSet* resultSet)const override {
		StockYJDO data;
		data.setId(resultSet->getString(1));
		data.setKuCType(resultSet->getString(2));
		data.setGoods_Id(resultSet->getString(3));
		data.setKu_Wei_Bian_Ma(resultSet->getString(4));
		data.setShp_Ming_Cheng(resultSet->getString(5));
		data.setBase_GoodsCount(resultSet->getUInt64(6));
		data.setBase_Unit(resultSet->getString(7));
		data.setCus_Code(resultSet->getString(8));
		data.setGoods_Pro_Data(resultSet->getString(9));
		data.setBzhi_Qi(resultSet->getString(10));
		data.setDqr(resultSet->getString(11));
		data.setRes_Date(resultSet->getDouble(12));
		data.setGuoQiBiLi(resultSet->getString(13));
		data.setCus_Name(resultSet->getString(14));
		return data;
	}
};



#endif // !_EXPIRATION_MAPPER_

