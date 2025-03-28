#include "stdafx.h"
#include <sstream>
#include "MethodDAO.h"
#include "MethodMapper.h"
std::string MethodDAO::queryConditionBuilder(const BillmethodQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->pronut_code) {

		sqlCondition << " AND `pronut_code`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->pronut_code.getValue(""));
	}
	if (query->pronut_name) {

		sqlCondition << " AND pronut_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->pronut_name.getValue(""));
	}
	return sqlCondition.str();
}
uint64_t MethodDAO::count(const BillmethodQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM ba_pronut_method ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}
std::list<CostwayDO> MethodDAO::selectWithPage(const BillmethodQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT * FROM ba_pronut_method ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	// 执行查询
	MethodMapper mapper;
	return sqlSession->executeQuery<CostwayDO>(sql, mapper, params);
}
string MethodDAO::insert(const MethodDO& iObj)
{
	std::string query = "SELECT * FROM ba_pronut_method WHERE CAST(id AS SIGNED) = (SELECT MAX(CAST(id AS SIGNED)) FROM ba_pronut_method);";
	MethodMapper mapper;
	auto res=sqlSession->executeQueryOne<MethodDO>(query,mapper);
	auto t=std::to_string(atoi(res.getId().c_str())+1);
	string sql = "INSERT INTO `ba_pronut_method` (`id`,`pronut_code`,`pronut_name`) VALUES (?, ?, ?)";
	std::to_string(sqlSession->executeInsert(sql, "%s%s%s",t,iObj.getPronut_code(), iObj.getPronut_name()));
	return t;
}

int MethodDAO::update(const MethodDO& uObj)
{
	string sql = "UPDATE `ba_pronut_method` SET `pronut_code`=?, `pronut_name`=? WHERE `id`=?";
    return sqlSession->executeUpdate(sql, "%s%s%s", uObj.getPronut_code(), uObj.getPronut_name(), uObj.getId());
}

std::list<CostwayDO> MethodDAO::qalldao()
{
	string sql = "SELECT * FROM ba_pronut_method ";
	MethodMapper mapper;
	auto res=sqlSession->executeQuery<MethodDO>(sql, mapper);
	return res;
}
