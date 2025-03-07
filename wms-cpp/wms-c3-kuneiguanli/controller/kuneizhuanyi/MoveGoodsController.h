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
	// [��ҳ��ѯת�������б�]�ӿ�
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

	// ����[�޸�ת������]�ӿ�
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("movegoods.put.modify.summary"), modifyMoveGoods, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/kuneizhuanyi/modify-movegoods", modifyMoveGoods, BODY_DTO(MoveGoodsModifyDTO::Wrapper, dto), execModifyMoveGoods(dto, authObject->getPayload()));

	// ����[����ת������]�ӿ�
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("movegoods.put.batch.summary"), batchModifyMoveGoods, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/kuneiguanli/kuneizhuanyi/batch-modify-movegoods", batchModifyMoveGoods, BODY_DTO(MoveGoodsBatchModifyDTO::Wrapper, dto), execBatchModifyMoveGoods(dto, authObject->getPayload()));

	//  ����[ɾ��ת������֧��������]�ӿ�
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("movegoods.delete.batch.summary"), batchRemoveMoveGoods, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/kuneiguanli/kuneizhuanyi/batch-remove-movegoods", batchRemoveMoveGoods, BODY_DTO(BatchRemoveMoveGoodsDTO::Wrapper, id), execBatchRemoveMoveGoods(id));

	// ����[��ȡת��������ϸ��Ϣ]�ӿ�
	ENDPOINT_INFO(queryDetailedMoveGoods) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("movegoods.getdetailed.summary"), MoveGoodsDetailedJsonVO::Wrapper);
		// �����������
		API_DEF_ADD_QUERY_PARAMS(Int64, "id", ZH_WORDS_GETTER("movegoods.field.id"), 1, false);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/kuneiguanli/kuneizhuanyi/query-detailed-movegoods", queryDetailedMoveGoods, 
		QUERY(Int64, id), execQueryDetailedMoveGoods(id));


	//	����[����ת��-��������]�ӿ�
	ENDPOINT_INFO(downLoadMoveGoodsExcel) {
		// ����ͨ������
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("movegoods.getdownload.summary"), MoveGoodsDetailedJsonVO::Wrapper);
		// �����������
		API_DEF_ADD_QUERY_PARAMS(Int64, "id", ZH_WORDS_GETTER("movegoods.field.id"), 1, false);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/kuneizhuanyi/down-load-movegoods", downLoadMoveGoodsExcel,
		QUERY(Int64, id), execDownLoadMoveGoods(id));

private:
	// ִ�з�ҳ��ѯת�������б�
	MoveGoodsPageJsonVO::Wrapper execQueryMoveGoodsList(const MoveGoodsQuery::Wrapper& query);
	// ִ���޸�ת������
	StringJsonVO::Wrapper execModifyMoveGoods(const MoveGoodsModifyDTO::Wrapper& dto, const PayloadDTO& payload);
    // ִ������ת������
	StringJsonVO::Wrapper execBatchModifyMoveGoods(const MoveGoodsBatchModifyDTO::Wrapper& dto, const PayloadDTO& payload);
	// ִ��ɾ��ת������֧��������
	Uint64JsonVO::Wrapper execBatchRemoveMoveGoods(const BatchRemoveMoveGoodsDTO::Wrapper& id);
	// ִ�л�ȡת��������ϸ��Ϣ
	MoveGoodsDetailedJsonVO::Wrapper execQueryDetailedMoveGoods(const Int64& id);
	// ִ�е���ת������execDownLoadMoveGoods
	MoveGoodsDownLoadJsonVO::Wrapper execDownLoadMoveGoods(const Int64& id);
};