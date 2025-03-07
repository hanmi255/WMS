#pragma once

#include <list>
#include "domain/vo/kuneizhuanyi/MoveGoodsVO.h"
#include "domain/query/kuneizhuanyi/MoveGoodsQuery.h"
#include "domain/dto/kuneizhuanyi/MoveGoodsDTO.h"

class MoveGoodsService {
public:
	// 分页获取转移任务数据
	MoveGoodsPageDTO::Wrapper listMoveGoodsPage(const MoveGoodsQuery::Wrapper& query);

	// 修改转移任务
	std::string updateMoveGoods(const MoveGoodsModifyDTO::Wrapper& dto, const PayloadDTO& payload);

	// 批量转移任务
	std::string updateMoveGoodsBatch(const MoveGoodsBatchModifyDTO::Wrapper& dto, const PayloadDTO& payload);
};