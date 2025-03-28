#pragma once
#ifndef _METHOD_DAO_
#define _METHOD_DAO_
#include "BaseDAO.h"
#include "../../domain/do/cost-way/CostwayDO.h"
#include "../../domain/query/costmethod/BillMethodQuery.h"
/**
 * 示例表数据库操作实现
 */
//class SampleDAO : public BaseDAO
//{
//private:
//	//************************************
//	// Method:      queryConditionBuilder
//	// FullName:    SampleDAO::queryConditionBuilder
//	// Access:      private 
//	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
//	// Parameter:   const SampleQuery::Wrapper& query 查询数据对象
//	// Parameter:   SqlParams& params 存放查询数据的参数对象
//	// Description: 查询条件构建器，根据SampleQuery对象动态构建查询条件相关参数
//	//************************************
//	inline std::string queryConditionBuilder(const SampleQuery::Wrapper& query, SqlParams& params);
//public:
//	// 统计数据条数
//	uint64_t count(const SampleQuery::Wrapper& query);
//	// 分页查询数据
//	std::list<SampleDO> selectWithPage(const SampleQuery::Wrapper& query);
//	// 通过姓名查询数据
//	std::list<SampleDO> selectByName(const string& name);
//	// 通过ID查询数据
//	PtrSampleDO selectById(uint64_t id);
//	// 插入数据
//	uint64_t insert(const SampleDO& iObj);
//	// 修改数据
//	int update(const SampleDO& uObj);
//	// 通过ID删除数据
//	int deleteById(uint64_t id);
//};
class MethodDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const BillmethodQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const BillmethodQuery::Wrapper& query);
	//// 分页查询数据
	std::list<CostwayDO> selectWithPage(const BillmethodQuery::Wrapper& query);
	//// 通过姓名查询数据
	//std::list<SampleDO> selectByName(const string& name);
	//// 通过ID查询数据
	//PtrSampleDO selectById(uint64_t id);
	// 插入数据
	string insert(const MethodDO& iObj);
	//// 修改数据
	int update(const MethodDO& uObj);

	std::list<CostwayDO> qalldao();
	//// 通过ID删除数据
	//int deleteById(uint64_t id);
};
#endif // !_SAMPLE_DAO_
