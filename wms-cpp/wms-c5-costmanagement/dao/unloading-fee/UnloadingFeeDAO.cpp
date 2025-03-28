#include "stdafx.h"
#include"UnloadingFeeDAO.h"
#include"UnloadingFeeMapper.h"
#include <sstream>


//查询条件构建器
std::string UnloadingFeeDAO::queryConditionBuilder(const UnloadingFeeQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->acceptor) {

		sqlCondition << " AND create_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->acceptor.getValue(""));
	}
	if (query->acceptDate_begin) {

		sqlCondition << " AND create_date BETWEEN ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->acceptDate_begin.getValue(""));
	}
	if (query->acceptDate_end) {

		sqlCondition << " AND ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->acceptDate_end.getValue(""));
	}
	if (query->orderNo) {

		sqlCondition << " AND im_notice_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->orderNo.getValue(""));
	}
	if (query->goods) {
		sqlCondition << " AND goods_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods.getValue(""));
	}
	return sqlCondition.str();
}

//统计数据条数
uint64_t UnloadingFeeDAO::count(const UnloadingFeeQuery::Wrapper& query)
{
	SqlParams params;
	//使用视图查询
	string sql = "SELECT COUNT(*) FROM vw_unloading_fee ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

//分页查询数据
std::list<UnloadingFeeDO> UnloadingFeeDAO::selectWithPage(const UnloadingFeeQuery::Wrapper& query)
{
	SqlParams params;
	//使用视图查询
	string sql = "SELECT * FROM vw_unloading_fee ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	// 执行查询
	UnloadingFeeMapper mapper;
	return sqlSession->executeQuery<UnloadingFeeDO>(sql, mapper, params);
}