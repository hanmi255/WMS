#include "stdafx.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "MethodController.h"
#include "service/costmethod/MethodService.h"

MethodPageJsonVO::Wrapper MethodController::execQuery(const BillmethodQuery::Wrapper& query, const PayloadDTO& payload)
{
	MethodService service;
	auto result = service.listAll(query);
	auto jvo= MethodPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
MethodPageJsonVO::Wrapper MethodController::execQueryall(const BillmethodQueryomit::Wrapper& query)
{
	auto jvo = MethodPageJsonVO::createShared();
	MethodService service;
	jvo->success(service.qall(query));
	return jvo;
}
StringJsonVO::Wrapper MethodController::execAddme(const MethodAddDTO::Wrapper& dto)
{
	auto jvo=StringJsonVO::createShared();
	if (!dto->pronut_code || !dto->pronut_name)
	{
		jvo->data = "ERROR";
		jvo->fail("ERROR");
		return jvo;
	}
	MethodService service;
	string p = service.addData(dto);
	if (atoi(p.c_str()) > -1)
	{
        jvo->data = p;
		jvo->success("SUCCESS :ID ="+p);
	}
	else
	{
		jvo->data = "FAIL";
		jvo->fail(("FAIL"));
		return jvo;
	}
	return jvo;
}
StringJsonVO::Wrapper MethodController::execModifyme(const MethodDTO::Wrapper& dto)
{
	auto jvo = StringJsonVO::createShared();
	if (!dto->id || !dto->pronut_code || !dto->pronut_name|| (atoi(dto->id.get()->c_str()) < 0))
	{
		jvo->data = "ERROR";
		jvo->fail("ERROR");
		return jvo;
	}
    MethodService service;
	if (service.updateData(dto))
	{
		jvo->data = "SUCCESS";
		jvo->success("SUCCESS");
		return jvo;
	}
	else
	{
		jvo->data = "FAIL";
		jvo->fail("FAIL");
		return jvo;
	}
	return jvo;
}

