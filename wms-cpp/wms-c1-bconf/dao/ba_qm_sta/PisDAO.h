#pragma once

#ifndef _PIS_DAO_
#define _PIS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/ba_qm_sta/PisDO.h"
#include "../../domain/query/ba_qm_sta/PisQuery.h"

/**
 * 示例表数据库操作实现
 */
class PisDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const PisQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const PisQuery::Wrapper& query);
	// 分页查询数据
	std::list<PisDO> selectWithPage(const PisQuery::Wrapper& query);
	// 通过品检状态代码查询数据
	//PtrPisDO selectByCode(const string& code);
	// 通过品检状态名称查询数据
	//PtrPisDO selectByName(const string& name);
	// 插入品检状态数据
	std::string insert(const PisDO& iObj);
	// 通过品检状态代码修改名称
	int update(const PisDO& uObj);
};
#endif // !_SAMPLE_DAO_
