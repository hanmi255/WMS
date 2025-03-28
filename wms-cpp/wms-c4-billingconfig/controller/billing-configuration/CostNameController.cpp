#include "stdafx.h"
#include "CostNameController.h"
#include "../../service/billing-configuration/CostNameService.h"
#include "../ApiDeclarativeServicesHelper.h"

CostNameJsonVO::Wrapper CostNameController::execQueryCostNameListAll(const CostNameQuery::Wrapper& costPageQuery)
{
	
	CostNameService service;
	// 查询数据
	auto result = service.listAll(costPageQuery);
	// 响应结果
	auto jvo = CostNameJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

CostNamePageJsonVO::Wrapper CostNameController::execQueryCostNameListWithCondition(const CostNameQuery::Wrapper& costPageQuery)
{
	CostNameService service;
	// 查询数据
	auto result = service.listAllByPage(costPageQuery);
	// 响应结果
	auto jvo = CostNamePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper CostNameController::execAddCostName(const CostAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();

	if (!dto->cost_code || !dto->cost_name || !dto->cost_type_code)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (dto->cost_code->empty() || dto->cost_name->empty() || dto->cost_type_code->empty())
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	CostNameService service;
	// 执行数据新增
	String resultfail = String("fail");
	String resultsuccess = String("success");
	if (service.saveData(dto,payload)) {
		jvo->success(resultsuccess);
		return jvo;
	}
	else
	{
		jvo->fail(resultfail);
		return jvo;
	}
	return jvo;
}

StringJsonVO::Wrapper CostNameController::execModifyCostName(const CostModifyDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	if (!dto->id)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	CostNameService service;
	// 执行数据修改
	String resultfail = String("fail");
	String resultsuccess = String("success");
	if (service.updateData(dto,payload)) {
		jvo->success(resultsuccess);
		return jvo;
	}
	else
	{
		jvo->fail(resultfail);
		return jvo;
	}
	return jvo;
}