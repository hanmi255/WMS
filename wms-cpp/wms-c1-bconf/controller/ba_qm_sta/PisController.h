#pragma once

#ifndef _PIS_CONTROLLER_
#define _PIS_CONTROLLER_

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/ba_qm_sta/PisQuery.h"
#include "domain/dto/ba_qm_sta/PisDTO.h"
#include "domain/vo/ba_qm_sta/PisVO.h"
#include "oatpp/web/server/api/ApiController.hpp"
#include "domain/query/PageQuery.h"
#include "ApiHelper.h"

// 1. 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class PisController : public oatpp::web::server::api::ApiController {
    // 2 定义控制器访问入口
    API_ACCESS_DECLARE(PisController);
    // 3 定义接口
public:
    // 3.1 定义pis分页查询接口描述
    ENDPOINT_INFO(queryPis) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("pis.get.summary"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(PisPageJsonVO);
        // 定义分页查询参数描述
        API_DEF_ADD_PAGE_PARAMS();
        // 定义其他查询参数描述
        API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("pis.field.qm_sta_code"), "QS001", false);
        API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("pis.field.qm_sta_name"), ZH_WORDS_GETTER("pis.field.qm_sta_name_ex"), false);
    }
    // 3.2 定义qis分页查询接口处理
    ENDPOINT(API_M_GET, "/pis/list-pis", queryPis, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        // 解析查询参数为Query领域模型
        API_HANDLER_QUERY_PARAM(userquery, PisQuery, queryParams);
        // 呼叫执行函数响应结果
        API_HANDLER_RESP_VO(execQueryPis(userquery, authObject->getPayload()));
    }

    // 3.1 定义pis新增数据接口描述
    ENDPOINT_INFO(addPis) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("pis.post.summary"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
    }
    // 3.2 定义pis新增数据接口处理
    ENDPOINT(API_M_POST, "/pis/add-pis", addPis, BODY_DTO(PisAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        // 呼叫执行函数响应结果
        API_HANDLER_RESP_VO(execAddPis(dto,authObject->getPayload()));
    }

    // 3.1 定义pis修改接口描述
    ENDPOINT_INFO(modifyPis) {
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("pis.put.summary"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME)
        API_DEF_ADD_AUTH();
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
    }
    // 3.2 定义pis修改接口处理
    ENDPOINT(API_M_PUT, "/pis/modify-pis", modifyPis, BODY_DTO(PisDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_RESP_VO(execModifyPis(dto,authObject->getPayload()));
    }

private:
    // 3.3 演示分页查询
    PisPageJsonVO::Wrapper execQueryPis(const PisQuery::Wrapper& query, const PayloadDTO& payload);
    // 3.3 演示新增数据
    StringJsonVO::Wrapper execAddPis(const PisAddDTO::Wrapper& dto,const PayloadDTO& payload);
    // 3.3 演示修改数据
    StringJsonVO::Wrapper execModifyPis(const PisDTO::Wrapper& dto, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End ApiController codegen section
#endif



    // 3.1 定义pis-code条件查询接口描述
    //ENDPOINT_INFO(queryPisByCode) {
    //    // 定义通用描述
    //    API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("pis.query-by-code.summary"), PisJsonVO::Wrapper);
    //    // 定义参数描述
    //    API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("pis.field.qm_sta_code"), "1", true);
    //}
    //// 3.2 定义pis-code条件查询接口处理
    //API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/pis/query-by-code", queryPisByCode, QUERY(String, code), execQueryByCode(code));

    // 3.1 定义pis-sta条件查询接口描述
    //ENDPOINT_INFO(queryPisBySta) {
    //    // 定义通用描述
    //    API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("pis.query-by-sta.summary"), PisJsonVO::Wrapper);
    //    // 定义参数描述
    //    API_DEF_ADD_QUERY_PARAMS(String, "sta", ZH_WORDS_GETTER("pis.field.qm_sta_name"), "yes", true);
    //}
    // 3.2 定义pis-sta条件查询接口处理
    //API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/pis/query-by-sta", queryPisBySta, QUERY(String, sta), execQueryBySta(sta));

    // 3.3 演示code查询数据
    //PisJsonVO::Wrapper execQueryByCode(const String& code);
    // 3.3 演示sta查询数据
    //PisJsonVO::Wrapper execQueryBySta(const String& sta);
