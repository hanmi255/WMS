#pragma once

#ifndef _UNLOADINGFEE_DAO_
#define _UNLOADINGFEE_DAO_

#include "BaseDAO.h"
#include "../../domain/do/UnloadingFeeDO.h"
#include"../../domain/dto/unloading-fee/UnloadingFeeDTO.h"
#include"../../domain/query/unloading-fee/UnloadingFeeQuery.h"

/**
 * 外包卸货费数据库操作实现
 */
class UnloadingFeeDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    UnloadingFeeDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const UnloadingFeeQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据UnloadingFeeQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const UnloadingFeeQuery::Wrapper& query, SqlParams& params);
public:
	//统计数据条数
	uint64_t count(const UnloadingFeeQuery::Wrapper& query);
	//分页查询外包卸货费
	std::list<UnloadingFeeDO> selectWithPage(const UnloadingFeeQuery::Wrapper& query);
};

#endif // !_UNLOADINGFEE_DAO_