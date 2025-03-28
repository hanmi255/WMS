#pragma once

#ifndef _LOADINGFEE_DAO_
#define _LOADINGFEE_DAO_

#include "BaseDAO.h"
#include "../../domain/do/LoadingFeeDO.h"
#include"../../domain/dto/loading-fee/LoadingFeeDTO.h"
#include"../../domain/query/loading-fee/LoadingFeeQuery.h"

/**
 * 外包装车费数据库操作实现
 */
class LoadingFeeDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    LoadingFeeDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const LoadingFeeQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据LoadingFeeQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const LoadingFeeQuery::Wrapper& query, SqlParams& params);
public:
	//统计数据条数
	uint64_t count(const LoadingFeeQuery::Wrapper& query);
	//分页查询外包装车费
	std::list<LoadingFeeDO> selectWithPage(const LoadingFeeQuery::Wrapper& query);
};
#endif // !_LOADINGFEE_DAO_