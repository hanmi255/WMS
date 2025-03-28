#include "stdafx.h"
#include <sstream>
#include "EnterpirseStatusDAO.h"
#include "EnterpirseStatusMapper.h"
#include "stdafx.h"

std::string EnterpriseStatusDAO::queryConditionBuilder(const GetEnterpriseStatusQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->name) {

		sqlCondition << " AND `name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue(""));
	}
	if (query->code) {

		sqlCondition << " AND code=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->code.getValue(""));
	}
	if (query->id) {

		sqlCondition << " AND id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue(""));
	}
	if (query->ban) {

		sqlCondition << " AND ban=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->ban.getValue(""));
	}
	return sqlCondition.str();
}

std::list<CustomerStatusDO> EnterpriseStatusDAO::selectWithPage(const GetEnterpriseStatusQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT cus_sta_name, cus_sta_code,id,cus_sta_del FROM jeewms.ba_cus_sta ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	EnterpriseStatusMapper mapper;
	return sqlSession->executeQuery<CustomerStatusDO>(sql, mapper, params);
}

uint64_t EnterpriseStatusDAO::count(const GetEnterpriseStatusQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM jeewms.ba_cus_sta ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

uint64_t EnterpriseStatusDAO::insert(const CustomerStatusDO& iObj)
{
	string sql = "INSERT INTO `ba_cus_sta` (cus_sta_name, cus_sta_code,id,cus_sta_del) VALUE(?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s", iObj.getName(), iObj.getCode(), iObj.getId(),iObj.getBan());
}