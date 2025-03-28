#pragma once
#ifndef _INVENTORYP_SERVICE_
#define _INVENTORYP_SERVICE_
#include <list>
#include "domain/vo/inentorydifference/InventoryPVO.h"
#include "domain/query/inentorydifference/InventoryPquery.h"
#include "domain/dto/inentorydifference/InventoryPDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class InventoryPService
{
public:
	// 分页查询所有数据
	InventoryPPageDTO::Wrapper listAll(const InventoryPquery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const InventoryPAddDTO::Wrapper& dto);
};

#endif // !_INVENTORYP_SERVICE_

