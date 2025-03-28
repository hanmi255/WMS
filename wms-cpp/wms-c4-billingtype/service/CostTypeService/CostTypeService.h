#pragma once
#ifndef _COST_TYPE__SERVICE_
#define _COST_TYPE__SERVICE_
#include <list>
#include "domain/vo/billingtype/CostVO.h"
#include "domain/query/billingtype/CostTypeQuery.h"
#include "domain/dto/billingtype/CostDTO.h"

/**
 *  费用类型服务实现
 */
class CostTypeService
{
public:
	// 分页查询费用类型数据
	CostListPageDTO::Wrapper listAll(const CostTypeQuery::Wrapper& query);
	// 通过ID查询单个费用类型数据
	CostListDTO::Wrapper getById(uint64_t id);
	// 保存费用类型数据
	uint64_t saveData(const  GetCostDTO::Wrapper& dto);
	uint64_t saveData(const  GetCostDTO::Wrapper& dto,const PayloadDTO& payload);
	// 修改费用类型数据
	bool updateData(const  ModifyCostDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};

#endif // !_COST_TYPE__SERVICE_

