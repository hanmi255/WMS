#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei
 @Date: 2025/2/26 11:08

*/
#ifndef _GOODS_MANAGE_SERVICE_
#define _GOODS_MANAGE_SERVICE_
#include <list>

#include "domain/vo/goods-manage/GoodsDiffPostVO.h"
#include "domain/dto/goods-manage/GoodsDiffPostDTO.h"
#include "domain/query/goods-manage/GoodsDiffPostQuery.h"


/**
 * 盘点管理服务实现
 */
class GoodsManageService
{
public:
	// 分页查询所有数据
	GoodsDiffPostPageDTO::Wrapper listAll(const GoodsDiffPostQuery::Wrapper& query);
	//差异过账
	bool updateData(const GoodsDiffPostDTO::Wrapper& dto, const PayloadDTO& payload);
	//导出数据
	std::string exportData(const GoodsDiffPostQuery::Wrapper& query);
	// 通过条件查询单个数据
	//GoodsDiffPostListDTO::Wrapper getByCondition(const GoodsDiffPostQuery::Wrapper& query);
	// 保存数据
	/*uint64_t saveData(const SampleAddDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const SampleDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);*/
};

#endif // !_GOODS_MANAGE_SERVICE_
