#pragma once
#ifndef _COST_TYPE_CONTROLLER_
#define _COST_TYPE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/billingtype/CostTypeQuery.h"
#include "domain/dto/billingtype/CostDTO.h"
#include "domain/vo/billingtype/CostVO.h"
#include OATPP_CODEGEN_BEGIN(ApiController)
/*
   费用类型控制器--显示类型
*/
class CostTypeController : public oatpp::web::server::api::ApiController
{
	
	API_ACCESS_DECLARE(CostTypeController);
public:
	

	ENDPOINT_INFO(QueryCostTypeListWithCondition) {
		
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("cost.get.list.condition.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(CostPageJsonVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(UInt64, "id", ZH_WORDS_GETTER("cost.field.id"),1, false);
		API_DEF_ADD_QUERY_PARAMS(String, "cost_code", ZH_WORDS_GETTER("cost.field.cost_code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "cost_name", ZH_WORDS_GETTER("cost.field.cost_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "cost_type", ZH_WORDS_GETTER("cost.field.cost_type"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "create_name", ZH_WORDS_GETTER("cost.field.create_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "create_date", ZH_WORDS_GETTER("cost.field.create_date"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "update_name", ZH_WORDS_GETTER("cost.field.update_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "update_date", ZH_WORDS_GETTER("cost.field.update_date"), "", false);
	}
	ENDPOINT(API_M_GET, "/cost-type/all", QueryCostTypeListWithCondition, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(userQuery, CostTypeQuery, queryParams);
		// 调用执行函数响应结果
		API_HANDLER_RESP_VO(execQueryCostTypeListWithCondition(userQuery, authObject->getPayload()));
	}
	

	// 获取费用名称列表
	ENDPOINT_INFO(queryCostTypeById) {
		// 定义通用描述
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("cost.get.list.summary"), CostJsonVO::Wrapper);
		// 定义参数描述
		API_DEF_ADD_QUERY_PARAMS(UInt64, "id", ZH_WORDS_GETTER("cost.field.id"), 1, true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/cost-type/id", queryCostTypeById, QUERY(Int64, id), execQueryCostTypeListAll(id));
	// 录入费用类型
	ENDPOINT_INFO(GetCostType) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("cost.put.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/cost-type/gettype", GetCostType, BODY_DTO(GetCostDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 调用执行函数响应结果
		API_HANDLER_RESP_VO(execGetCostType(dto, authObject->getPayload()));
	}

	// 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("cost.modify.summary"), ModifyCostType, Uint64JsonVO::Wrapper);
	// 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/cost-type/modify", ModifyCostType, BODY_DTO(ModifyCostDTO::Wrapper, dto), execModifyCostType(dto));
private:
	// 获取费用类型列表
	CostJsonVO::Wrapper execQueryCostTypeListAll(const Int64& id);

	// 获取费用类型列表(分页)
	CostPageJsonVO::Wrapper execQueryCostTypeListWithCondition(const  CostTypeQuery::Wrapper& query, const PayloadDTO& payload);

	// 录入费用类型
	Uint64JsonVO::Wrapper execGetCostType(const GetCostDTO::Wrapper& dto, const PayloadDTO& payload);

	// 修改费用类型
	Uint64JsonVO::Wrapper execModifyCostType(const ModifyCostDTO::Wrapper& dto);
};
#include OATPP_CODEGEN_END(ApiController) 
#endif // ! _COST_TYPE_CONTROLLER_