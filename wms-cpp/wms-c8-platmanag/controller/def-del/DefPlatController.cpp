#include "stdafx.h"
#include "DefPlatController.h"
#include "../../service/def-plat/DefPlatService.h"
#include "../ApiDeclarativeServicesHelper.h"
Uint64JsonVO::Wrapper DefPlatController::execDelPlat(const String& id)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (id == "")
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	DefPlatService service;
	// 执行数据删除
	if (service.DefDelData(id)) {
		jvo->success(1);
	}
	else
	{
		jvo->fail(3);
	}
	// 响应结果
	return jvo;
}
StringJsonVO::Wrapper DefPlatController::execPutPlat(const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	// 定义一个Service
	DefPlatService service;
	// 执行数据导出
	string result = service.DefPutData(payload);
	if (!result.empty()) {
		jvo->success(result);
	}
	else {
		jvo->fail(result);
	}
	return jvo;
}
Uint64JsonVO::Wrapper DefPlatController::execEditPlat(const DefEditDto::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (dto->id == "")
	{
		//std::cout << dto->id << dto->id_ << std::endl;
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	DefPlatService service;
	// 执行数据修改
	if (service.DefEditData(dto, payload)) {
		jvo->success(1);
	}
	else
	{
		jvo->fail(3);
	}
	// 响应结果
	return jvo;
}
