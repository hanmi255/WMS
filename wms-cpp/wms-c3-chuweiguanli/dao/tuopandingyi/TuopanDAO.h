#pragma once
#ifndef _TUOPAN_DAO_
#define _TUOPAN_DAO_
#include "BaseDAO.h"
#include "../../domain/do/TuopanDO.h"
#include "../../domain/query/tuopandingyi/TuopanQuery.h"

/**
 * 示例表数据库操作实现
 */
class TuopanDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    TuopanDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const TuopanQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据TuopanQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const TuopanQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const TuopanQuery::Wrapper& query);
	// 分页查询数据
	std::list<TuopanDO> selectWithPage(const TuopanQuery::Wrapper& query);
	//// 通过姓名查询数据
	//std::list<SampleDO> selectByName(const string& name);
	//// 通过ID查询数据
	//PtrSampleDO selectById(uint64_t id);
	//// 插入数据
	//uint64_t insert(const SampleDO& iObj);
	// 修改数据
	int update(const TuopanDO& uObj);
	// 批量删除数据
	int deleteById(string id);
};
#endif // !_TUOPAN_DAO_