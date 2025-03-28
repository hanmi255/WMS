#pragma once

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class MyController : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(MyController);
public:
    ENDPOINT_INFO(root) {
        info->summary = ZH_WORDS_GETTER("api.summary");
       
    }

    ENDPOINT_INFO(test) {
        info->summary = ZH_WORDS_GETTER("api.summary");
        //请求参数的描述
        API_DEF_ADD_PAGE_PARAMS();
        //响应格式描述
        API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
    }

    ENDPOINT("GET", "/", root) {
        return createResponse(Status::CODE_200, ZH_WORDS_GETTER("test"));
    }


    ENDPOINT("GET", "/test", test, QUERIES(QueryParams,params)) {
        //解析查询参数
        API_HANDLER_QUERY_PARAM(query, PageQuery, params);
        //响应处理结果
        API_HANDLER_RESP_VO(excuteTest(query));
    }

private:
    StringJsonVO::Wrapper excuteTest(const PageQuery::Wrapper& query);

};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section