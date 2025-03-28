#include "stdafx.h"
#include "controller/baworkst/BaWorkStController.h"
#include "../../service/baworkst/BaWorkStService.h"
#include "../ApiDeclarativeServicesHelper.h"


BaWorkStPageJsonVO::Wrapper BaWorkStController::execQueryBaWorkSt(const BaWorkStQuery::Wrapper& query, const PayloadDTO& payload) {
	BaWorkStService service;
	auto result = service.listAll(query);
	auto jvo = BaWorkStPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper BaWorkStController::execAddBaWorkSt(const BaWorkStAddDTO::Wrapper& dto, const PayloadDTO& payload) {
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	//非空校验
	if ( !dto->work_sta_code || !dto->work_sta_name)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}


	// 定义一个Service
	BaWorkStService service;
	// 执行数据新增
	std::string id = service.saveData(dto,payload);
	if (id.size() !=  0) {
		jvo->success(String(id));
	}
	else
	{
		jvo->fail(String(id));
	}
	//响应结果
	return jvo;
}

StringJsonVO::Wrapper BaWorkStController::execModifyBaWorkSt(const BaWorkStChangeDTO::Wrapper& dto, const PayloadDTO& payload) {
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if ( !dto->work_sta_code || !dto->work_sta_name)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	BaWorkStService service;
	// 执行数据修改
	std::string id = service.updateData(dto, payload);
	if (id.size() != 0) {
		jvo->success(String(id));
	}
	else
	{
		jvo->fail(String(-1));
	}

	// 响应结果
	return jvo;
}