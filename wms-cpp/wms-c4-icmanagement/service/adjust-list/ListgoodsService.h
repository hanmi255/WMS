#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei
 @Date: 2025/3/4 11:08

*/
#ifndef _LIST_GOODS_SERVICE_
#define _LIST_GOODS_SERVICE_
#include <list>

#include "domain/vo/adjust-list/ListgoodsVO.h"
#include "domain/dto/adjust-list/ListgoodsDTO.h"
#include "domain/query/adjust-list/ListgoodsQuery.h"


/**
 * 盘点管理服务实现
 */
class ListGoodsService
{
public:
	std::string exportData(const ExportDataQuery::Wrapper& query);
};

#endif // !_LIST_GOODS_SERVICE_
