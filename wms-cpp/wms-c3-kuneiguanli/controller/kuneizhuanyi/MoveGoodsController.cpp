#include "stdafx.h"	
#include "controller/kuneizhuanyi/MoveGoodsController.h"
#include "service/kuneizhuanyi/MoveGoodsService.h"

MoveGoodsPageJsonVO::Wrapper MoveGoodsController::execQueryMoveGoodsList(const MoveGoodsQuery::Wrapper& query)
{
	MoveGoodsService service;

	auto result = service.listMoveGoodsPage(query);
	auto jvo = MoveGoodsPageJsonVO::createShared();

	jvo->success(result);
	return jvo;
}

StringJsonVO::Wrapper MoveGoodsController::execModifyMoveGoods(const MoveGoodsModifyDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	MoveGoodsService service;
	auto result = service.updateMoveGoods(dto, payload);

	if (result == "failed")
		jvo->fail(String{ "failed to modify move goods" });
	else
		jvo->success(String{ result });

	return jvo;
}

StringJsonVO::Wrapper MoveGoodsController::execBatchModifyMoveGoods(const MoveGoodsBatchModifyDTO::Wrapper& dto, const PayloadDTO& payload)
{
	auto jvo = StringJsonVO::createShared();
	MoveGoodsService service;
	auto result = service.updateMoveGoodsBatch(dto, payload);

	if (result == "All Updated")
		jvo->success(String{ "all modified successfully" });
	else if (result == "Part Updated")
		jvo->fail(String{ "part modified successfully" });
	else
		jvo->fail(String{ "failed to modify move goods" });

	return jvo;
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