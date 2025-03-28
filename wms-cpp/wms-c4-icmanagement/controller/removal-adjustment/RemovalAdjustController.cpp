#include "stdafx.h"
#include "RemovalAdjustController.h"
//#include "../../service/sample/SampleService.h"
#include "../../service/removal-adjustment/RemovalAdjustService.h"
#include "../ApiDeclarativeServicesHelper.h"


RemovalPageJsonVO::Wrapper RemovalController::execQueryRemoval(const RemovalQuery::Wrapper& query, const PayloadDTO& payload)
{
	//分页查询
	// 定义一个Service
	RemovalService service;
	// 实现分页查询数据的服务
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = RemovalPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	//return {};
}
RemovalDetailPageJsonVO::Wrapper RemovalController::execQueryRemovaldetail(const RemovalQuery::Wrapper& query, const PayloadDTO& payload)
{
	auto jvo = RemovalDetailPageJsonVO::createShared();
	//jvo是一个RemovalDetailJsonVO
	RemovalService service;
	auto result = service.getdetail(query);
	//这里的result是一个std::list<RemovalDetailDTO::Wrapper> 类型
	jvo->success(result);

	//响应结果
	return jvo;


	//return {};
}
StringJsonVO::Wrapper RemovalController::execModifyRemoval(const RemovalListDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	
	// 定义一个Service
	RemovalService service;
	// 执行数据修改
	
	String resultfail = String("fail");
	String resultsuccess = String("success");
	if (service.updateData(dto)) {
		jvo->success(resultsuccess);
		return jvo;
	}
	else
	{
		jvo->fail(resultfail);
		return jvo;
	}
	
}