#pragma once

#include "BaseDAO.h"
#include "domain/do/kuneizhuanyi/MoveGoodsDO.h"
#include "domain/query/kuneizhuanyi/MoveGoodsQuery.h"

class MoveGoodsDAO : public BaseDAO {
private:
	/**
	 * @brief 查询条件构造器
	 * @param query 查询条件
	 * @param params SQL参数
	 * @return 查询条件SQL语句
	 * @note 该方法用于构造查询条件SQL语句，并将参数填充到SQL参数列表中
	 */
	inline std::string queryConditionBuilder(const MoveGoodsQuery::Wrapper& query, SqlParams& params);

public:
	// 统计数据条数
	uint64_t count(const MoveGoodsQuery::Wrapper& query);

	// 分页查询转移任务
	std::list<MoveGoodsDO> selectWithPage(const MoveGoodsQuery::Wrapper& query);

	// 修改转移任务
	std::string updateMoveGoods(const MoveGoodsDO& moveGoods);

	// 批量转移任务
	std::string updateMoveGoodsBatch(const std::vector<MoveGoodsDO>& moveGoodsList);
};