#include "stdafx.h"
#include "BareaInfoService.h"
#include "dao/districtinfo/BareaInfoDAO.h"

BareaInfoPageDTO::Wrapper BareaInfoService::list(const BareaInfoQuery::Wrapper& query)
{
	auto pages = BareaInfoPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	BareaInfoDAO dao;
	auto list = dao.infoList(query);
	pages->total = list.size();
	if (pages->total <= 0)
	{
		return pages;
	}
	pages->calcPages();

	for (auto sub : list)
	{
		auto dto = BareaInfoDTO::createShared();
		dto->id = sub.getId();
		dto->code = sub.getBarea_code();
		dto->name = sub.getBarea_name();
		dto->rdata = sub.getBarea_rdata();
		pages->addData(dto);
	}
	return pages;
}