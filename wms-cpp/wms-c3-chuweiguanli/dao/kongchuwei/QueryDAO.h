#pragma once
#ifndef _QUERY_DAO_
#define _QUERY_DAO_
#include "BaseDAO.h"
#include "../../domain/do/BinDO.h"
#include "../../domain/query/kongchuwei/DaoChuKongChuWeiQuery.h"

/**
 * 示例表数据库操作实现
 */
class QueryDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const SampleQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据SampleQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const DaoChuKongChuWeiQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const DaoChuKongChuWeiQuery::Wrapper& query);
	// 分页查询数据
	std::list<BinDO> selectWithPage(const DaoChuKongChuWeiQuery::Wrapper& query);
	
};
#endif // !_QUERY_DAO_