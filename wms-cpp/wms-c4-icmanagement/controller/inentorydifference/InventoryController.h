#pragma once
#ifndef _INVENTORY_CONTROLLER_
#define _INVENTORY_CONTROLLER_
#include "domain/GlobalInclude.h"
#include "domain/vo/inentorydifference/InventoryPVO.h"
#include "domain/query/inentorydifference/InventoryPquery.h"
#include "domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

/*
*盘点人基础资料
*/
class InventoryController : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(InventoryController);
public:
	ENDPOINT_INFO(queryALL) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("mql.ask.inventory"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(InventoryPPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "stt_name", ZH_WORDS_GETTER("mql.stt.stt_name"), "li ming", false);
		API_DEF_ADD_QUERY_PARAMS(String, "bin_id", ZH_WORDS_GETTER("mql.rest.bin_id"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "tin_id", ZH_WORDS_GETTER("mql.rest.tin_id"), "100", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_id", ZH_WORDS_GETTER("mql.goods.goods_id"), "710500", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_name", ZH_WORDS_GETTER("mql.goods.goods_name"), "XXXX", false);
		API_DEF_ADD_QUERY_PARAMS(String, "cus_code", ZH_WORDS_GETTER("mql.cus.cus_code"), "wang pong", false);
		API_DEF_ADD_QUERY_PARAMS(String, "cus_id", ZH_WORDS_GETTER("mql.cus.cus_id"), "0000", false);
	}
	ENDPOINT("GET", "/inv/inventory", queryALL, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(invQuery, InventoryPquery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAll(invQuery));
	}

	ENDPOINT_INFO(addInv) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("mql.add.inventory"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_POST, "/inv/inventory", addInv, BODY_DTO(InventoryPAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddInv(dto));
	}
private:
	InventoryPPageJsonVO::Wrapper execQueryAll(const InventoryPquery::Wrapper& qurey);
	StringJsonVO::Wrapper execAddInv(const InventoryPAddDTO::Wrapper& dto);
    // TODO - more endpoints here

};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section
#endif //!_INVENTORY_CONTROLLER_