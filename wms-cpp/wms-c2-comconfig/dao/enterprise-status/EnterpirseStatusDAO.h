#pragma once
#ifndef _ENTERPRISESTATUS_DAO_
#define _ENTERPRISESTATUS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/enterprise-status/ba_cus_staDO.h"
#include "../../domain/query/enterprise-status/GetEnterpriseStatusQuery.h"
#include "BaseDAO.h"


/**
 * 示例表数据库操作实现
 */
class EnterpriseStatusDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const GetEnterpriseStatusQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const GetEnterpriseStatusQuery::Wrapper& query);
	// 查询数据
	std::list<CustomerStatusDO> selectWithPage(const GetEnterpriseStatusQuery::Wrapper& query);
	// 插入数据
	uint64_t insert(const CustomerStatusDO& iObj);

};
#endif // !_ENTERPRISESTATUS_DAO_

