//#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei
 @Date: 2025/2/26 11:08

*/

#include "stdafx.h"
#include "InventorylistService.h"
#include "../../dao/overallInventory/InventorylistDAO.h"
#include "Macros.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"

//..
#define TEST_EXCEL_FN "./" + ZH_WORDS_GETTER("review-stt.excel.path.good-diff-post") + ".xlsx"
#define TEST_EXCEL_SN ZH_WORDS_GETTER("review-stt.excel.sheet.s1")

// 条件分页查询所有数据
InventorylistDto::Wrapper InventorylistService::listAll(const InventorylistQuery::Wrapper& query)
{

	// 构建返回对象
	auto pages = InventorylistDto::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	InventorylistDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<InventorylistDo> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	/*for (InventorylistDo sub : result)
	{
		auto dto = InventorylistDto::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, huozhumingcheng);
		pages->addData(dto);
	}*/
	return pages;
}


//uint64_t InventorylistService::saveData(const InventorylistDto::Wrapper& dto)
//{
//	// 组装DO数据
//	InventorylistDo data;
//	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age);
//	// 执行数据添加
//	InventorylistDAO dao;
//	return dao.insert(data);
//}

// 通过条件分页查询数据
/*GoodsDiffPostListDTO::Wrapper GoodsManageService::getByCondition(const GoodsDiffPostQuery::Wrapper& query)
{
	return {};
}*/