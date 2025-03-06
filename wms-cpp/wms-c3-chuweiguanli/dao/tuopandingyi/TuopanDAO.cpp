#include "stdafx.h"
#include "TuopanDAO.h"
#include <sstream>
#include "TuopanMapper.h"




std::string TuopanDAO::queryConditionBuilder(const TuopanQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->tin_id) {

		sqlCondition << " AND tin_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->tin_id.getValue(""));
	}
	if (query->tin_sort) {

		sqlCondition << " AND tin_sort=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->tin_sort.getValue(""));
	}
	if (query->bin_id) {

		sqlCondition << " AND bin_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->bin_id.getValue(""));
	}
	if (query->tin_status) {

		sqlCondition << " AND tin_status=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->tin_status.getValue(""));
	}
	if (query->bpm_status) {

		sqlCondition << " AND bpm_status=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->bpm_status.getValue(""));
	}
	if (query->sys_org_code) {

		sqlCondition << " AND sys_org_code=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->sys_org_code.getValue(""));
	}
	if (query->sys_company_code) {

		sqlCondition << " AND sys_company_code=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->sys_company_code.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t TuopanDAO::count(const TuopanQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM wm_tuopan ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<TuopanDO> TuopanDAO::selectWithPage(const TuopanQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT tin_id,tin_sort,bin_id,tin_status,bpm_status,sys_org_code,sys_company_code,id	FROM wm_tuopan ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	TuopanMapper mapper;
	return sqlSession->executeQuery<TuopanDO>(sql, mapper, params);
}

int TuopanDAO::update(const TuopanDO& uObj)
{
	string sql = "UPDATE `wm_tuopan` SET `tin_id`=?, `tin_sort`=?, `bin_id`=?, `tin_status`=?, `bpm_status`=?, `sys_org_code`=?, `sys_company_code`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s", uObj.getTinId(), uObj.getTinSort(), uObj.getBinId(), uObj.getTinStatus(),uObj.getBpmStatus(), uObj.getSysOrgCode(), uObj.getSysCompanyCode(), uObj.getId());
}

int TuopanDAO::deleteById(string id)
{
	string sql = "DELETE FROM `wm_tuopan` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}
