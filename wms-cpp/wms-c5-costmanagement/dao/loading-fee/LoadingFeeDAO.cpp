#include "stdafx.h"
#include"dao/loading-fee/LoadingFeeDAO.h"
#include"LoadingFeeMapper.h"

//查询条件构建器
std::string LoadingFeeDAO::queryConditionBuilder(const LoadingFeeQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->Operator) {

		sqlCondition << " AND create_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->Operator.getValue(""));
	}
	if (query->operateDate_begin) {

		sqlCondition << " AND create_date BETWEEN ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->operateDate_begin.getValue(""));
	}
	if (query->operateDate_end) {

		sqlCondition << " AND ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->operateDate_end.getValue(""));
	}
	if (query->orderNo) {

		sqlCondition << " AND order_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->orderNo.getValue(""));
	}
	if (query->goods) {
		sqlCondition << " AND goods_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods.getValue(""));
	}
	return sqlCondition.str();
}

//统计数据条数
uint64_t LoadingFeeDAO::count(const LoadingFeeQuery::Wrapper& query)
{
	SqlParams params;
	//使用视图查询
	string sql = "SELECT COUNT(*) FROM vw_loading_fee ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

//分页查询外包装车费
std::list<LoadingFeeDO> LoadingFeeDAO::selectWithPage(const LoadingFeeQuery::Wrapper& query)
{
	SqlParams params;
	//使用视图查询
	string sql = "SELECT * FROM vw_loading_fee ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	// 执行查询
	LoadingFeeMapper mapper;
	return sqlSession->executeQuery<LoadingFeeDO>(sql, mapper, params);
}