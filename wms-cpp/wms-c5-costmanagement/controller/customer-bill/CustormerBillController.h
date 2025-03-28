#pragma once

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/customer-bill/CustomerBillVO.h"
#include "domain/query/customer-bill/CustomerBillQuery.h"
#include "ApiHelper.h"
#include "domain/query/PageQuery.h"
#include "domain/GlobalInclude.h"
#include "string"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class CustormerBillController : public oatpp::web::server::api::ApiController {

    // 2 定义控制器访问入口
    API_ACCESS_DECLARE(CustormerBillController);

public:

	// 3.1 定义查询接口描述
	ENDPOINT_INFO(Customer_Bill) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("api.seek_customer_bill"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(CustomerBillPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "customercode", ZH_WORDS_GETTER("field.customer-code"), "001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "fullchinesename", ZH_WORDS_GETTER("field.full-chinese-name"), ZH_WORDS_GETTER("field.sample"), false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/cost-management/customer-bill/query", Customer_Bill, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(Query, CustomerBillQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQuerySample(Query, authObject->getPayload()));
	}



	// 导出未清账单描述接口
	// 定义描述
	ENDPOINT_INFO(unsettled) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("field.export"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "customercode", ZH_WORDS_GETTER("field.customer-code"), "1250", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("bill.filename"), "file/text.xlsx", true);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/cost-management/customer-bill/export-unsettled", unsettled, QUERIES(QueryParams, queryFile)) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(file, UnsettledQuery, queryFile);

		return execExportFile(file);

	}


	// 导出期间账单描述接口
	// 定义描述
	ENDPOINT_INFO(period) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("field.export1"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "customercode", ZH_WORDS_GETTER("field.customer-code"), "1250", true);
		API_DEF_ADD_QUERY_PARAMS(String, "startdate", ZH_WORDS_GETTER("field.begin"), "2020-01-23 00:00:00", true);
		API_DEF_ADD_QUERY_PARAMS(String, "enddate", ZH_WORDS_GETTER("field.end"), "2020-01-29 00:00:00", true);
		//API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("bill.filename"), "file/tsxt.xlsx", true);//这里的问题明天在说

	}
	// 定义端点
	ENDPOINT(API_M_GET, "/cost-management/customer-bill/export-period", period, QUERIES(QueryParams, queryFile)) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(file, PeriodQuery, queryFile);

		return execperiodFile(file);
	}
	


private:

	// 执行未清文件导出处理
	std::shared_ptr<OutgoingResponse> execExportFile(const UnsettledQuery::Wrapper& file);
	// 执行期间文件导出处理
	std::shared_ptr<OutgoingResponse> execperiodFile(const PeriodQuery::Wrapper& file);

	// 3.3 演示分页查询数据
	CustomerBillPageJsonVO::Wrapper execQuerySample(const CustomerBillQuery::Wrapper& query, const PayloadDTO& payload);
};





#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section