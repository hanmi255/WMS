#include "stdafx.h"
#include "onocc_controller.h"
#include "../../service/onocc/onocc_service.h"
#include "../ApiDeclarativeServicesHelper.h"


StringJsonVO::Wrapper onocc_controller::execModifyEs(const EsDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	if (!dto->id||!dto->pos_sta_code || !dto->pos_sta_name)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	EsService service;
	// 执行数据新增
	bool up = service.updateData(dto,payload);
	if (up) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(String("update no success"));
	}
	//响应结果
	return jvo;
}
StringJsonVO::Wrapper onocc_controller::execAddEs(const EsAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	if (!dto->pos_sta_code || !dto->pos_sta_name)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	EsService service;
	// 执行数据新增
	std::string id = service.saveData(dto, payload);
	if (id.size()!=0) {
		jvo->success(String(id));
	}
	else
	{
		jvo->fail(String("no insert success"));
	}
	//响应结果
	return jvo;
}
EsPageJsonVO::Wrapper onocc_controller::execQueryEs(const EsQuery::Wrapper& query)
{
	EsService service;
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = EsPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}