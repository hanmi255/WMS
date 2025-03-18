#pragma once
#ifndef _MOVE_SERVICE_
#define _MOVE_SERVICE_
#include <list>
#include "domain/vo/shengchengtuopanzhuanyi/HuoQuKeZhuanYiLieBiaoVO.h"
#include "domain/query/shengchengtuopanzhuanyi/HuoQuKeZhuanYiLieBiaoQuery.h"
#include "domain/dto/shengchengtuopanzhuanyi/HuoQuKeZhuanYiLieBiaoDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class MoveService
{
public:
	// 分页查询所有数据
	HuoQuKeZhuanYiLieBiaoListPageDTO::Wrapper querylist(const HuoQuKeZhuanYiLieBiaoQuery::Wrapper& query);
	
};

#endif // !_MOVE_SERVICE_