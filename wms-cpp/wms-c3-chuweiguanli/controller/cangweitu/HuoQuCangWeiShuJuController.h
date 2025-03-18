#pragma once
#ifndef _HUO_QU_CANG_WEI_SHU_JU_CONTROLLER_
#define _HUO_QU_CANG_WEI_SHU_JU_CONTROLLER_
#include "domain/GlobalInclude.h"
#include "domain/vo/cangweitu/HuoQuCangWeiShuJuVO.h"
#include "domain/query/cangweitu/HuoQuCangWeiShuJuQuery.h"


#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class HuoQuCangWeiShuJuController : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(HuoQuCangWeiShuJuController);
public:
    // 3.1 定义查询接口描述
    ENDPOINT_INFO(querystore) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("store.query-forward.summary"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(HuoQuCangWeiShuJuJsonVO);
        // 定义其他查询参数描述
        API_DEF_ADD_QUERY_PARAMS(String, "bin_store", ZH_WORDS_GETTER("store.field.bin_store"), "1", false);
        API_DEF_ADD_QUERY_PARAMS(String, "ku_wei_bian_ma", ZH_WORDS_GETTER("store.field.ku_wei_bian_ma"), "123", false);
        API_DEF_ADD_QUERY_PARAMS(String, "znode", ZH_WORDS_GETTER("store.field.znode"), "123", false);
        API_DEF_ADD_QUERY_PARAMS(String, "xnode", ZH_WORDS_GETTER("store.field.xnode"), "123", false);
        API_DEF_ADD_QUERY_PARAMS(String, "ynode", ZH_WORDS_GETTER("store.field.ynode"), "123", false);
    }

    ENDPOINT(API_M_GET, "/chuweiguanli/cangweitu/query-store", querystore, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        // 解析查询参数为Query领域模型
        API_HANDLER_QUERY_PARAM(storeQuery, HuoQuCangWeiShuJuQuery, queryParams);
        // 呼叫执行函数响应结果
        API_HANDLER_RESP_VO(execQueryStore(storeQuery));
    }

    //ENDPOINT_INFO(test) {
    //    info->summary = ZH_WORDS_GETTER("api.summary");
    //    //请求参数的描述信息
    //    API_DEF_ADD_PAGE_PARAMS();
    //    //响应格式描述
    //    API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
    //}
    //ENDPOINT("GET", "/test", test, QUERIES(QueryParams, params)) {
    //    //解析查询参数
    //    API_HANDLER_QUERY_PARAM(query, PageQuery, params);
    //    //响应处理结果
    //    API_HANDLER_RESP_VO(excuteTest(query));
    //}
private:
    HuoQuCangWeiShuJuJsonVO::Wrapper execQueryStore(const HuoQuCangWeiShuJuQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section

#endif// !_HUO_QU_CANG_WEI_SHU_JU_CONTROLLER_