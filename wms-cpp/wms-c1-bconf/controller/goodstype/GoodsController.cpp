#include "stdafx.h"
#include "GoodsController.h"
#include "service/goodstype/GoodsTypeService.h"

Uint64JsonVO::Wrapper GoodsController::execAddGoodsType(const GoodsTypeAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->code || !dto->name)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->name->empty() || dto->code->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	GoodsTypeService service;
	// 执行数据新增
	bool success = service.saveData(dto, payload);
	if (success) {
		jvo->success(UInt64(1));
	}
	else
	{
		jvo->fail(UInt64(-1));
	}
	//响应结果
	return jvo;
}
