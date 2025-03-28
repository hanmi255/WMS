#pragma once

#ifndef _COST_CONTROLLER_
#define _COST_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/cost-detail-ahead/CostDetialDTO.h"
#include "domain/vo/cost-detail-ahead/CostDetialVO.h"
#include "domain/query/cost-detail-ahead/CostDetailQuery.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 费用明细管理 控制器，演示基础接口的使用
 */
class CostDetialController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(CostDetialController);
	// 3 定义接口
public:
	// 3.1 定义分页查询接口描述
	ENDPOINT_INFO(querypageAll) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("cost.get.pagequery"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CostDetailListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();

		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "cusCode", ZH_WORDS_GETTER("cost.field.cus_code"), "X00001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "cusName", ZH_WORDS_GETTER("cost.field.cus_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "costCode", ZH_WORDS_GETTER("cost.field.cost_code"), "2001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "costName", ZH_WORDS_GETTER("cost.field.cost_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "costDateBegin", ZH_WORDS_GETTER("cost.field.cost_date"), "2025-02-19 00:00:00", false);
		API_DEF_ADD_QUERY_PARAMS(String, "costDateEnd", ZH_WORDS_GETTER("cost.field.cost_date"), "2025-02-25 00:00:00", false);
		API_DEF_ADD_QUERY_PARAMS(String, "costOrigin", ZH_WORDS_GETTER("cost.field.cost_ori"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "note", ZH_WORDS_GETTER("cost.field.beizhu"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "costState", ZH_WORDS_GETTER("cost.field.cost_sta"), "", false);

	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/cost-management/cost-detail/query-cost", querypageAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(costDetailQuery, CostDetailQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryPageAll(costDetailQuery));
	}
	/*
	// 3.1 定义条件查询接口描述
	ENDPOINT_INFO(queryAll) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("cost.get.query"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CostDetailJsonVO);
		
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "cusCode", ZH_WORDS_GETTER("cost.field.cus_code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "cusName", ZH_WORDS_GETTER("cost.field.cus_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "costCode", ZH_WORDS_GETTER("cost.field.cost_code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "costName", ZH_WORDS_GETTER("cost.field.cost_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "costDateBegin", ZH_WORDS_GETTER("cost.field.cost_date"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "costDateEnd", ZH_WORDS_GETTER("cost.field.cost_date"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "costOrigin", ZH_WORDS_GETTER("cost.field.cost_ori"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "note", ZH_WORDS_GETTER("cost.field.beizhu"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "costState", ZH_WORDS_GETTER("cost.field.cost_sta"), "", false);

	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/cost-detail/query-cost", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(costQuery, CostDetailQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAll(costQuery, authObject->getPayload()));
	}*/



	// 3.1 定义录入费用明细接口描述
	ENDPOINT_INFO(addCost) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("cost.post.add"));
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
	}
	// 3.2 定义录入费用明细接口处理
	ENDPOINT(API_M_POST, "/cost-management/cost-detail/add-cost", addCost, BODY_DTO(CostDetailAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddCost(dto, authObject->getPayload()));
	}

	// 3.1 定义编辑费用明细接口描述
	ENDPOINT_INFO(editCost) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("cost.put.edit"));
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
	}
	// 3.2 定义费用明细接口处理
	ENDPOINT(API_M_PUT, "/cost-management/cost-detail/edit-cost", editCost, BODY_DTO(CostDetailEditDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		 //呼叫执行函数响应结果/cost-detail
		API_HANDLER_RESP_VO(execeditCost(dto, authObject->getPayload()));
	}


	// 3.1 定义删除接口描述
	ENDPOINT_INFO(removeCostById) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("cost.delete.summary"), StringJsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("cost.field.id"), "", true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/cost-management/cost-detail/by-id/{id}", removeCostById, PATH(String, id), execRemoveCost(id));



	// 3.1 定义批量删除接口描述
	ENDPOINT_INFO(removeCostAll) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("cost.delete.all"), StringJsonVO::Wrapper);

		// 定义其他路径参数说明
		//API_DEF_ADD_PATH_PARAMS(List<String>, "ids", ZH_WORDS_GETTER("cost.field.ids"), {}, true);
	}
	// 3.2 定义批量删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/cost-management/cost-detail/remove-batch", removeCostAll, BODY_DTO(List<String>, ids), execRemoveAllCost(ids));


private:
	// 3.3 演示分页查询数据
	CostDetailListPageJsonVO::Wrapper execQueryPageAll(const CostDetailQuery::Wrapper& query);
	// 3.3 演示新增数据
	Uint64JsonVO::Wrapper execAddCost(const CostDetailAddDTO::Wrapper& dto, const PayloadDTO& payload);
	// 3.3 演示修改数据
	StringJsonVO::Wrapper execeditCost(const CostDetailEditDTO::Wrapper& dto, const PayloadDTO& payload);
	
	// 3.3 演示单个删除数据
	StringJsonVO::Wrapper execRemoveCost(const String& id);
	// 3.3 演示批量删除数据
	StringJsonVO::Wrapper execRemoveAllCost(const List<String>& ids);


};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _COST_CONTROLLER_

