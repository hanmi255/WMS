#include "stdafx.h"
#include "InventoryController.h"
#include "../../service/inentorydifference/InventoryPService.h"
#include "../ApiDeclarativeServicesHelper.h"

InventoryPPageJsonVO::Wrapper InventoryController::execQueryAll(const InventoryPquery::Wrapper& query)
{
	// 定义一个Service
	InventoryPService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = InventoryPPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper InventoryController::execAddInv(const InventoryPAddDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->stt_name || !dto->bin_id || !dto->tin_id || !dto->goods_id || !dto->goods_name || !dto->cus_code || !dto->cus_id)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->goods_qua->empty() || dto->stt_qua->empty() || dto->stt_name->empty() || dto->stt_date->empty() || dto->bin_id->empty() || dto->tin_id->empty() || dto->goods_id->empty() || dto->goods_name->empty() || dto->goods_pro_data->empty() || dto->cus_code->empty() || dto->cus_id->empty() || dto->stt_sta->empty())
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	InventoryPService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(String(id));
	}
	else
	{
		jvo->fail(String(id));
	}
	//响应结果
	return jvo;
}
