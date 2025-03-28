#include "stdafx.h"
#include "OrderTypeController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/order_type/OrderTypeService.h"

OrderTypeNameVO::Wrapper OrderTypeController::execQueryNameOrderType(const PageQuery::Wrapper& query)
{
	// 定义一个Service
	OrderTypeService service;
	// 查询数据
	auto result = service.listName(query);
	// 响应结果
	auto jvo = OrderTypeNameVO::createShared();
	jvo->success(result);
	return jvo;
}

OrderTypePageJsonVO::Wrapper OrderTypeController::execQueryOrderType(const OrderTypeQuery::Wrapper& query)
{
	// 定义一个Service
	OrderTypeService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = OrderTypePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper OrderTypeController::addOrderType(const OrderTypeAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->order_type_code || !dto->order_type_name) 
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (dto->order_type_code->empty() || dto->order_type_name->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	OrderTypeService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto, payload);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}