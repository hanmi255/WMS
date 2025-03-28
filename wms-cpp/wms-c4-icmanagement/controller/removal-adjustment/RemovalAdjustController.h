#pragma once
#ifndef _REMOVAL_CONTROLLER_
#define _REMOVAL_CONTROLLER_

#include "../../../lib-oatpp/include/domain/vo/BaseJsonVO.h"
#include "../../domain/vo/removal-adjustment/RemovalVO.h"
#include "../../domain/query/removal-adjustment/RemovalQuery.h"
#include "../../domain/dto/removal-adjustment/RemovalDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class RemovalController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(RemovalController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryremoval) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("removal-adjustment.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(RemovalListJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "order_id", ZH_WORDS_GETTER("removal-adjustment.get.order_id"), "123456", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_id", ZH_WORDS_GETTER("removal-adjustment.get.goods_id"), "123456", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_name", ZH_WORDS_GETTER("removal-adjustment.get.goods_name"), "123456", false);
	}
	ENDPOINT(API_M_GET, "/removal-adjustment/query", queryremoval, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, RemovalQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryRemoval(userQuery, authObject->getPayload()));
	}
	ENDPOINT_INFO(querydetailremoval)
	{
		// 定义通用描述
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("removal-adjustment.get.detail"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_RSP_JSON_WRAPPER(RemovalDetailJsonVO);
		// 定义参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "order_id", ZH_WORDS_GETTER("removal-adjustment.query.order_id"), "CK20240925-0002", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_id", ZH_WORDS_GETTER("removal-adjustment.query.goods_id"), "20222", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods_name", ZH_WORDS_GETTER("removal-adjustment.query.goods_name"), "牛羊肉半成品", false);
	}
	ENDPOINT(API_M_GET, "/removal-adjustment/detail-query", querydetailremoval, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userdetailQuery, RemovalQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryRemovaldetail(userdetailQuery, authObject->getPayload()));
	}
	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("removal-adjustment.get.modify_goods"), modifyRemoval, RemovalListJsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/removal-adjustment/modify", modifyRemoval, BODY_DTO(RemovalListDTO::Wrapper, dto), execModifyRemoval(dto));
private:
	RemovalPageJsonVO::Wrapper execQueryRemoval(const RemovalQuery::Wrapper& query, const PayloadDTO& payload);
	RemovalDetailPageJsonVO::Wrapper execQueryRemovaldetail(const RemovalQuery::Wrapper& query, const PayloadDTO& payload);
	
	StringJsonVO::Wrapper execModifyRemoval(const RemovalListDTO::Wrapper & dto);
};
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // 