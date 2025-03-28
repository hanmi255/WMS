#pragma once
#ifndef _EXPENSETYPEDAO_
#define _EXPENSETYPEDAO_
#include "BaseDAO.h"
#include "../../domain/do/expensetype/ExpenseTypeDO.h"
#include "../../domain/query/expensetype/ExpenseTypeQuery.h"

/**
 * 库存表数据库操作实现
 */
class ExpenseTypeDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    ListGoodsDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const ListgoodsQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据ListgoodsQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const ExpenseTypeQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const ExpenseTypeQuery::Wrapper& query);
	// 分页查询数据
	std::list<ExpenseTypeDO> selectWithPage(const ExpenseTypeQuery::Wrapper& query);
	// 查询数据---不分页
	std::list<ExpenseTypeDO> selectWithConditions(const ExpenseTypeQuery::Wrapper& query);
};
#endif // !_EXPENSETYPEDAO_
