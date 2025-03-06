#include "stdafx.h"
#include "TuopanController.h"
#include "../../service/tuopandingyi/TuopanService.h"
#include "../../domain/vo/tuopandingyi/TuopanVO.h"




TuopanPageJsonVO::Wrapper TuopanController::execQueryTuopan(const TuopanQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	TuopanService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = TuopanPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper TuopanController::execModifyTuopan(const TuopanDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->id )
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	TuopanService service;
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

StringJsonVO::Wrapper TuopanController::execRemoveTuopan(const DeleteTuopanDTO::Wrapper& idlist)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!idlist)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	TuopanService service;

	// 执行数据删除
	bool res = service.removeData(idlist->id);
	if (res) {
		jvo->init("success", RS_SUCCESS);
	}
	else
	{
		jvo->init("fail", RS_FAIL);
	}
	
	// 响应结果
	return jvo;
}
