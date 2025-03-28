#include "stdafx.h"
#include "CompanyController.h"
#include "service/company-conf/CompanyInfoService.h"


CompanyPageJsonVO::Wrapper CompanyController::execQueryALL(const CompanyInfoQuery::Wrapper& query)
{
	// 定义一个Service
	CompanyInfooService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = CompanyPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}


CompanyInfoVOJsonVO::Wrapper CompanyController::execQueryDETAIL(const Int64& id)
{
	// 定义返回数据对象
	auto jvo = CompanyInfoVOJsonVO::createShared();
	// 定义一个Service
	CompanyInfooService service;
	// 执行数据新增
	auto res = service.getById(id.getValue({}));
	jvo->success(res);

	// 响应结果
	return jvo;
}

