#pragma once
#ifndef _ENTERPRISE_CONTROLLER_
#define _ENTERPRISE_CONTROLLER_
#include<iostream>
#include "ApiHelper.h"
#include "../../domain/dto/enterpriseDTO.h"
#include "../../domain/vo/enterpriseJsonVO.h"
#include "./domain/vo/enterpriseJsonVO.h"
#include "./domain/dto/enterpriseDTO.h"
#include "./domain/query/PageQuery.h"
#include "./domain/query/enterprisePageQuery.h"
#include "./service/enterpriseService.h"
#include "../lib-oatpp/include/jwt/jwt.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class enterpriseController : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(enterpriseController);
public:
    // TODO - more endpoints here
    //增加企业分类信息端点
    ENDPOINT_INFO(addEnterprise) {
        // 定义接口标题
        //API_DEF_ADD_TITLE("addEnterprise");
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("indclas.func.add"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();
        //增加查询参数描述
        info->queryParams.add<String>("enterpriseClassificationCode").description = ZH_WORDS_GETTER("indclas.field.code");
        info->queryParams.add<String>("enterpriseClassificationName").description = ZH_WORDS_GETTER("indclas.field.name");
        info->queryParams.add<UInt64>("stopInfo").description = ZH_WORDS_GETTER("indclas.field.stopInfo");

        //定义默认值
        info->queryParams["enterpriseClassificationCode"].addExample("default", String("NULL"));
        info->queryParams["enterpriseClassificationName"].addExample("default", String("NULL"));
        info->queryParams["stopInfo"].addExample("default", UInt64(1));
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(addEnterpriseJsonVO);
        info->addConsumes<addEnterpriseDTO::Wrapper>("application/json");
    }
    ENDPOINT(API_M_POST, "/indclas/add-indclas", addEnterprise, BODY_DTO(addEnterpriseDTO::Wrapper, enterpriseInfo), API_HANDLER_AUTH_PARAME) {
        auto payload = authObject->getPayload();//负载信息
        API_HANDLER_RESP_VO(execAddEnterprise(enterpriseInfo, payload));
    }

    //分页查询
    ENDPOINT_INFO(enterprisePageQuery) {

        // 定义接口标题
        //API_DEF_ADD_TITLE("enterprisePageQuery");
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("indclas.func.query-all"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();

        //增加查询参数描述
        //info->queryParams.add<String>("enterpriseClassificationCode").description = "queryCode";
        info->queryParams.add<String>("enterpriseClassificationCode").description = ZH_WORDS_GETTER("indclas.field.code");
        //info->queryParams.add<String>("enterpriseClassificationName").description = "queryName";
        info->queryParams.add<String>("enterpriseClassificationName").description = ZH_WORDS_GETTER("indclas.field.name");
        //info->queryParams.add<UInt64>("pageIndex").description = "queryPageIndex";
        info->queryParams.add<UInt64>("pageIndex").description=ZH_WORDS_GETTER("indclas.field.pageIndex");
        //info->queryParams.add<UInt64>("pageSize").description = "queryPageSize";
        info->queryParams.add<UInt64>("pageSize").description=ZH_WORDS_GETTER("indclas.field.pagesize");
        //增加查询参数默认值
        info->queryParams["enterpriseClassificationCode"].addExample("default", String("NULL"));
        info->queryParams["enterpriseClassificationName"].addExample("default", String("NULL"));
        info->queryParams["pageIndex"].addExample("default", UInt64(1));
        info->queryParams["pageSize"].addExample("default", UInt64(10));

        //定义响应格式
        API_DEF_ADD_RSP_JSON_WRAPPER(enterprisePageJsonVO);
    }
    ENDPOINT(API_M_GET, "/indclas/get-indclaslist", enterprisePageQuery, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_QUERY_PARAM(userQuery, enterprisePageQuery, queryParams);
        API_HANDLER_RESP_VO(execEnterprisePageQuery(userQuery));
    }

    //查询企业分类名称
    ENDPOINT_INFO(getEnterpriseName) {
        // 定义接口标题
        //API_DEF_ADD_TITLE("getEnterpriseName");
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("indclas.func.get-name"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();
        //增加查询参数描述
        //info->queryParams.add<String>("enterpriseClassificationName").description = "queryName";
        //增加查询参数默认值
        //info->queryParams["enterpriseClassificationName"].addExample("default", String("NULL"));
        //定义响应格式
        API_DEF_ADD_RSP_JSON_WRAPPER(enterpriseNameJsonVO);
    }
    ENDPOINT(API_M_GET, "/indclas/get-indclasnamelist", getEnterpriseName, API_HANDLER_AUTH_PARAME) {//, QUERIES(QueryParams, queryParams)
        //API_HANDLER_QUERY_PARAM(userQuery, PageQuery, queryParams);
        API_HANDLER_RESP_VO(execGetEnterpriseName());//userQuery
    }


private:
    addEnterpriseJsonVO::Wrapper execAddEnterprise(const addEnterpriseDTO::Wrapper& enterpriseInfo, const PayloadDTO& payload);
    enterprisePageJsonVO::Wrapper execEnterprisePageQuery(const enterprisePageQuery::Wrapper& query);
    enterpriseNameJsonVO::Wrapper execGetEnterpriseName();
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section


#endif // _ENTERPRISE_CONTROLLER_
