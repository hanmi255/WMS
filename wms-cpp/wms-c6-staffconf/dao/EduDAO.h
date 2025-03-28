#pragma once
#ifndef _EDU_DAO_
#define _EDU_DAO_
#include "BaseDAO.h"
#include "../domain/do/education/EducationDO.h"
#include "../domain/query/education/EduQuery.h"

/**
 * 示例表数据库操作实现
 */
class EduDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const SampleQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据EduQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const EduQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const EduQuery::Wrapper& query);
	// 分页查询数据
	std::list<EducationDO> selectWithPage(const EduQuery::Wrapper& query);
	std::list<EduBaseDO> select();
	// 插入数据
	bool insert(const EducationDO& iObj);
	void insert(const list<EducationDO>& obj);
};
#endif // !_SAMPLE_DAO_