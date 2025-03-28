#include "stdafx.h"
#include "AdditionAdjustController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/addition-adjustment/AdditionAdjustService.h"
StringJsonVO::Wrapper AdditionController::execbatchAddition(const AdditionBatchDTO::Wrapper& batchdto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	string resultfail = string("fail");
	string resultsuccess = string("success");
	////// 参数校验
	if (!batchdto || !batchdto->dtoList || batchdto->dtoList->empty()) {
		jvo->fail(resultfail);
		return jvo;
	}
	// 定义一个service
	AdditionService service;
	// 执行数据修改
	if (service.updateData(batchdto)) {
		jvo->success(resultsuccess);
		return jvo;
	}
	else
	{
		jvo->fail(resultfail);
		return jvo;
	}

	
}