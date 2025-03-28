#pragma once

#ifndef _LOADINGFEE_MAPPER_
#define _LOADINGFEE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/LoadingFeeDO.h"

/**
 * 外包装车费表字段匹配映射
 */
class LoadingFeeMapper : public Mapper<LoadingFeeDO>
{
public:
	LoadingFeeDO mapper(ResultSet* resultSet) const override
	{
		LoadingFeeDO data;
		data.setFee(resultSet->getString(1));
		data.setXOperator(resultSet->getString(2));
		data.setOperateDate(resultSet->getString(3));
		data.setOrderNo(resultSet->getString(4));
		data.setGoods(resultSet->getString(5));
		data.setGoodsName(resultSet->getString(6));
		data.setGoodsNum(resultSet->getInt(7));
		data.setGoodsWeight(resultSet->getDouble(8));
		data.setFeeRMB(resultSet->getDouble(9));
		data.setPrice(resultSet->getDouble(10));
		return data;
	}
};

#endif // !_LOADINGFEE_MAPPER_