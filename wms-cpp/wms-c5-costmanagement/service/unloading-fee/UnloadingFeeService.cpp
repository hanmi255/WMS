#include "stdafx.h"
#include"UnloadingFeeService.h"
#include"../../dao/unloading-fee/UnloadingFeeDAO.h"
#include"../../domain/dto/unloading-fee/UnloadingFeeDTO.h"
#include"../../domain/query/unloading-fee/UnloadingFeeQuery.h"

//分页查询外包卸货费
UnloadingFeePageDTO::Wrapper UnloadingFeeService::pageQueryUnloadingFee(const UnloadingFeeQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = UnloadingFeePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	UnloadingFeeDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<UnloadingFeeDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (UnloadingFeeDO sub : result)
	{
		auto dto = UnloadingFeeDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, fee, Fee, acceptor, Acceptor, acceptDate, AcceptDate, orderNo, OrderNo, goods, Goods, goodsName, GoodsName, unloadingNum, UnloadingNum, unloadingWeight, UnloadingWeight, feeRMB, FeeRMB, price, Price);
		pages->addData(dto);
	}
	return pages;
}

//导出外包卸货费
list<UnloadingFeeDO> UnloadingFeeService::DownloadUnloadingFee(const UnloadingFeeQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = UnloadingFeePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// 查询数据总条数
	UnloadingFeeDAO dao;
	uint64_t count = dao.count(query);
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	//返回要到出的数据
	list<UnloadingFeeDO> result = dao.selectWithPage(query);
	return result;
}