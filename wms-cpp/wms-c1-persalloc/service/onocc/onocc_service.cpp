#include "stdafx.h"
#include "onocc_service.h"
#include "../../dao/onocc/onocc_dao.h"

EsPageDTO::Wrapper EsService::listAll(const EsQuery::Wrapper& query)
{
	auto pages = EsPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	EsDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) return pages;

	pages->total = count;
	pages->calcPages();
	list<EsDO> result = dao.selectWithPage(query);

	for (EsDO sub : result)
	{
		auto dto = EsDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,id,Id,pos_sta_code, Pos_Sta_Code, pos_sta_name, Pos_Sta_Name);
		pages->addData(dto);
	}
	return pages;
}
std::string EsService::saveData(const EsAddDTO::Wrapper& dto,const PayloadDTO& payload)
{
	EsDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,Pos_Sta_Code, pos_sta_code, Pos_Sta_Name, pos_sta_name);
	// 执行数据添加
	data.setCreate_Name(payload.getUsername());
	data.setCreate_By(payload.getId());
	data.setSys_Org_Code(payload.getOrgcode());
	data.setSys_Company_Code(payload.getCompanycode());
	EsDAO dao;
	return dao.insert(data);
}
bool EsService::updateData(const EsDTO::Wrapper& dto,const PayloadDTO& payload)
{
	EsDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id,id,Pos_Sta_Code, pos_sta_code, Pos_Sta_Name, pos_sta_name);
	data.setUpdate_Name(payload.getUsername());
	data.setUpdate_By(payload.getId());
	data.setSys_Org_Code(payload.getOrgcode());
	data.setSys_Company_Code(payload.getCompanycode());
	EsDAO dao;
	return dao.update(data);
	return true;
}