#include "stdafx.h"
#include "TPController.h"
#include "service/tuopandingyi/TPService.h"

QueryTPListJsonVO::Wrapper TPController::execQueryTP(){
	TPService service;
	auto result = service.queryTP();
	auto jvo = QueryTPListJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper TPController::execAddTP(const AddTPDTO::Wrapper &dto, const PayloadDTO& payload) {
	TPService service;
	auto id = service.addTP(dto, payload);
	auto jvo = StringJsonVO::createShared();
	jvo->success(id);
	return jvo;
}
