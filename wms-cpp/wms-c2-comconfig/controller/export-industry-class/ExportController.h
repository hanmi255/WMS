#pragma once
#ifndef _EXPORT_CONTROLLER_H_
#define _EXPORT_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 导出行业分类接口
 */
class ExportController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ExportController);
public:
	// 定义一个导出行业分类接口
		// 定义描述
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("chengfeng.export"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("chengfeng.excel"), "file.xlsx", true);
	//其他分页查询参数
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("chengfeng.id"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "classfl_code", ZH_WORDS_GETTER("chengfeng.code"), "007", false);
		API_DEF_ADD_QUERY_PARAMS(String, "classfl_name", ZH_WORDS_GETTER("chengfeng.name"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "classfl_del", ZH_WORDS_GETTER("chengfeng.del"), "yes", false);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/indclas/download-indclas", downloadFile, QUERY(String, filename)) {
		return execExportExcel(filename);
	}

private: // 定义接口执行函数
	
	// 导出行业分类
	std::shared_ptr<OutgoingResponse> execExportExcel(const String& filename);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_EXPORT_CONTROLLER_H_