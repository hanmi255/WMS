#pragma once
#ifndef _BILLING_MAPPER_
#define _BILLING_MAPPER_

#include "Mapper.h"
#include "../../domain/do/billing-name/BillingNameDO.h"
/**
 * 示例表字段匹配映射
 */
class BillingNameMapper : public Mapper<BillingNameDO>
{
public:
	//ResultSet通常是用来获取数据库的每个字段
    BillingNameDO mapper(ResultSet* resultSet) const override
	{
		BillingNameDO data;
		//用data这个类将数据库的每一个字段给包裹起来
		//data.setId(resultSet->getString(1));// 编号
		data.setCost_code(resultSet->getString(1));
		data.setCost_name(resultSet->getString(2));
		data.setCost_type_code(resultSet->getString(3));
		return data;
	}
};

/**
 * 库存表字段匹配映射-创建智能指针对象
 */
class PtrBillingNameMapper : public Mapper<PtrBillingNameDO>
{
public:
	PtrBillingNameDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<BillingNameDO>();
		//data->setId(resultSet->getString(1));// 编号
		data->setCost_code(resultSet->getString(1));
		data->setCost_name(resultSet->getString(2));
		data->setCost_type_code(resultSet->getString(3));
		return data;
	}
};


#endif // !_DOWNGOODS_MAPPER_#pragma once
