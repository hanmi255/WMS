 #pragma once
#ifndef _TOTAL_REICEIVED_FEES_CONTROLLER_
#define _TOTAL_REICEIVED_FEES_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/total-reiceived-fees/TotalReiceivedFeesQuery.h"
#include "domain/vo/total-reiceived-fees/TotalReiceivedFeesVO.h"


#include "ApiHelper.h"
#include "ServerInfo.h"


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class TotalReiceivedFeesController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(TotalReiceivedFeesController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryListOfTotalFees) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("TRF.getthelistoftotalfees"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(TotalReiceivedFeesPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "feestartdate", ZH_WORDS_GETTER("TRF.feestartdate"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "feeenddate", ZH_WORDS_GETTER("TRF.feeenddate"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "customers", ZH_WORDS_GETTER("TRF.customers"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "fees", ZH_WORDS_GETTER("TRF.fees"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "feesname", ZH_WORDS_GETTER("TRF.feesname"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "customersname", ZH_WORDS_GETTER("TRF.customersname"), "", false);
	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/cost-management/total-amount-of-received-fees/query-list-of-total-fees", queryListOfTotalFees, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, TotalReiceivedFeesQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryListOfTotalFees(userQuery, authObject->getPayload()));
	}


	ENDPOINT_INFO(exportFile) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("TRF.export"), Void);
		//定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		//API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("TRF.filename"), "totalreceivedfees.xlsx", true);
		API_DEF_ADD_QUERY_PARAMS(String, "feestartdate", ZH_WORDS_GETTER("TRF.feestartdate"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "feeenddate", ZH_WORDS_GETTER("TRF.feeenddate"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "customers", ZH_WORDS_GETTER("TRF.customers"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "fees", ZH_WORDS_GETTER("TRF.fees"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "feesname", ZH_WORDS_GETTER("TRF.feesname"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "customersname", ZH_WORDS_GETTER("TRF.customersname"), "", false);
	}
	ENDPOINT(API_M_POST, "/cost-management/total-amount-of-received-fees/export", exportFile, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, TotalReiceivedFeesQuery, queryParams);
		// 呼叫执行函数响应结果"/total-amount-of-received-fees/export"
		return execExport(userQuery, authObject->getPayload());
	}


private:
	// 3.3 演示分页查询数据
	TotalReiceivedFeesPageJsonVO::Wrapper execQueryListOfTotalFees(const TotalReiceivedFeesQuery::Wrapper& query, const PayloadDTO& payload);
	
	std::shared_ptr<OutgoingResponse> execExport(const TotalReiceivedFeesQuery::Wrapper& query, const PayloadDTO& payload);

};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _TOTAL_REICEIVED_FEES_CONTROLLER_