#include "stdafx.h"
#include "BillingNameDAO.h"
#include "BillingNameMapper.h"
#include "../../domain/query/billing-name/BillingNameQuery.h"
#include <sstream>

std::string BillingNameDAO::queryConditionBuilder(const BillingNameQuery::Wrapper& query, SqlParams& params)
{
    std::stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";

    if (query->id) {
        sqlCondition << " AND id = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue(""));
    }
    if (query->cost_code) {
        sqlCondition << " AND cost_code = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->cost_code.getValue(""));
    }
    if (query->cost_name) {
        sqlCondition << " AND cost_name = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->cost_name.getValue(""));
    }
    if (query->cost_type_code) {
        sqlCondition << " AND cost_type_code = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->cost_type_code.getValue(""));
    }
   

    return sqlCondition.str();
}
int BillingNameDAO::batchdelete(const BillingNameDO& uObj)
{
	string sql = "DELETE FROM `ba_cost` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", uObj.getId());
}
//无分页查询所有数据
std::list<BillingNameDO> BillingNameDAO::selectWithConditions(const BillingNameQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT cost_code,cost_name,cost_type_code FROM ba_cost";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	BillingNameMapper mapper;
	return sqlSession->executeQuery<BillingNameDO>(sql, mapper, params);
}
int BillingNameDAO::batchinsert(const BillingNameDO& uObj)
{
    string sql = "INSERT INTO `ba_cost` (`id`,`cost_code`, `cost_name`, `cost_type_code`) VALUES (?,?,?,?)";
    return sqlSession->executeInsert(sql, "%s%s%s%s",uObj.getId(),uObj.getCost_code(),uObj.getCost_name(),uObj.getCost_type_code());
      
}