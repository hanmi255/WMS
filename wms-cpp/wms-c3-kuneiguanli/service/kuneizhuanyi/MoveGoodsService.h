#pragma once

#include <list>
#include "domain/vo/kuneizhuanyi/MoveGoodsVO.h"
#include "domain/query/kuneizhuanyi/MoveGoodsQuery.h"
#include "domain/dto/kuneizhuanyi/MoveGoodsDTO.h"

class MoveGoodsService {
public:
	// ��ҳ��ȡת����������
	MoveGoodsPageDTO::Wrapper listMoveGoodsPage(const MoveGoodsQuery::Wrapper& query);

	// �޸�ת������
	std::string updateMoveGoods(const MoveGoodsModifyDTO::Wrapper& dto, const PayloadDTO& payload);

	// ����ת������
	std::string updateMoveGoodsBatch(const MoveGoodsBatchModifyDTO::Wrapper& dto, const PayloadDTO& payload);
};