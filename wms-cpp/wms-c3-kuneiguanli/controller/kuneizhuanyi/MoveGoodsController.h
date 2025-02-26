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
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("move-goods.field.id"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods-id", ZH_WORDS_GETTER("move-goods.field.goods-id"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods-name", ZH_WORDS_GETTER("move-goods.field.goods-name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "cus-code", ZH_WORDS_GETTER("move-goods.field.cus-code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "cus-name", ZH_WORDS_GETTER("move-goods.field.cus-name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "to-cus-code", ZH_WORDS_GETTER("move-goods.field.to-cus-code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "to-cus-name", ZH_WORDS_GETTER("move-goods.field.to-cus-name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "tin-from", ZH_WORDS_GETTER("move-goods.field.tin-from"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "tin-id", ZH_WORDS_GETTER("move-goods.field.tin-id"), "", false);
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
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/kuneiguanli/kuneizhuanyi/batch-move-goods", batchMoveGoods, BODY_DTO(MoveGoodsBatchDTO::Wrapper, dto), execBatchMoveGoods(dto));

	//  定义[删除转移任务（支持批量）]接口
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("move-goods.delete.batch.summary"), batchRemoveMoveGoods, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/kuneiguanli/kuneizhuanyi/batch-remove-move-goods", batchRemoveMoveGoods, BODY_DTO(BatchRemoveMoveGoodsDTO::Wrapper, id), execBatchRemoveMoveGoods(id));

	// 定义[获取转移任务详细信息]接口
	ENDPOINT_INFO(queryDetailedMoveGoods) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("move-goods.getdetailed.summary"), MoveGoodsDetailedJsonVO::Wrapper);
		// 定义参数描述
		API_DEF_ADD_QUERY_PARAMS(Int64, "id", ZH_WORDS_GETTER("move-goods.field.id"), 1, false);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/kuneiguanli/kuneizhuanyi/query-detailed-move-goods", queryDetailedMoveGoods, 
		QUERY(Int64, id), execQueryDetailedMoveGoods(id));


	//	定义[库内转移-导出数据]接口
	ENDPOINT_INFO(downLoadMoveGoodsExcel) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("move-goods.getdownload.summary"), MoveGoodsDetailedJsonVO::Wrapper);
		// 定义参数描述
		API_DEF_ADD_QUERY_PARAMS(Int64, "id", ZH_WORDS_GETTER("move-goods.field.id"), 1, false);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/kuneizhuanyi/down-load-move-goods", downLoadMoveGoodsExcel,
		QUERY(Int64, id), execDownLoadMoveGoods(id));

private:
	// 执行分页查询转移任务列表
	MoveGoodsPageJsonVO::Wrapper execQueryMoveGoodsList(const MoveGoodsQuery::Wrapper& moveGoodsQuery, const PayloadDTO& payload);
	// 执行修改转移任务
	Uint64JsonVO::Wrapper execModifyMoveGoods(const MoveGoodsModifyDTO::Wrapper& moveGoodsModifyDTO);
    // 执行批量转移任务
	Uint64JsonVO::Wrapper execBatchMoveGoods(const MoveGoodsBatchDTO::Wrapper& moveGoodsBatchDTO);
	// 执行删除转移任务（支持批量）
	Uint64JsonVO::Wrapper execBatchRemoveMoveGoods(const BatchRemoveMoveGoodsDTO::Wrapper& id);
	// 执行获取转移任务详细信息
	MoveGoodsDetailedJsonVO::Wrapper execQueryDetailedMoveGoods(const Int64& id);
	// 执行导出转移任务execDownLoadMoveGoods
	MoveGoodsDownLoadJsonVO::Wrapper execDownLoadMoveGoods(const Int64& id);
};