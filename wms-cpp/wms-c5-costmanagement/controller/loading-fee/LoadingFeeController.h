#pragma once
 
#ifndef _LOADINGFEE_CONTROLLER_
#define _LOADINGFEE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include"../../domain/vo/loading-fee/LoadingFeeVO.h"
#include"../../domain/dto/loading-fee/LoadingFeeDTO.h"
#include"../../domain/query/loading-fee/LoadingFeeQuery.h"

//定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 外包卸货费控制器
 */
class LoadingFeeController : public oatpp::web::server::api::ApiController //继承控制器
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(LoadingFeeController);
	//定义接口
public:
	//1.定义分页查询接口描述
	ENDPOINT_INFO(pageQueryLoadingFee) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("loadingfee.get.page-query"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(LoadingFeePageJsonVO);
		//定义页面查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		//定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "Operator", ZH_WORDS_GETTER("loadingfee.field.operator"), "zhangsan", false);
		API_DEF_ADD_QUERY_PARAMS(String, "operateDate_begin", ZH_WORDS_GETTER("loadingfee.field.operateDate_begin"), "2024-01-01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "operateDate_end", ZH_WORDS_GETTER("loadingfee.field.operateDate_end"), "2025-01-01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "orderNo", ZH_WORDS_GETTER("loadingfee.field.orderNo"), "ORDER001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods", ZH_WORDS_GETTER("loadingfee.field.goods"), "food", false);
	}
	//定义分页查询接口处理
	ENDPOINT(API_M_GET, "/cost-management/loading-fee/page-query", pageQueryLoadingFee, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userquery, LoadingFeeQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execPageQueryLoadingFee(userquery, authObject->getPayload()));
	}

	// 2.定义一个文件下载接口
	// 定义描述
	ENDPOINT_INFO(downloadLoadingFee) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("file.download.loadingFee"), Void);
		//定义页面查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		//定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "Operator", ZH_WORDS_GETTER("loadingfee.field.operator"), "zhangsan", false);
		API_DEF_ADD_QUERY_PARAMS(String, "operateDate_begin", ZH_WORDS_GETTER("loadingfee.field.operateDate_begin"), "2024-01-01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "operateDate_end", ZH_WORDS_GETTER("loadingfee.field.operateDate_end"), "2025-01-01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "orderNo", ZH_WORDS_GETTER("loadingfee.field.orderNo"), "ORDER001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods", ZH_WORDS_GETTER("loadingfee.field.goods"), "food", false);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/cost-management/loading-fee/download", downloadLoadingFee, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userquery, LoadingFeeQuery, queryParams);
		return execDownloadLoadingFee(userquery);
	}
private:
	//分页查询外包装车费
	LoadingFeePageJsonVO::Wrapper execPageQueryLoadingFee(const LoadingFeeQuery::Wrapper& query, const PayloadDTO& payload);
	// 执行文件下载处理
	std::shared_ptr<OutgoingResponse> execDownloadLoadingFee(const LoadingFeeQuery::Wrapper& query);
};

#endif // _LOADINGFEE_CONTROLLER_