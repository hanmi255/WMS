#include "stdafx.h"
#include "StoreService.h"
#include "dao/cangkudingyi/StoreDAO.h"
#include "domain/GlobalInclude.h"

string getTimeStr() {
	auto now = std::chrono::system_clock::now();
	auto now_c = std::chrono::system_clock::to_time_t(now);
	std::stringstream ss;
	ss << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S");
	return ss.str();
}

string StoreService::addStore(const StoreAddDTO::Wrapper dto, const PayloadDTO& payload)
{
	StoreDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		StoreCode, store_code,
		StoreName, store_name,
		StoreText, store_text);
	data.setCreateName(payload.getRealname());
	data.setCreateBy(payload.getUsername());
	data.setSysOrgCode(payload.getOrgcode());
	data.setSysCompanyCode(payload.getCompanycode());
	data.setCreateDate(getTimeStr());
	StoreDAO dao;
	return dao.add(data);
}

string StoreService::modifyStore(const StoreModifyDTO::Wrapper dto, const PayloadDTO& payload)
{
	StoreDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		Id, id,
		StoreCode, store_code,
		StoreName, store_name,
		StoreText, store_text);
	data.setUpdateName(payload.getRealname());
	data.setUpdateBy(payload.getUsername());
	data.setUpdateDate(getTimeStr());
	StoreDAO dao;
	return dao.modify(data);
}

CangkuListPageDTO::Wrapper StoreService::listAll(const CangkuListQuery::Wrapper& query)
{
	auto pages = CangkuListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	StoreDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	//分页查询数据
	pages->total = count;
	pages->calcPages();
	list<StoreDO> result = dao.selectWithPage(query);

	for (StoreDO data : result)
	{
		auto dto = CangkuListDTO::createShared();
		ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
			Id, id,
			StoreCode, store_code,
			StoreName, store_name,
			StoreText, store_text);
		pages->addData(dto);
	}
	return pages;

}