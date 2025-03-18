#include "stdafx.h"
#include "HuoQuCangWeiShuJuController.h"
#include "service/cangweitu/StoreService.h"

HuoQuCangWeiShuJuJsonVO::Wrapper HuoQuCangWeiShuJuController::execQueryStore(const HuoQuCangWeiShuJuQuery::Wrapper& query)
{
	// 定义一个Service
	StoreService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = HuoQuCangWeiShuJuJsonVO::createShared();
	jvo->data=result;
	return jvo;
}