#pragma once

#ifndef _TIN_TRANSFER_CONTROLLER_
#define _TIN_TRANSFER_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/shengchengtuopanzhuanyi/TinTransferQuery.h"
#include "domain/dto/shengchengtuopanzhuanyi/TinTransferDTO.h"
#include "domain/vo/shengchengtuopanzhuanyi/TinTransferVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 
 */
class TinTransferController	: public oatpp::web::server::api::ApiController 
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(TinTransferController);
	
public:
	// [可转移列表]接口
	ENDPOINT_INFO(queryTinTransferList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("assignment.get.tin.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(TinTransferJsonVO);
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

	ENDPOINT(API_M_GET, "/shengchengtuopanzhuanyi/query-tin-transfer-list", queryTinTransferList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(pageQuery, TinTransferQuery, queryParams);
		//呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryTinTransferList(pageQuery));
	}

	//[生成转移任务(支持批量)]接口
	ENDPOINT_INFO(modifyTinTransfer) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("assignment.put.tin.modify.summary"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 响应格式描述
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_PUT, "/shengchengtuopanzhuanyi/modify-tin-transfer", modifyTinTransfer, BODY_DTO(TinTransferBaseDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execModifyTinTransfer(dto));
	}

		
private:
	// 执行可转移列表查询
	TinTransferJsonVO::Wrapper execQueryTinTransferList(const TinTransferQuery::Wrapper& query);
	// 执行生成转移任务(支持批量)
	StringJsonVO::Wrapper execModifyTinTransfer(const TinTransferBaseDTO::Wrapper& dto);
};


#include OATPP_CODEGEN_END(ApiController) 

#endif // _TIN_TRANSFER_CONTROLLER_