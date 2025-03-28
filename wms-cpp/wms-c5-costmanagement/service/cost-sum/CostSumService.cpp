#include "stdafx.h"
#include"CostSumService.h"
#include"../../dao/cost-sum/CostSumDAO.h"
#include "../../domain/dto/cost-sum-dto/CostSumDTO.h"
#include "Macros.h"

CostSumPageDTO::Wrapper CostSumService::listall(const CostSumQuery::Wrapper& query) {
	auto pages = CostSumPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	CostSumDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	pages->total = count;
	pages->calcPages();
	list<CostSumDO> result = dao.selectWithPage(query);
	for (CostSumDO sub: result)
	{
		auto dto = CostSumBaseDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto,sub,costdate,cost_date,client,client_c,clientname,client_name,cost,cost_c,costname,cost_name,number,Number,unit,Unit,orgprice,org_price,notax,no_tax,tax,Tax,taxprice,tax_price);
		pages->addData(dto);
	}
	return pages;
}
list<CostSumDO> CostSumService::exportdata(const CostSumQuery::Wrapper& query)
{
	auto pages = CostSumPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	// 查询数据总条数
	CostSumDAO dao;
	uint64_t count = dao.count(query);
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<CostSumDO> result = dao.selectWithPage(query);
	return result;
}