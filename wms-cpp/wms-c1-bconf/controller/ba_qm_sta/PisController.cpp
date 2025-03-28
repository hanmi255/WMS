#include "stdafx.h"
#include "PisController.h"
#include "../../service/ba_qm_sta/PisService.h"
#include "../ApiDeclarativeServicesHelper.h"

PisPageJsonVO::Wrapper PisController::execQueryPis(const PisQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	PisService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = PisPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper PisController::execAddPis(const PisAddDTO::Wrapper& dto,const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->id || !dto->code || !dto->name)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->code->empty() || dto->name->empty())
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	PisService service;
	// 执行数据新增
	std::string id = service.saveData(dto,payload);
	//std::cout << id << std::endl;
	if (id.size() != 0) { // 成功保存数据返回状态0
		jvo->success(String(id));
	}
	else
	{
		jvo->fail(String("no insert success"));
	}
	//响应结果
	return jvo;
}

StringJsonVO::Wrapper PisController::execModifyPis(const PisDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto->code || !dto->name)
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->code->empty() || dto->name->empty())
	{
		jvo->init(String(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	PisService service;

	// 执行数据修改
	if (service.updateData(dto,payload)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(String("update no success"));
	}
	// 响应结果
	return jvo;
}



//PisJsonVO::Wrapper PisController::execQueryByCode(const String& code)
//{
//	// 定义返回数据对象
//	auto jvo = PisJsonVO::createShared();
//
//	// 参数校验
//	// 非空校验
//	if (code == "")
//	{
//		jvo->init(nullptr, RS_PARAMS_INVALID);
//		return jvo;
//	}
//	 //有效值校验
//	if (code.getValue({}) == 0)
//	{
//		jvo->init(nullptr, RS_PARAMS_INVALID);
//		return jvo;
//	}
//
//	// 定义一个Service
//	PisService service;
//	// 执行数据新增
//	auto res = service.getByCode(code.getValue({}));
//	jvo->success(res);
//
//	//响应结果
//	return jvo;
//}

//PisJsonVO::Wrapper PisController::execQueryBySta(const String& sta)
//{
//	// 定义返回数据对象
//	auto jvo = PisJsonVO::createShared();
//
//	// 参数校验
//	// 非空校验
//	if (sta == "")
//	{
//		jvo->init(nullptr, RS_PARAMS_INVALID);
//		return jvo;
//	}
//	//有效值校验
//	if (sta.getValue({}) == 0)
//	{
//		jvo->init(nullptr, RS_PARAMS_INVALID);
//		return jvo;
//	}
//
//	// 定义一个Service
//	PisService service;
//	// 执行数据新增
//	auto res = service.getByCode(sta.getValue({}));
//	jvo->success(res);
//
//	//响应结果
//	return jvo;
//}