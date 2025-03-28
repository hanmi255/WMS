#include"stdafx.h"
#include"EnterpriseStatusController.h"
#include"../../service/enterprisestatus/EnterpriseStatusService.h"
#include "../ApiDeclarativeServicesHelper.h"

EnterprisePageJsonVO::Wrapper EnterpriseController::execQueryAll(const EnterpriseQuery::Wrapper& query)
{
	// 定义一个Service
	EnterpriseStatusService service;
	// 查询数据
	auto result = service.queryAll(query);
	// 响应结果
	auto jvo = EnterprisePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	
}

EnterpriseJsonVO::Wrapper EnterpriseController::execQueryForList()
{
	// 定义返回数据对象
	auto jvo = EnterpriseJsonVO::createShared();
	EnterpriseStatusService service;
	auto data = service.queryForList();
	
	if (!data) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	else {
		jvo->success(data);
	}

	return jvo;
	
}