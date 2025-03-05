#pragma once

#include "BaseDAO.h"
#include "domain/do/kuneizhuanyi/MoveGoodsDO.h"
#include "domain/query/kuneizhuanyi/MoveGoodsQuery.h"

class MoveGoodsDAO : public BaseDAO {
private:
	/**
	 * @brief ��ѯ����������
	 * @param query ��ѯ����
	 * @param params SQL����
	 * @return ��ѯ����SQL���
	 * @note �÷������ڹ����ѯ����SQL��䣬����������䵽SQL�����б���
	 */
	inline std::string queryConditionBuilder(const MoveGoodsQuery::Wrapper& query, SqlParams& params);

public:
	// ͳ����������
	uint64_t count(const MoveGoodsQuery::Wrapper& query);

	// ��ҳ��ѯת������
	std::list<MoveGoodsDO> selectWithPage(const MoveGoodsQuery::Wrapper& query);

	// �޸�ת������
	std::string updateMoveGoods(const MoveGoodsDO& moveGoods);

	// ����ת������
	std::string updateMoveGoodsBatch(const std::vector<MoveGoodsDO>& moveGoodsList);
};