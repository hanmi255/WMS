#pragma once
#ifndef _ORDER_TYPE_MAPPER_H_
#define _ORDER_TYPE_MAPPER_H_

#include "Mapper.h"
#include "../../domain/do/order_type/OrderTypeDO.h"

class OrderTypeMapper : public Mapper<OrderTypeDO> {
public:
    OrderTypeDO mapper(ResultSet* resultSet) const override
    {
        OrderTypeDO data;
        data.setId(resultSet->getString(1));
        data.setOrderTypeCode(resultSet->getString(2));
        data.setOrderTypeName(resultSet->getString(3));
        return data;
    }
};

class PtrOrderTypeMapper : public Mapper<PtrOrderTypeDO> {
public:
    PtrOrderTypeDO mapper(ResultSet* resultSet) const override
    {
        PtrOrderTypeDO data = std::make_shared<OrderTypeDO>();
        data->setId(resultSet->getString(1));
        data->setOrderTypeCode(resultSet->getString(2));
        data->setOrderTypeName(resultSet->getString(3));
        return data;
    }
};

class OrderTypeNameMapper : public Mapper<OrderTypeNameDO> {
public:
    OrderTypeNameDO mapper(ResultSet* resultSet) const override
    {
        OrderTypeNameDO data;
        data.setId(resultSet->getString(1));
        data.setOrderTypeName(resultSet->getString(2));
        return data;
    }
};

class PtrOrderTypeNameMapper : public Mapper<PtrOrderTypeNameDO> {
public:
    PtrOrderTypeNameDO mapper(ResultSet* resultSet) const override
    {
        PtrOrderTypeNameDO data = std::make_shared<OrderTypeNameDO>();
        data->setId(resultSet->getString(1));
        data->setOrderTypeName(resultSet->getString(2));
        return data;
    }
};

#endif // !_ORDER_TYPE_MAPPER_H_