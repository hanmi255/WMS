#pragma once
#ifndef _ACTTYPEDAO_H_
#define _ACTTYPEDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/act_type/ActTypeDO.h"
#include "../../domain/query/act_type/ActTypeQuery.h"

/**
 * 获取作业类型列表、录入作业类型 数据库操作实现
 */
class ActTypeDAO : public BaseDAO
{
private:
	inline std::string queryConditionBuilder(const ActTypeQuery::Wrapper& query, SqlParams& params);
public:
	// 分页查询数据
	std::list<ActTypeDO> selectWithPage(const ActTypeQuery::Wrapper& query);
	// 插入数据
	uint64_t insert(const ActTypeDO& iObj);
	// 统计数据条数
	uint64_t count(const ActTypeQuery::Wrapper& query);
};


#endif // !_ACTTYPEDAO_H_