#pragma once
#include <list>
#include <stdint.h>
//#include "domain/vo/employedstatus/employedVO.h"
//#include "domain/query/employedstatus/employedQuery.h"
#include "domain/dto/goodstype/GoodsTypeDTO.h"

/**
 * 录入产品属性服务实现
 */
class GoodsTypeService
{
public:

	// 保存数据
	uint64_t saveData(const GoodsTypeAddDTO::Wrapper& dto, const PayloadDTO& payload);

};