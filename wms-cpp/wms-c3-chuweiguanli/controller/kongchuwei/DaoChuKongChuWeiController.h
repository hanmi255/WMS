#pragma once
#ifndef _DAO_CHU_KONG_CHU_WEI_CONTROLLER_
#define _DAO_CHU_KONG_CHU_WEI_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/vo/kongchuwei/DaoChuKongChuWeiVO.h"
#include "domain/query/kongchuwei/DaoChuKongChuWeiQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 文件操作示例接口
 */
class DaoChuKongChuWeiController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(DaoChuKongChuWeiController);
public:
	// 定义一个文件下载接口
	// 定义描述
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("file.download.summary"), Void);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "bin_store", ZH_WORDS_GETTER("store.field.bin_store"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "ku_wei_shu_xing", ZH_WORDS_GETTER("store.field.ku_wei_shu_xing"), "tiao wen", false);
		API_DEF_ADD_QUERY_PARAMS(String, "chp_shu_xing", ZH_WORDS_GETTER("store.field.chp_shu_xing"), "ri yong", false);
		API_DEF_ADD_QUERY_PARAMS(String, "binid", ZH_WORDS_GETTER("store.field.binid"), "123", false);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/chuweiguanli/kongchuwei/export-excel", downloadFile, QUERIES(QueryParams, queryParams)) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(storeQuery, DaoChuKongChuWeiQuery, queryParams);
		return execDownloadFile(storeQuery);
	}

private: // 定义接口执行函数

	// 执行文件下载处理
	std::shared_ptr<OutgoingResponse> execDownloadFile(const DaoChuKongChuWeiQuery::Wrapper& query);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_DAO_CHU_KONG_CHU_WEI_CONTROLLER_