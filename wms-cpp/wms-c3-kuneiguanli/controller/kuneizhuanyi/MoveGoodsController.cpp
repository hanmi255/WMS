#include "stdafx.h"	
#include "controller/kuneizhuanyi/MoveGoodsController.h"

MoveGoodsPageJsonVO::Wrapper MoveGoodsController::execQueryMoveGoodsList(const MoveGoodsQuery::Wrapper& moveGoodsQuery, const PayloadDTO& payload)
{
	return MoveGoodsPageJsonVO::Wrapper();
}

Uint64JsonVO::Wrapper MoveGoodsController::execModifyMoveGoods(const MoveGoodsModifyDTO::Wrapper& moveGoodsModifyDTO)
{
	return Uint64JsonVO::Wrapper();
}

Uint64JsonVO::Wrapper MoveGoodsController::execBatchMoveGoods(const MoveGoodsBatchDTO::Wrapper& moveGoodsBatchDTO)
{
	return Uint64JsonVO::Wrapper();
}