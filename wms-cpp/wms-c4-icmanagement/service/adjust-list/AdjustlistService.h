#pragma once
/*****************************************************************************
    *  @COPYRIGHT NOTICE
    *  @Copyright (c) 2013, kato1
    *  @All rights reserved
    *  @file	 : AdjustlistService.h
    *  @version  : ver 1.0
    *  @author   : kato1
    *  @date     : 2025/2/27 14:10
    *  @brief    : brief
*****************************************************************************/

#ifndef _ADJUSTLIST_SERVICE_
#define _ADJUSTLIST_SERVICE_



#include <list>
#include "domain/vo/adjust-list/ListgoodsVO.h"
#include "domain/dto/adjust-list/ListgoodsDTO.h"
#include "domain/query/adjust-list/ListgoodsQuery.h"


/**
 * 示例服务实现，演示基础的示例服务实现
 */
class AdjustlistService
{
public:
	// 分页查询所有上架货物数据
    ListgoodsPageDTO::Wrapper listAll(const ListgoodsQuery1::Wrapper& query);
	
    // 查询详细上架货物数据
	ListgoodsDetailDTO::Wrapper getById(const std::string id);
	
	// 修改数据
	bool updateData(const ListgoodsadjustDTO::Wrapper& dto, const PayloadDTO& payload);

};



#endif // !_ADJUSTLIST_SERVICE_
