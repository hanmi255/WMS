#include "stdafx.h"
#include "service/tuopandingyi/TPService.h"
#include "dao/tuopandingyi/TPDAO.h"
#include "domain/do/TuopanDO.h"
#include <ctime>

oatpp::List<QueryTPDTO::Wrapper> TPService::queryTP() {
	TPDAO dao;
	auto result = dao.queryTP();
	auto dtoList = oatpp::List<QueryTPDTO::Wrapper>::createShared();
	for (TuopanDO sub : result) {
		auto dto = QueryTPDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, tin_id, TinId);
		dtoList.get() -> push_back(dto);
	}

	return dtoList;
}

std::string TPService::addTP(const AddTPDTO::Wrapper &dto, const PayloadDTO& payload) {
	TPDAO dao;
	TuopanDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, TinId, tin_id, \
		SysOrgCode, sys_org_code, SysCompanyCode, sys_company_code, \
		TinSort, tin_sort, BinId, bin_id, TinStatus, tin_status, BpmStatus, bpm_status);
	auto result = dao.addTP(data);
	return result;
}