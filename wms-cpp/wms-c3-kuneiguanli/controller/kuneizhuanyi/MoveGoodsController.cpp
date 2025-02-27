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

Uint64JsonVO::Wrapper MoveGoodsController::execBatchRemoveMoveGoods(const BatchRemoveMoveGoodsDTO::Wrapper& id)
{
	return Uint64JsonVO::Wrapper();
}

MoveGoodsDetailedJsonVO::Wrapper MoveGoodsController::execQueryDetailedMoveGoods(const Int64& id)
{
	return MoveGoodsDetailedJsonVO::Wrapper();
}

MoveGoodsDownLoadJsonVO::Wrapper MoveGoodsController::execDownLoadMoveGoods(const Int64& id)
{
	return MoveGoodsDownLoadJsonVO::Wrapper();
}