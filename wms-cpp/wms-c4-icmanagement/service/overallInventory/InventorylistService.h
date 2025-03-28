#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei
 @Date: 2025/2/26 11:08

*/
#ifndef _REVIEW_STT_SERVICE_
#define _REVIEW_STT_SERVICE_
#include <list>

#include "domain/query/overallInventory/InventorylistQuery.h"
#include "domain/dto/overallInventory/InventorylistDto.h"
#include "domain/vo/overallInventory/InventorylistVo.h"


/**
 * 盘点管理服务实现
 */
class InventorylistService
{
public:
	// 分页查询所有数据
	InventorylistDto::Wrapper listAll(const InventorylistQuery::Wrapper& query);
	
	// 通过条件查询单个数据
	//GoodsDiffPostListDTO::Wrapper getByCondition(const GoodsDiffPostQuery::Wrapper& query);
	// 保存数据
	//uint64_t saveData(const InventorylistDto::Wrapper& dto);
	 /*// 修改数据
	bool updateData(const SampleDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);*/
};

#endif // !_REVIEW_STT_SERVICE_
