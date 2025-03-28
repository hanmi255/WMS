#include "TotalReiceivedFeesService.h"

#include "stdafx.h"
#include "dao/total-reiceived-fees/TotalReiceivedFeesDAO.h"
#include "domain/do/public-do/DayCostDO.h"

TotalReiceivedFeesPageVO::Wrapper TotalReiceivedFeesService::listAll(const TotalReiceivedFeesQuery::Wrapper& query) {
	// 构建返回对象
	auto pages = TotalReiceivedFeesPageVO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	TotalReiceivedFeesDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<DayCostDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (DayCostDO sub : result)
	{
		auto dto = TotalReiceivedFeesVO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, feedate, CostDate, customers, CusCode, customersname, CusName, fees, CostCode, feesname, CostName, tax_exclusiveprice, DayCostBhs, taxinclusiveprice, DayCostHsj, taxamount, DayCostSe, originalprice, DayCostYj, billingquantity, CostSl, unityofquantity, CostUnit);
		pages->addData(dto);
	}
	return pages;
}



vector<vector<string>> TotalReiceivedFeesService::exportAll(const TotalReiceivedFeesQuery::Wrapper& query) {
	TotalReiceivedFeesDAO dao;
	list<DayCostDO> result = dao.selectWithPage(query);
	vector<vector<string>>re_t;
	for (auto& do_t : result) {
		vector<string> col;
		col.emplace_back(do_t.getCostDate());
		col.emplace_back(do_t.getCusCode());
		col.emplace_back(do_t.getCusName());
		col.emplace_back(do_t.getCostCode());
		col.emplace_back(do_t.getCostName());
		col.emplace_back(do_t.getCostSl());
		col.emplace_back(do_t.getCostUnit());
		col.emplace_back(do_t.getDayCostYj());
		col.emplace_back(do_t.getDayCostBhs());
		col.emplace_back(do_t.getDayCostSe());
		col.emplace_back(do_t.getDayCostHsj());
		re_t.push_back(col);
	}
	return re_t;
}