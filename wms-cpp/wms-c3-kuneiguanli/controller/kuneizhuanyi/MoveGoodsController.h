#pragma once

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/kuneizhuanyi/MoveGoodsDTO.h"
#include "domain/vo/kuneizhuanyi/MoveGoodsVO.h"
#include "domain/query/kuneizhuanyi/MoveGoodsQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class MoveGoodsController : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(MoveGoodsController);

public:
	// [分页查询转移任务列表]接口
	ENDPOINT_INFO(queryMoveGoodsList) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("move-goods.get.summary"), MoveGoodsPageJsonVO::Wrapper);
		API_DEF_ADD_AUTH();
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "goods-id", ZH_WORDS_GETTER("move-goods.field.goods-id"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods-name", ZH_WORDS_GETTER("move-goods.field.goods-name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "cus-code", ZH_WORDS_GETTER("move-goods.field.cus-code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "cus-name", ZH_WORDS_GETTER("move-goods.field.cus-name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "to-cus-code", ZH_WORDS_GETTER("move-goods.field.to-cus-code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "to-cus-name", ZH_WORDS_GETTER("move-goods.field.to-cus-name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "tin-from", ZH_WORDS_GETTER("move-goods.field.tin-from"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "tin-to", ZH_WORDS_GETTER("move-goods.field.tin-to"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "bin-from", ZH_WORDS_GETTER("move-goods.field.bin-from"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "bin-to", ZH_WORDS_GETTER("move-goods.field.bin-to"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "move-sta", ZH_WORDS_GETTER("move-goods.field.move-sta"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "run-sta", ZH_WORDS_GETTER("move-goods.field.run-sta"), "", false);
	}
	ENDPOINT(API_M_GET, "/kuneizhuanyi/query-move-goods-list", queryMoveGoodsList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(moveGoodsQueryy, MoveGoodsQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryMoveGoodsList(moveGoodsQueryy, authObject->getPayload()));
	}

	// [修改转移任务]接口
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("move-goods.put.modify.summary"), modifyMoveGoods, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/kuneizhuanyi/modify-move-goods", modifyMoveGoods, BODY_DTO(MoveGoodsModifyDTO::Wrapper, dto), execModifyMoveGoods(dto));

	// [批量转移任务]接口
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("move-goods.put.batch.summary"), batchMoveGoods, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/kuneizhuanyi/batch-move-goods", batchMoveGoods, BODY_DTO(MoveGoodsBatchDTO::Wrapper, dto), execBatchMoveGoods(dto));

private:
	// 执行分页查询转移任务列表
	MoveGoodsPageJsonVO::Wrapper execQueryMoveGoodsList(const MoveGoodsQuery::Wrapper& moveGoodsQuery, const PayloadDTO& payload);
	// 执行修改转移任务
	Uint64JsonVO::Wrapper execModifyMoveGoods(const MoveGoodsModifyDTO::Wrapper& moveGoodsModifyDTO);
    // 执行批量转移任务
	Uint64JsonVO::Wrapper execBatchMoveGoods(const MoveGoodsBatchDTO::Wrapper& moveGoodsBatchDTO);
};