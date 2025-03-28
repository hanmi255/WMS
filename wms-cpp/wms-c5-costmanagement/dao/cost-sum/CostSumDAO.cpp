#include "stdafx.h"
#include "./CostSumDAO.h"
#include "CostSumMapper.h"
#include <sstream>

std::string CostSumDAO::QueryConditionBuilder(const CostSumQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->datebegin) {

		sqlCondition << " AND cost_data BETWEEN ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->datebegin.getValue(""));
	}
	if (query->dateend) {

		sqlCondition << " AND ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->dateend.getValue(""));
	}
	if (query->client) {

		sqlCondition << " AND cus_code=?";
		SQLPARAMS_PUSH(params, "s", string, query->client.getValue(""));
	}
	if (query->clientname) {

		sqlCondition << " AND cus_name=?";
		SQLPARAMS_PUSH(params, "s", string, query->clientname.getValue(""));
	}
	if (query->cost) {

		sqlCondition << " AND cost_code=?";
		SQLPARAMS_PUSH(params, "s", string, query->cost.getValue(""));
	}
	if (query->costname) {

		sqlCondition << " AND cost_name=?";
		SQLPARAMS_PUSH(params, "s", string, query->costname.getValue(""));
	}
	return sqlCondition.str();
}

std::list<CostSumDO> CostSumDAO::selectWithPage(const CostSumQuery::Wrapper& query)
{
	SqlParams param;
	string sql = "SELECT cost_data,cus_code,cus_name,cost_code,cost_name,cost_sl,cost_unit,yuanj,bhsj,shuie,hansj FROM wv_day_cost_sum";
	sql += QueryConditionBuilder(query, param);
	sql += " LIMIT " + std::to_string(((query->pageIndex-1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	CostSumMapper mapper;
	return sqlSession->executeQuery<CostSumDO>(sql, mapper, param);
}
uint64_t CostSumDAO::count(const CostSumQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM wv_day_cost_sum ";
	// 构建查询条件
	sql += QueryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}