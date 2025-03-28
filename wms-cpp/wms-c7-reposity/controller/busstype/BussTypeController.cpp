#include "stdafx.h"
#include "BussTypeController.h"
#include "../../service/busstype/BussTypeService.h"
#include "../ApiDeclarativeServicesHelper.h"


BussTypePageJsonVO::Wrapper BussTypeController::execQueryBussType(const BussTypeQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	BussTypeService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = BussTypePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
Uint64JsonVO::Wrapper BussTypeController::execAddBussType(const BussTypeAddDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	if (!dto->buss_type_code || !dto->buss_type_name || !dto->buss_type_text)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->buss_type_code->empty() || dto->buss_type_name->empty() || dto->buss_type_text->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	BussTypeService service;
	// 执行数据新增
	uint64_t res = service.saveData(dto);
	if (res > 0) {
		jvo->success(UInt64(res));
	}
	else
	{
		jvo->fail(UInt64(res));
	}
	//响应结果
	return jvo;
}
Uint64JsonVO::Wrapper BussTypeController::execModifyBussType(const BussTypeAddDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	string stdId = dto->id->c_str();
	uint64_t resultId = std::stoull(stdId);
	if (!dto->id || resultId < 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	BussTypeService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(resultId);
	}
	else
	{
		jvo->fail(resultId);
	}
	// 响应结果
	return jvo;
}