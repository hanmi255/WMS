/*
* Author: laughter
*/
#include "stdafx.h"
#include "CompanyattrController.h"
#include "../../service/companyattr/CompanyattrService.h"

CompanyattrPageJsonVO::Wrapper CompanyattrController::execQueryAll(const CompanyattrQuery::Wrapper& query, const PayloadDTO& payload) {
	// 定义一个Service
	CompanyattrService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = CompanyattrPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
Uint64JsonVO::Wrapper CompanyattrController::execModify(const CompanyattrIdListDTO::Wrapper& dto, const PayloadDTO& payload) {
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->id||!dto->com_type_code || !dto->com_type_name)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	CompanyattrService service;
	// 执行数据修改
	if (service.updateData(dto,payload)) {
		jvo->success(1);
	}
	else
	{
		jvo->fail(-1);
	}
	// 响应结果
	return jvo;
}
Uint64JsonVO::Wrapper CompanyattrController::execAdd(const CompanyattrListDTO::Wrapper& dto, const PayloadDTO& payload) {
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->com_type_code || !dto->com_type_name)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	//// 有效值校验
	//if (dto->age < 0 || dto->name->empty() || dto->sex->empty())
	//{
	//	jvo->init(UInt64(-1), RS_PARAMS_INVALID);
	//	return jvo;
	//}

	// 定义一个Service
	CompanyattrService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto,payload);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}