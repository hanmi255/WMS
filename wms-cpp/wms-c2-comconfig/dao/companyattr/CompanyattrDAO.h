#pragma once
/*
  @Author: laughter
*/
#ifndef _COMPANYATTR_DAO_
#define _COMPANYATTR_DAO_
#include "BaseDAO.h"
#include "../../domain/do/companyattr/CompanyattrDO.h"
#include "../../domain/query/companyattr/CompanyattrQuery.h"

/**
 * 示例表数据库操作实现
 */
class CompanyattrDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const CompanyattrQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const CompanyattrQuery::Wrapper& query);
	// 分页查询数据
	std::list<CompanyattrDO> selectWithPage(const CompanyattrQuery::Wrapper& query);
	// 插入数据
	uint64_t insert(const CompanyattrIdDO& iObj);
	//修改数据
	int update(const CompanyattrIdDO& uObj);
	//// 通过ID删除数据
	//int deleteById(uint64_t id);
};
#endif // !_SAMPLE_DAO_

