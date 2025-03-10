#pragma once
#ifndef _CHUWEI_DAO_
#define _CHUWEI_DAO_
#include "BaseDAO.h"
#include "../../domain/do/BinDO.h"
#include "../../domain/query/chuweidingyi/ChuWeiQuery.h"

/**
 * 表数据库操作实现
 */
class ChuWeiDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    ChuWeiDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const ChuWeiQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据ChuWeiQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const ChuWeiQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const ChuWeiQuery::Wrapper& query);
	// ***分页查询数据
	std::list<BinDO> selectWithPage(const ChuWeiQuery::Wrapper& query);
	// 修改数据
	int update(const BinDO& uObj);
	// 通过ID删除数据
	int deleteById(string id);
};
#endif // !_CHUWEI_DAO_
