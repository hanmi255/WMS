#include "stdafx.h"
#include "ActTypeController.h"
#include "../../service/act_type/ActTypeService.h"
#include "../ApiDeclarativeServicesHelper.h"


ActTypePageJsonVO::Wrapper ActTypeController::execQueryActType(const ActTypeQuery::Wrapper& query)
{
	// 定义一个Service
	ActTypeService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ActTypePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper ActTypeController::execAddActType(const ActTypeBaseDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->act_type_code || !dto->act_type_name || !dto->oper_step_code)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->act_type_code->empty() || dto->act_type_name->empty() || dto->oper_step_code->empty())
	{
        jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ActTypeService service;
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