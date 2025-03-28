#pragma once

#ifndef _UNLOADINGFEE_MAPPER_
#define _UNLOADINGFEE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/UnloadingFeeDO.h"

/**
 * 外包卸货费表字段匹配映射
 */
class UnloadingFeeMapper : public Mapper<UnloadingFeeDO>
{
public:
	UnloadingFeeDO mapper(ResultSet* resultSet) const override
	{
		UnloadingFeeDO data;
		data.setFee(resultSet->getString(1));
		data.setAcceptor(resultSet->getString(2));
		data.setAcceptDate(resultSet->getString(3));
		data.setOrderNo(resultSet->getString(4));
		data.setGoods(resultSet->getString(5));
		data.setGoodsName(resultSet->getString(6));
		data.setUnloadingNum(resultSet->getInt(7));
		data.setUnloadingWeight(resultSet->getDouble(8));
		data.setFeeRMB(resultSet->getDouble(9));
		data.setPrice(resultSet->getDouble(10));
		return data;
	}
};

#endif // !_UNLOADINGFEE_MAPPER_