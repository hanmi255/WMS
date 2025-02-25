#include "stdafx.h"	
#include "controller/cangkudingyi/StoreController.h"
#include "service/cangkudingyi/StoreService.h"
#include <chrono>
#include <iomanip>
#include <sstream>

StringJsonVO::Wrapper StoreController::execAddStore(const StoreAddDTO::Wrapper dto, const PayloadDTO& payload) {
	//return StringJsonVO::Wrapper();
	auto jvo = StringJsonVO::createShared();
	StoreService service;
	auto Id = service.addStore(dto, payload);

	if (Id == "failed") {
		jvo->fail(String{ "fail" });
	}
	else {
		jvo->success(String{ Id });
	}
	return jvo;
}

StringJsonVO::Wrapper StoreController::execModifyStore(const StoreModifyDTO::Wrapper dto, const PayloadDTO& payload)
{
	//return StringJsonVO::Wrapper();
	auto jvo = StringJsonVO::createShared();
	StoreService service;
	auto Id = service.modifyStore(dto, payload);

	if (Id == "failed") {
		jvo->fail(String{ "fail" });
	}
	else {
		jvo->success(String{ Id });
	}
	return jvo;
}
