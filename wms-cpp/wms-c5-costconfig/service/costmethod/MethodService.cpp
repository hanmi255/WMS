#include "stdafx.h"
#include "MethodService.h"


MethodPageDTO::Wrapper MethodService::listAll(const BillmethodQuery::Wrapper& query)
{
	auto pages= MethodPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;
	MethodDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	pages->total = count;
	pages->calcPages();
	list<CostwayDO> result = dao.selectWithPage(query);
	for (CostwayDO sub : result)
	{
		auto dto = MethodDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, pronut_code, Pronut_code, pronut_name, Pronut_name);
		pages->addData(dto);
	}
	return pages;
}
string MethodService:: addData(const MethodAddDTO::Wrapper& dto)
{
	CostwayDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data,dto, Pronut_code,pronut_code,Pronut_name,pronut_name);
	MethodDAO dao;
	return dao.insert(data);
}

bool MethodService::updateData(const MethodDTO::Wrapper& dto)
{
	CostwayDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id , id ,Pronut_code,pronut_code,Pronut_name,pronut_name);
	MethodDAO  dao;
	if (dao.update(data) >= 1)return true;
	return false;
}

MethodPageDTO::Wrapper MethodService::qall(const BillmethodQueryomit::Wrapper& query)
{
	MethodDAO dao;
	auto pages = MethodPageDTO::createShared();
    auto result=dao.qalldao();
	for (CostwayDO sub : result)
	{
		auto dto = MethodDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, pronut_code, Pronut_code, pronut_name, Pronut_name);
		pages->addData(dto);
	}
	return pages;
}
