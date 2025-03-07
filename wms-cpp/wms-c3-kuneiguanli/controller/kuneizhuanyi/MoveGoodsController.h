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
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("movegoods.get.summary"), MoveGoodsPageJsonVO::Wrapper);
		API_DEF_ADD_AUTH();
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("movegoods.field.id"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_id", ZH_WORDS_GETTER("movegoods.field.goods_id"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_name", ZH_WORDS_GETTER("movegoods.field.goods_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "cus_code", ZH_WORDS_GETTER("movegoods.field.cus_code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "cus_name", ZH_WORDS_GETTER("movegoods.field.cus_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "to_cus_code", ZH_WORDS_GETTER("movegoods.field.to_cus_code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "to_cus_name", ZH_WORDS_GETTER("movegoods.field.to_cus_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "tin_from", ZH_WORDS_GETTER("movegoods.field.tin_from"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "tin_id", ZH_WORDS_GETTER("movegoods.field.tin_id"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "bin_from", ZH_WORDS_GETTER("movegoods.field.bin_from"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "bin_to", ZH_WORDS_GETTER("movegoods.field.bin_to"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "move_sta", ZH_WORDS_GETTER("movegoods.field.move_sta"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "run_sta", ZH_WORDS_GETTER("movegoods.field.run_sta"), "", false);
	}
	ENDPOINT(API_M_GET, "/kuneizhuanyi/query-movegoods-list", queryMoveGoodsList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(moveGoodsQuery, MoveGoodsQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryMoveGoodsList(moveGoodsQuery));
	}

	// 定义[修改转移任务]接口
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("movegoods.put.modify.summary"), modifyMoveGoods, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/kuneizhuanyi/modify-movegoods", modifyMoveGoods, BODY_DTO(MoveGoodsModifyDTO::Wrapper, dto), execModifyMoveGoods(dto, authObject->getPayload()));

	// 定义[批量转移任务]接口
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("movegoods.put.batch.summary"), batchModifyMoveGoods, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/kuneiguanli/kuneizhuanyi/batch-modify-movegoods", batchModifyMoveGoods, BODY_DTO(MoveGoodsBatchModifyDTO::Wrapper, dto), execBatchModifyMoveGoods(dto, authObject->getPayload()));

	//  定义[删除转移任务（支持批量）]接口
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("movegoods.delete.batch.summary"), batchRemoveMoveGoods, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/kuneiguanli/kuneizhuanyi/batch-remove-movegoods", batchRemoveMoveGoods, BODY_DTO(BatchRemoveMoveGoodsDTO::Wrapper, id), execBatchRemoveMoveGoods(id));

	// 定义[获取转移任务详细信息]接口
	ENDPOINT_INFO(queryDetailedMoveGoods) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("movegoods.getdetailed.summary"), MoveGoodsDetailedJsonVO::Wrapper);
		// 定义参数描述
		API_DEF_ADD_QUERY_PARAMS(Int64, "id", ZH_WORDS_GETTER("movegoods.field.id"), 1, false);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/kuneiguanli/kuneizhuanyi/query-detailed-movegoods", queryDetailedMoveGoods, 
		QUERY(Int64, id), execQueryDetailedMoveGoods(id));


	//	定义[库内转移-导出数据]接口
	ENDPOINT_INFO(downLoadMoveGoodsExcel) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("movegoods.getdownload.summary"), MoveGoodsDetailedJsonVO::Wrapper);
		// 定义参数描述
		API_DEF_ADD_QUERY_PARAMS(Int64, "id", ZH_WORDS_GETTER("movegoods.field.id"), 1, false);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/kuneizhuanyi/down-load-movegoods", downLoadMoveGoodsExcel,
		QUERY(Int64, id), execDownLoadMoveGoods(id));

private:
	// 执行分页查询转移任务列表
	MoveGoodsPageJsonVO::Wrapper execQueryMoveGoodsList(const MoveGoodsQuery::Wrapper& query);
	// 执行修改转移任务
	StringJsonVO::Wrapper execModifyMoveGoods(const MoveGoodsModifyDTO::Wrapper& dto, const PayloadDTO& payload);
    // 执行批量转移任务
	StringJsonVO::Wrapper execBatchModifyMoveGoods(const MoveGoodsBatchModifyDTO::Wrapper& dto, const PayloadDTO& payload);
	// 执行删除转移任务（支持批量）
	Uint64JsonVO::Wrapper execBatchRemoveMoveGoods(const BatchRemoveMoveGoodsDTO::Wrapper& id);
	// 执行获取转移任务详细信息
	MoveGoodsDetailedJsonVO::Wrapper execQueryDetailedMoveGoods(const Int64& id);
	// 执行导出转移任务execDownLoadMoveGoods
	MoveGoodsDownLoadJsonVO::Wrapper execDownLoadMoveGoods(const Int64& id);
};