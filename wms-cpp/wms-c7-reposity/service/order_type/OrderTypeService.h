#pragma once
#ifndef _ORDER_TYPE_SERVICE_H_
#define _ORDER_TYPE_SERVICE_H_
#include <list>
#include "../../domain/vo/order_type/OrderTypeVo.h"
#include "../../domain/query/order_type/OrderTypeQuery.h"
#include "../../domain/dto/order_type/OrderTypeDTO.h"

class OrderTypeService
{
public:
	// 查询订单类型名称列表
	OrderTypeNamePageDTO::Wrapper listName(const PageQuery::Wrapper& query);
	// 分页查询所有数据
	OrderTypePageDTO::Wrapper listAll(const OrderTypeQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const OrderTypeAddDTO::Wrapper& dto, const PayloadDTO& payload);

};

#endif //! _ORDER_TYPE_SERVICE_H_