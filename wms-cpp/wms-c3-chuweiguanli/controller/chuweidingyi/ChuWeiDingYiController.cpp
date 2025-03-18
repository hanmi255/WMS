#include "stdafx.h"
#include "ChuWeiDingYiController.h"
#include "service/chuweidingyi/CwService.h"

StringJsonVO::Wrapper ChuWeiDingYiController::execAddCW(const AddCWDTO::Wrapper dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	CwService service;
	auto Id = service.addCW(dto, payload);

	if (Id == "failed") {
		jvo->fail(String{ "fail" });
	}
	else {
		jvo->success(String{ Id });
	}
	return jvo;
}
