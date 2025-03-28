/*
 Copyright Zero One Star. All rights reserved.

 @Author: 圣少游
 @Date: 2025/2/22 11:36:29

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#include "stdafx.h"
#include <list>
#include "MovingBinService.h"
#include "../../dao/moving-bin/MovingBinDAO.h"
#include "../../domain/do/moving-bin/MovingBinDO.h"
#include "Macros.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"

MovingBinPageDTO::Wrapper MovingBinService::listAll(const MovingBinQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = MovingBinPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	MovingBinDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<MovingBinDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (MovingBinDO sub : result)
	{
		auto dto = MovingBinListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, bin_id, BinId, tin_id, TinId, goods_id, GoodsId, goods_name, GoodsName, goods_specification, GoodsSpecification, goods_pro_date, GoodsProDate, save_date, SaveDate);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto,sub, due_date, DueDate, total_stock, TotalStock, last_pick_time, LastPickTime, avail_stock, AvailStock, to_be_taken_down, ToBeTakenDown, goods_unit, GoodsUnit)
		pages->addData(dto);
	}
	return pages;
}


list<MovingBinDO> MovingBinService::exportData(const MovingBinQuery::Wrapper& query)
{
	MovingBinDAO dao;

	list<MovingBinDO> result = dao.selectWithConditions(query);

	return result;
	
}
