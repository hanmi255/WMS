#pragma once
#ifndef _ORDER_TYPE_CONTROLLER_H_
#define _ORDER_TYPE_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "domain/dto/order_type/OrderTypeDTO.h"
#include "domain/query/order_type/OrderTypeQuery.h"
#include "domain/vo/order_type/OrderTypeVo.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class OrderTypeController : public oatpp::web::server::api::ApiController
{
public:
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(OrderTypeController);
	// 3 定义接口

	//  定义查询接口描述
	//  定义获取订单类型名称接口描述
	
	ENDPOINT_INFO(orderQueryName) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("order_type.get.order_type_name_list"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(OrderTypeNameVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
	}
	// 定义查询订单类型接口处理
	ENDPOINT(API_M_GET, "/repository/order-type/query-name", orderQueryName, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(orderTypeQuery, PageQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryNameOrderType(orderTypeQuery));
	}
	

	//  定义查询订单类型列表接口描述
	ENDPOINT_INFO(queryOrderType) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("order_type.get.order_type_list"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(OrderTypePageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "order_type_code", ZH_WORDS_GETTER("order_type.field.order_type_code"), "01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "order_type_name", ZH_WORDS_GETTER("order_type.field.order_type_name"), "ru ku", false);
	}
	// 定义查询订单类型接口处理
	ENDPOINT(API_M_GET, "/repository/order-type/query-all", queryOrderType, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(orderTypeQuery, OrderTypeQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryOrderType(orderTypeQuery));
	}

	//定义查询订单类型接口处理
	ENDPOINT_INFO(addOrderType) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("order_type.post.order_type_add"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 定义新增接口处理,录入作业类型
	ENDPOINT(API_M_POST, "/repository/order-type/add-data", addOrderType, BODY_DTO(OrderTypeAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(addOrderType(dto, authObject->getPayload()));
	}
private:
	// 4 定义执行函数
	OrderTypeNameVO::Wrapper execQueryNameOrderType(const PageQuery::Wrapper& query);
	OrderTypePageJsonVO::Wrapper execQueryOrderType(const OrderTypeQuery::Wrapper& query);
	Uint64JsonVO::Wrapper addOrderType(const OrderTypeAddDTO::Wrapper& dto, const PayloadDTO& payload);

};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_ORDER_TYPE_CONTROLLER_H_