#pragma once

#ifndef _EXPENSEINOUTCONTROLLER_H_
#define _EXPENSEINOUTCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "../../domain/query/expensetype/ExpenseTypeQuery.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 文件操作示例接口
 */
class ExpenseinoutController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ExpenseinoutController);
public:





	/*导出费用类型*/
	ENDPOINT_INFO(exportExpenceType) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expense.download.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_QUERY_PARAMS(String, "cost_type_code", ZH_WORDS_GETTER("expense.field.cost_code"),"",false);
		API_DEF_ADD_QUERY_PARAMS(String, "cost_type_name", ZH_WORDS_GETTER("expense.field.cost_type_name"), "", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "cost_type_del", ZH_WORDS_GETTER("expense.field.cost_type_del"), "", false);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/expense/download", exportExpenceType, QUERIES(QueryParams, exportParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为ExportGoodsDiffPostQuery领域模型
		API_HANDLER_QUERY_PARAM(exportQuery, ExpenseTypeQuery, exportParams);
		// 呼叫执行函数响应结果

		return execExportData(exportQuery);
	}

	//导入费用类型
	ENDPOINT_INFO(uploadExpenceType) {
		//    // 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("expense.upload.summary"));
		API_DEF_ADD_AUTH();
	}

	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/expense/upload", uploadExpenceType, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadExpenceType(request, authObject->getPayload()));


private: // 定义接口执行函数
	// 执行上传文件处理
	StringJsonVO::Wrapper execUploadExpenceType(std::shared_ptr<IncomingRequest> request,const PayloadDTO& payload);
	// 执行文件下载处理
	std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> execExportData(const ExpenseTypeQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_EXPENSEINOUTCONTROLLER_H_