#pragma once
#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include "../../domain/vo/cost-sum-vo/CostSumVO.h"
#include "../../domain/query/cost-sum-query/CostSumQuery.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "ExcelComponent.h"
#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section
#include "Macros.h"
class  GetCostSumList : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(GetCostSumList);
public:
    ENDPOINT("GET", "/cost-management/cost-sum/query-cost-sum", GetList , QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
    {

        API_HANDLER_QUERY_PARAM(costquery, CostSumQuery, queryParams);
        API_HANDLER_RESP_VO(executequery(costquery));
    }
    ENDPOINT_INFO(GetList) {
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("GetCostList"));
        API_DEF_ADD_AUTH();
        API_DEF_ADD_RSP_JSON_WRAPPER(CostSumPageJsonVO);
        API_DEF_ADD_PAGE_PARAMS();
        API_DEF_ADD_QUERY_PARAMS(String, "datebegin", ZH_WORDS_GETTER("costdate.begin"), "2022-1-1",false);
        API_DEF_ADD_QUERY_PARAMS(String, "dateend", ZH_WORDS_GETTER("costdate.end"), "2025-1-1", false);
        API_DEF_ADD_QUERY_PARAMS(String, "client", ZH_WORDS_GETTER("client"), "001", false);
        API_DEF_ADD_QUERY_PARAMS(String, "clientname", ZH_WORDS_GETTER("clientname"), "tom", false);
        API_DEF_ADD_QUERY_PARAMS(String, "cost", ZH_WORDS_GETTER("cost"), "001", false);
        API_DEF_ADD_QUERY_PARAMS(String, "costname", ZH_WORDS_GETTER("costname"), "100yuan", false);
     
    }
    ENDPOINT_INFO(ExportData) {
        API_DEF_ADD_COMMON(ZH_WORDS_GETTER("File.download.summary"), Void);
        API_DEF_ADD_PAGE_PARAMS();
        //定义其他查询参数描述
        API_DEF_ADD_QUERY_PARAMS(String, "datebegin", ZH_WORDS_GETTER("costdate.begin"), "2021-01-02", false);
        API_DEF_ADD_QUERY_PARAMS(String, "dateend", ZH_WORDS_GETTER("costdate.end"), "2025-01-03", false);
        API_DEF_ADD_QUERY_PARAMS(String, "client", ZH_WORDS_GETTER("client"), "001", false);
        API_DEF_ADD_QUERY_PARAMS(String, "clientname", ZH_WORDS_GETTER("clientname"), "111", false);
        API_DEF_ADD_QUERY_PARAMS(String, "cost", ZH_WORDS_GETTER("cost.field.cost_code"), "2201", false);
        API_DEF_ADD_QUERY_PARAMS(String, "costname", ZH_WORDS_GETTER("costname"), "111", false);

    }
    // 定义端点
    ENDPOINT(API_M_GET, "/cost-management/cost-sum/export-data", ExportData, QUERIES(QueryParams, queryParams)) {
        API_HANDLER_QUERY_PARAM(userquery, CostSumQuery, queryParams);
        return execDownloadFile(userquery);
    }
  
private:
    CostSumPageJsonVO::Wrapper executequery(const CostSumQuery::Wrapper& query);
    std::shared_ptr<OutgoingResponse> execDownloadFile(const CostSumQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)