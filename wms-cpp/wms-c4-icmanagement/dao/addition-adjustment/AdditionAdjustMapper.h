#pragma once
#ifndef _ADDITION_MAPPER_
#define _ADDITION_MAPPER_

#include "Mapper.h"
//#include "../../domain/do/sample/SampleDO.h"
#include "../../domain/do/addition-adjustment/AdditionDO.h"
/**
 * 示例表字段匹配映射
 */
class AdditionMapper : public Mapper<AdditionDO>
{
public:
	//ResultSet通常是用来获取数据库的每个字段
	AdditionDO mapper(ResultSet* resultSet) const override
	{
		AdditionDO data;
		//用data这个类将数据库的每一个字段给包裹起来
		data.setId(resultSet->getString(1));
		data.setOrder_id(resultSet->getString(2));
		data.setGoods_id(resultSet->getString(3));
		data.setGoods_name(resultSet->getString(4));
		//data.setGoods_qua(resultSet->getString(5));
		return data;
	}
};


/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrAdditionMapper : public Mapper<PtrAdditionDO>
{
public:
	PtrAdditionDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<AdditionDO>();
		data->setId(resultSet->getString(1));
		data->setOrder_id(resultSet->getString(2));
		data->setGoods_id(resultSet->getString(3));
		data->setGoods_name(resultSet->getString(4));
		//data->setGoods_qua(resultSet->getString(5));
		return data;
	}
};



#endif // !_SAMPLE_MAPPER_
