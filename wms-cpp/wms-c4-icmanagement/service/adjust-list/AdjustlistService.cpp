/*
****************************************************************************
    *  @COPYRIGHT NOTICE
    *  @Copyright (c) 2013, kato1
    *  @All rights reserved
    *  @file	 : AdjustlistService.cpp
    *  @version  : ver 1.0
    *  @author   : kato1
    *  @date     : 2025/2/27 14:31
    *  @brief    : brief
****************************************************************************
*/






#include "stdafx.h"
#include "../../dao/adjust-list/AdjustlistDAO.h"
#include "AdjustlistService.h"


ListgoodsPageDTO::Wrapper AdjustlistService::listAll(const ListgoodsQuery1::Wrapper& query)
{
	// 构建返回对象
	auto pages = ListgoodsPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	AdjustlistDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<AdjustlistDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (AdjustlistDO sub : result)
	{
		auto dto = ListgoodsBasePageDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, create_date, CreateDate, goods_qua, GoodsQua, ku_wei_bian_ma, KuWeiBianMa, bin_id, BinId, goods_id, GoodsId, base_goodscount, BaseGoodscount, base_unit, BaseUnit, goods_name, GoodsName, order_id, OrderId, goods_unit, GoodsUnit, cus_code, CusCode);
		pages->addData(dto);
	}
	return pages;
	
}

ListgoodsDetailDTO::Wrapper AdjustlistService::getById(const std::string id)
{
	// 查询数据
	AdjustlistDAO dao;
	auto res = dao.selectById(id);

	// 没有查询到数据
	if (!res)
		return nullptr;

	// 查询到数据转换成DTO
	auto dto = ListgoodsDetailDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, id, Id, create_date, CreateDate, goods_id, GoodsId, order_id, OrderId, goods_unit, GoodsUnit, cus_code, CusCode, goods_qua, GoodsQua, goods_pro_data, GoodsProData, ku_wei_bian_ma, KuWeiBianMa, bin_id, BinId, base_unit, BaseUnit, base_goodscount, BaseGoodscount);
	return dto;

}

bool AdjustlistService::updateData(const ListgoodsadjustDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	AdjustlistDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, GoodsQua, goods_qua, GoodsProData, goods_pro_data, BinId, bin_id, KuWeiBianMa, ku_wei_bian_ma, BaseUnit, base_unit, Id, id);
	// 执行数据修改
	AdjustlistDAO dao;
	return dao.update(data, payload) == 1;

}


