#pragma once

#ifndef _COST_NAME_CONTROLLER_
#define _COST_NAME_CONTROLLER_

#include "domain/vo/billing-configuration/CostNameVO.h"
#include "domain/query/billing-configuration/CostNameQuery.h"
#include "domain/dto/billing-configuration/CostNameDTO.h"
#include "domain/vo/BaseJsonVO.h"
#include"domain/do/billing-configuration/CostNameDO.h"
#include"dao/billing-configuration/CostNameDAO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 费用名称控制器，演示费用名称相关接口的使用
 */
class CostNameController : public oatpp::web::server::api::ApiController
{
    API_ACCESS_DECLARE(CostNameController);

public:
    
    // 获取费用名称列表（全部）
    ENDPOINT_INFO(queryCostNameListAll) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("cost.get.list.summary"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(CostNameJsonVO);
        //API_DEF_ADD_PAGE_PARAMS();
        API_DEF_ADD_QUERY_PARAMS(String, "cost_type_code", ZH_WORDS_GETTER("cost.field.type_code"), "", false);
    }
    ENDPOINT(API_M_GET, "/billing-configuration/query-all",   queryCostNameListAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        // 解析查询参数为 Query 领域模型
        API_HANDLER_QUERY_PARAM(costListQuery, CostNameQuery, queryParams);
        // 调用执行函数响应结果
        API_HANDLER_RESP_VO(execQueryCostNameListAll(costListQuery));
    }

    // 获取费用名称列表（条件+分页）
    ENDPOINT_INFO(queryCostNameListWithCondition) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("cost.get.list.condition.summary"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(CostNamePageJsonVO);
        // 定义分页查询参数描述
        API_DEF_ADD_PAGE_PARAMS();
        // 定义其他查询参数描述
        API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("cost.field.code"), "", false);
        API_DEF_ADD_QUERY_PARAMS(String, "cost_code", ZH_WORDS_GETTER("cost.field.code"), "", false);
        API_DEF_ADD_QUERY_PARAMS(String, "cost_name", ZH_WORDS_GETTER("cost.field.name"), "", false);
        API_DEF_ADD_QUERY_PARAMS(String, "cost_type_code", ZH_WORDS_GETTER("cost.field.type_code"), "", false);
        //API_DEF_ADD_QUERY_PARAMS(String, "create_name", ZH_WORDS_GETTER("cost.field.create_name"), "", false);
        //API_DEF_ADD_QUERY_PARAMS(String, "create_by", ZH_WORDS_GETTER("cost.field.create_by"), "", false);
        //API_DEF_ADD_QUERY_PARAMS(String, "create_date", ZH_WORDS_GETTER("cost.field.create_date"), "", false);
       // API_DEF_ADD_QUERY_PARAMS(String, "update_name", ZH_WORDS_GETTER("cost.field.update_name"), "", false);
        //API_DEF_ADD_QUERY_PARAMS(String, "update_by", ZH_WORDS_GETTER("cost.field.update_by"), "", false);
        //API_DEF_ADD_QUERY_PARAMS(String, "update_date", ZH_WORDS_GETTER("cost.field.update_date"), "", false);
        //API_DEF_ADD_QUERY_PARAMS(String, "sys_org_code", ZH_WORDS_GETTER("cost.field.sys_org_code"), "", false);
        //API_DEF_ADD_QUERY_PARAMS(String, "sys_company_code", ZH_WORDS_GETTER("cost.field.sys_company_code"), "", false);
    }
    ENDPOINT(API_M_GET, "/billing-configuration/query-by-page", queryCostNameListWithCondition, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        // 解析查询参数为 Query 领域模型
        API_HANDLER_QUERY_PARAM(costPageQuery, CostNameQuery, queryParams);
        // 调用执行函数响应结果
        API_HANDLER_RESP_VO(execQueryCostNameListWithCondition(costPageQuery));
    }

    

    // 录入费用名称
    ENDPOINT_INFO(addCostName) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("cost.post.summary"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);


    }
    ENDPOINT(API_M_POST, "/billing-configuration/add-cost-name", addCostName, BODY_DTO(CostAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        // 调用执行函数响应结果
        API_HANDLER_RESP_VO(execAddCostName(dto, authObject->getPayload()));
    }

    //定义修改接口描述
    API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("cost.put.summary"), modifyCostName, StringJsonVO::Wrapper);
    //定义修改接口处理
    API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/billing-configuration/modify-cost-name", modifyCostName, BODY_DTO(CostModifyDTO::Wrapper, dto), execModifyCostName(dto, authObject->getPayload()));
    

private:
    // 获取费用名称列表（全部）
    CostNameJsonVO::Wrapper execQueryCostNameListAll(const CostNameQuery::Wrapper& costPageQuery);

    // 获取费用名称列表（条件+分页）
    CostNamePageJsonVO::Wrapper execQueryCostNameListWithCondition(const CostNameQuery::Wrapper& costPageQuery);

    // 录入费用名称
    StringJsonVO::Wrapper execAddCostName(const CostAddDTO::Wrapper& dto,const PayloadDTO& payload);

    // 修改费用名称
    StringJsonVO::Wrapper execModifyCostName(const CostModifyDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_COST_NAME_CONTROLLER_