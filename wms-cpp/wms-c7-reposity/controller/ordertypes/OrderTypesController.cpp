/*
 @Author: nanbowan
*/
#include"stdafx.h"
#include"OrderTypesController.h"
#include "../../service/ordertypes/OrderTypesService.h"

Uint64JsonVO::Wrapper OrderTypesController::execModifyOrd(const ModifyOrderTypeDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	string stdId = dto->id->c_str();
	uint64_t idValue = std::stoull(stdId);
	if (!dto->id || idValue < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	OrderTypesService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(idValue);
	}
	else
	{
		jvo->fail(idValue);
	}
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper OrderTypesController::execDeleteOrd(const oatpp::String& id)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验

	if (!id || id->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	OrderTypesService service;
	string stdId = id->c_str();
	uint64_t idValue = std::stoull(stdId);
	if (service.removeData(id)){
		jvo->success(idValue);
	}
	else
	{
		jvo->fail(idValue);
	}
	// 响应结果
	return jvo;
}


