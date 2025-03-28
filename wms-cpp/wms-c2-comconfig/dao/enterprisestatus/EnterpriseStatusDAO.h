#pragma once

#ifndef _ENTERPRISESTATUSDAO_
#define _ENTERPRISESTATUSDAO_
#include "BaseDAO.h"
#include "../../domain/do/enterprisestatus/EnterpriseStatusDO.h"
#include "../../domain/query/md-cus-other/EnterpriseQuery.h"

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
	inline std::string queryConditionBuilder(const EnterpriseQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const EnterpriseQuery::Wrapper& query);
	uint64_t count1();
	// 分页查询数据
	std::list<EnterpriseStatusDO> selectWithPage(const EnterpriseQuery::Wrapper& query);
	
	std::list<EnterpriseStatusListDO> selectForList();

};
#endif // !_ENTERPRISESTATUSDAO_
