#pragma once
#ifndef _COSTSUM_DAO_
#define _COSTSUM_DAO_
#include "BaseDAO.h"
#include "../../domain/do/CostSumDO.h"
#include "../../domain/dto/cost-sum-dto/CostSumDTO.h"
#include "../../domain/query/cost-sum-query/CostSumQuery.h"

/**
 * 示例表数据库操作实现
 */
class CostSumDAO : public BaseDAO
{
private:
	inline std::string QueryConditionBuilder(const CostSumQuery::Wrapper& query, SqlParams& params);
public:
	// 分页查询数据
	std::list<CostSumDO> selectWithPage(const CostSumQuery::Wrapper& query);
	uint64_t count(const CostSumQuery::Wrapper& query);

};
#endif // !_SAMPLE_DAO_