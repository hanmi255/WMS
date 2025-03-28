#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include "ExpenseTypeDAO.h"
#include "ExpenseTypeMapper.h"
#include <sstream>

inline std::string ExpenseTypeDAO::queryConditionBuilder(const ExpenseTypeQuery::Wrapper& query, SqlParams& params)
{
    stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";
    

    if (query->cost_type_code)
    {
        sqlCondition << " AND `cost_type_code` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->cost_type_code.getValue(""));
    }

    if (query->cost_type_name)
    {
        sqlCondition << " AND `cost_type_name` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->cost_type_name.getValue(""));
    }


	/* if (query->cost_type_del)
	 {
		 sqlCondition << " AND `cost_type_del` =?";
		 SQLPARAMS_PUSH(params, "s", std::string, query->cost_type_del.getValue(""));
	 }*/
    return sqlCondition.str();
}

// 统计数据条数
uint64_t ExpenseTypeDAO::count(const ExpenseTypeQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT COUNT(*) FROM ba_cost_type";
    // 构建查询条件
    sql += queryConditionBuilder(query, params);
    // 执行查询
    return sqlSession->executeQueryNumerical(sql, params);
}

// 分页查询数据 wm_stt_in_goods
std::list<ExpenseTypeDO> ExpenseTypeDAO::selectWithPage(const ExpenseTypeQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT * FROM ba_cost_type";
    // 构建查询条件
    sql += queryConditionBuilder(query, params);
    // 构建分页条件
    sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

    // 执行查询
    ExpenseTypeMapper mapper;
    return sqlSession->executeQuery<ExpenseTypeDO>(sql, mapper, params);
}

// 查询数据---不分页
std::list<ExpenseTypeDO> ExpenseTypeDAO::selectWithConditions(const ExpenseTypeQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT * FROM ba_cost_type";
    // 构建查询条件
    sql += queryConditionBuilder(query, params);
    // 执行查询
    ExpenseTypeMapper mapper;
    return sqlSession->executeQuery<ExpenseTypeDO>(sql, mapper, params);
}

