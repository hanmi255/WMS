#include "stdafx.h"
#include "CostTypeController.h"
#include "../../service/CostTypeService/CostTypeService.h"
#include "../ApiDeclarativeServicesHelper.h"

CostJsonVO::Wrapper CostTypeController::execQueryCostTypeListAll(const Int64& id)
{
    // 方法实现：获取所有费用类型
	// 定义返回数据对象
	auto jvo = CostJsonVO::createShared();

	// 参数校验
	// 非空校验
	if (!id)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (id.getValue({}) <= 0)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	CostTypeService service;
	// 执行数据新增
	auto res = service.getById(id.getValue({}));
	jvo->success(res);
	return jvo;
}

CostPageJsonVO::Wrapper CostTypeController::execQueryCostTypeListWithCondition(const  CostTypeQuery::Wrapper& query, const PayloadDTO& payload)
{
    // 方法实现：获取费用类型列表分页
	// 定义一个Service
	CostTypeService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = CostPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper CostTypeController::execGetCostType(const GetCostDTO::Wrapper& dto, const PayloadDTO& payload)
{
    // 方法实现：录入费用类型
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 有效值校验
	if ( dto->cost_code->empty() || dto->cost_name->empty()|| dto->cost_type->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	CostTypeService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto,payload);
	//std::cout << "controller id = " << id << "\n";
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

Uint64JsonVO::Wrapper CostTypeController::execModifyCostType(const ModifyCostDTO::Wrapper& dto)
{
    // 方法实现：修改费用类型


	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->id || dto->id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	CostTypeService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// 响应结果
	return jvo;
}