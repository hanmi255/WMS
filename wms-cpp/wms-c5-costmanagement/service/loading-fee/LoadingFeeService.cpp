#include "stdafx.h"
#include"LoadingFeeService.h"
#include"../../dao/loading-fee/LoadingFeeDAO.h"


//分页查询外包装车费
LoadingFeePageDTO::Wrapper LoadingFeeService::pageQueryLoadingFee(const LoadingFeeQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = LoadingFeePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	LoadingFeeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<LoadingFeeDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (LoadingFeeDO sub : result)
	{
		auto dto = LoadingFeeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, fee, Fee, Operator, XOperator, operateDate, OperateDate, orderNo, OrderNo, goods, Goods, goodsName, GoodsName, goodsNum, GoodsNum, goodsWeight, GoodsWeight, feeRMB, FeeRMB, price, Price);
		pages->addData(dto);
	}
	return pages;
}


//导出外包装车费
list<LoadingFeeDO> LoadingFeeService::DownloadLoadingFee(const LoadingFeeQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = LoadingFeePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// 查询数据总条数
	LoadingFeeDAO dao;
	uint64_t count = dao.count(query);
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<LoadingFeeDO> result = dao.selectWithPage(query);
	return result;
}