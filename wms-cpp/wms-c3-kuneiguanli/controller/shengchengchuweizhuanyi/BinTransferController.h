#pragma once

#ifndef _BIN_TRANSFER_CONTROLLER_
#define _BIN_TRANSFER_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/shengchengchuweizhuanyi/BinTransferQuery.h"
#include "domain/dto/shengchengchuweizhuanyi/BinTransferDTO.h"
#include "domain/vo/shengchengchuweizhuanyi/BinTransferVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 *
 */
class BinTransferController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(BinTransferController);

public:
	// [可转移列表]接口
	ENDPOINT_INFO(queryBinTransfer) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("assignment.get.bin.summary"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(BinTransferJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();

		//唯一标识
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("assignment.field.id"), "", false);
		// 移动日期
		API_DEF_ADD_QUERY_PARAMS(String, "moveDate", ZH_WORDS_GETTER("assignment.field.move-date"), "", false);
		// 到日期时间
		API_DEF_ADD_QUERY_PARAMS(String, "toMoveDate", ZH_WORDS_GETTER("assignment.field.to-move-date"), "", false);
		// 库存类型
		API_DEF_ADD_QUERY_PARAMS(String, "inventoryType", ZH_WORDS_GETTER("assignment.field.inventory-type"), "", false);
		// 储位
		API_DEF_ADD_QUERY_PARAMS(String, "bin", ZH_WORDS_GETTER("assignment.field.bin"), "", false);
		// 托盘
		API_DEF_ADD_QUERY_PARAMS(String, "tin", ZH_WORDS_GETTER("assignment.field.tin"), "", false);
		// 货主
		API_DEF_ADD_QUERY_PARAMS(String, "cusCode", ZH_WORDS_GETTER("assignment.field.cus-code"), "", false);
		// 货主名称
		API_DEF_ADD_QUERY_PARAMS(String, "cusName", ZH_WORDS_GETTER("assignment.field.cus-name"), "", false);
		// 商品编码
		API_DEF_ADD_QUERY_PARAMS(String, "goodsID", ZH_WORDS_GETTER("assignment.field.goods-id"), "", false);
		//商品名称
		API_DEF_ADD_QUERY_PARAMS(String, "goodsName", ZH_WORDS_GETTER("assignment.field.goods-name"), "", false);
		//生产日期
		API_DEF_ADD_QUERY_PARAMS(String, "produceDate", ZH_WORDS_GETTER("assignment.field.produce-date"), "", false);
		// 到生产日期
		API_DEF_ADD_QUERY_PARAMS(String, "toProduceDate", ZH_WORDS_GETTER("assignment.field.to-produce-date"), "", false);
	}

	ENDPOINT(API_M_GET, "/shengchengchuweizhuanyi/query-bin-transfer", queryBinTransfer, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(pageQuery, BinTransferQuery, queryParams);
		//呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryBinTransfer(pageQuery));
	}

	//[生成转移任务(支持批量)]接口
	ENDPOINT_INFO(modifyBinTransfer) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("assignment.put.bin.modify.summary"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 响应格式描述
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_PUT, "/shengchengchuweizhuanyi/modify-bin-transfer", modifyBinTransfer, BODY_DTO(BinTransferListDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execModifyBinTransfer(dto));
	}


private:
	// 执行可转移列表查询
	BinTransferJsonVO::Wrapper execQueryBinTransfer(const BinTransferQuery::Wrapper& query);
	// 执行生成转移任务(支持批量)
	StringJsonVO::Wrapper execModifyBinTransfer(const BinTransferListDTO::Wrapper& dto);
};


#include OATPP_CODEGEN_END(ApiController) 

#endif // _BIN_TRANSFER_CONTROLLER_