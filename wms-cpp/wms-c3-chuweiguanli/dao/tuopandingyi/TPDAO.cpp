#include "stdafx.h"
#include "dao/tuopandingyi/TPDAO.h"
#include "dao/tuopandingyi/QueryTPMapper.h"
#include <sstream>
#include "id/UuidFacade.h"
#include <string>

std::list<TuopanDO> TPDAO::queryTP() {
	SqlParams params;
	string sql = "SELECT id, tin_id FROM wm_tuopan";
	QueryTPMapper mapper;

	return sqlSession->executeQuery<TuopanDO>(sql, mapper, params);
}

std::string TPDAO::addTP(const TuopanDO &iObj) {
	SqlParams params;
	string sql = "INSERT INTO `wm_tuopan` (`id`, `tin_id`, `sys_org_code`, `sys_company_code`, `tin_sort`, `bin_id`, `tin_status`, `bpm_status`) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
	UuidFacade uf;
	auto id = uf.genUuid();
	auto result = sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s", id, iObj.getTinId(), iObj.getSysOrgCode(), iObj.getSysCompanyCode(), iObj.getTinSort(), iObj.getBinId(), iObj.getTinStatus(), iObj.getBpmStatus());
	std::cout << result << std::endl;
	if (result == -1) {
		return "";
	}
	return id;
}