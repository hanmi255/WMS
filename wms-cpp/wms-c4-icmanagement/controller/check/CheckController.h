#pragma once
#ifndef _CHECK_CONTROLLER_
#define _CHECK_CONTROLLER_
#include "domain/GlobalInclude.h"
#include "domain/vo/check/CheckVO.h"
#include "domain/query/check/CheckQuery.h"			
#include "domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

/*
 *盘点人基础资料
 */
class CheckController : public oatpp::web::server::api::ApiController
{
    API_ACCESS_DECLARE(CheckController);

public:
    ENDPOINT_INFO(queryCheck)
    {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("mql.ask.check"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(CheckPageJsonVO);
        // 定义分页查询参数描述
        API_DEF_ADD_PAGE_PARAMS();
        // 定义其他查询参数描述
        API_DEF_ADD_QUERY_PARAMS(String, "bin_id", ZH_WORDS_GETTER("mql.rest.bin_id"), "", false);
        API_DEF_ADD_QUERY_PARAMS(String, "tin_id", ZH_WORDS_GETTER("mql.rest.tin_id"), "", false);
        API_DEF_ADD_QUERY_PARAMS(String, "goods_id", ZH_WORDS_GETTER("mql.goods.goods_id"), "", false);
        // API_DEF_ADD_QUERY_PARAMS(String, "goods_name", ZH_WORDS_GETTER("mql.goods.goods_name"), ZH_WORDS_GETTER("mql.rest.cane"), false);
        API_DEF_ADD_QUERY_PARAMS(String, "goods_name", ZH_WORDS_GETTER("mql.goods.goods_name"), "", false);
        API_DEF_ADD_QUERY_PARAMS(String, "goods_pro_data", ZH_WORDS_GETTER("mql.goods.goods_pro_data"), "", false);
        API_DEF_ADD_QUERY_PARAMS(String, "goods_batch", ZH_WORDS_GETTER("mql.goods.goods_batch"), "", false);
        API_DEF_ADD_QUERY_PARAMS(String, "cus_name", ZH_WORDS_GETTER("mql.cus.cus_name"), "", false);
        API_DEF_ADD_QUERY_PARAMS(String, "cus_code", ZH_WORDS_GETTER("mql.cus.cus_code"), "", false);
        // API_DEF_ADD_QUERY_PARAMS(String, "stt_sta", ZH_WORDS_GETTER("mql.stt.stt_sta"), ZH_WORDS_GETTER("mql.rest.going"), false);
        API_DEF_ADD_QUERY_PARAMS(String, "stt_sta", ZH_WORDS_GETTER("mql.stt.stt_sta"), "", false);
        API_DEF_ADD_QUERY_PARAMS(String, "create_date", ZH_WORDS_GETTER("mql.creat.create_date"), "", false);
    }
    ENDPOINT(API_M_GET, "/inv/check", queryCheck, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
    {
        // 解析查询参数为Query领域模型
        API_HANDLER_QUERY_PARAM(invQuery, CheckQuery, queryParams);
        // 呼叫执行函数响应结果
        API_HANDLER_RESP_VO(execQueryCheck(invQuery));
    }

    ENDPOINT_INFO(exportCheck)
    {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("bin.download.mql"));
        // 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
        API_DEF_ADD_AUTH();

        // 定义分页查询参数描述
        API_DEF_ADD_PAGE_PARAMS();
    }
    // 定义端点
    ENDPOINT(API_M_GET, "/inv/download", exportCheck, QUERIES(QueryParams, exportParams), API_HANDLER_AUTH_PARAME)
    {
        // 解析查询参数为CheckQuery领域模型
        API_HANDLER_QUERY_PARAM(binQuery, CheckQuery, exportParams);
        // 呼叫执行函数响应结果
        return execExportCheck(binQuery);
    }

private:
    CheckPageJsonVO::Wrapper execQueryCheck(const CheckQuery::Wrapper &query);
    std::shared_ptr<OutgoingResponse> execExportCheck(const CheckQuery::Wrapper &query);
    // TODO - more endpoints here
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section
#endif //!_CHECK_CONTROLLER_