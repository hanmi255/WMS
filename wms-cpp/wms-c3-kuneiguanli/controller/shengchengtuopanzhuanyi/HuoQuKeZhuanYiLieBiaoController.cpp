#include "stdafx.h"
#include "HuoQuKeZhuanYiLieBiaoController.h"
#include "service/shengchengtuopanzhuanyi/MoveService.h"

HuoQuKeZhuanYiLieBiaoPageJsonVO::Wrapper HuoQuKeZhuanYiLieBiaoController:: execQueryAll(const HuoQuKeZhuanYiLieBiaoQuery::Wrapper& query)
{
	// 定义一个Service
	MoveService service;
	// 查询数据
	auto result = service.querylist(query);
	// 响应结果
	auto jvo = HuoQuKeZhuanYiLieBiaoPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}