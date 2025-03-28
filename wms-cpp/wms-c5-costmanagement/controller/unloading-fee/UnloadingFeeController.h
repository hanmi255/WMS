#pragma once

#ifndef _UNLOADINGFEE_CONTROLLER_
#define _UNLOADINGFEE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include"../../domain/vo/unloading-fee/UnloadingFeeVO.h"
#include"../../domain/do/UnloadingFeeDO.h"
#include"../../domain/dto/unloading-fee/UnloadingFeeDTO.h"
#include"../../domain/query/unloading-fee/UnloadingFeeQuery.h"

//定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 外包卸货费控制器
 */
class UnloadingFeeController : public oatpp::web::server::api::ApiController //继承控制器
{
	//1.定义控制器访问入口
	API_ACCESS_DECLARE(UnloadingFeeController);
	//定义接口
public:
	//定义分页查询接口描述
	ENDPOINT_INFO(pageQueryUnloadingFee) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("unloadingfee.get.page-query"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(UnloadingFeePageJsonVO);
		//定义查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		//定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "acceptor", ZH_WORDS_GETTER("unloadingfee.field.acceptor"), "zhangsan", false);
		API_DEF_ADD_QUERY_PARAMS(String, "acceptDate_begin", ZH_WORDS_GETTER("unloadingfee.field.acceptDate_begin"), "2024-01-01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "acceptDate_end", ZH_WORDS_GETTER("unloadingfee.field.acceptDate_end"), "2025-01-01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "orderNo", ZH_WORDS_GETTER("unloadingfee.field.orderNo"), "ORDER00", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods", ZH_WORDS_GETTER("unloadingfee.field.goods"), "food", false);
	}
	//定义分页查询接口处理
	ENDPOINT(API_M_GET, "/cost-management/unloading-fee/page-query", pageQueryUnloadingFee, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userquery, UnloadingFeeQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execPageQueryUnloadingFee(userquery, authObject->getPayload()));
	}

	// 定义一个文件下载接口
	// 定义描述
	ENDPOINT_INFO(downloadUnoadingFee) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("file.download.unloadingFee"), Void);
		//定义页面查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		//定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "acceptor", ZH_WORDS_GETTER("unloadingfee.field.operator"), "zhangsan", false);
		API_DEF_ADD_QUERY_PARAMS(String, "acceptDate_begin", ZH_WORDS_GETTER("uloadingfee.field.acceptDate_begin"), "2024-01-01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "acceptDate_end", ZH_WORDS_GETTER("unloadingfee.field.acceptDate_end"), "2025-01-01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "orderNo", ZH_WORDS_GETTER("unloadingfee.field.orderNo"), "ORDER001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "goods", ZH_WORDS_GETTER("unloadingfee.field.goods"), "food", false);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/cost-management/unloading-fee/download", downloadUnoadingFee, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userquery, UnloadingFeeQuery, queryParams);
		return execDownloadUnLoadingFee(userquery);
	}

private:
	//分页查询外包卸货费
	UnloadingFeePageJsonVO::Wrapper execPageQueryUnloadingFee(const UnloadingFeeQuery::Wrapper& query, const PayloadDTO& payload);
	// 执行文件下载处理
	std::shared_ptr<OutgoingResponse> execDownloadUnLoadingFee(const UnloadingFeeQuery::Wrapper& query);
};

#endif // _UNLOADINGFEE_CONTROLLER_