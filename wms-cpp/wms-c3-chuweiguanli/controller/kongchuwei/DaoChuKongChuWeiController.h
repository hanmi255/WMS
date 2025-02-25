#pragma once
#ifndef _DAO_CHU_KONG_CHU_WEI_CONTROLLER_
#define _DAO_CHU_KONG_CHU_WEI_CONTROLLER_

#include "../../../lib-oatpp/include/ApiHelper.h"	
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/vo/kongchuwei/DaoChuKongChuWeiVO.h"

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
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("file.field.filename"), "file/test.xlsx", true);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/chuweiguanli/kongchuwei/export-excel", downloadFile, QUERY(String, filename)) {
		return execDownloadFile(filename);
	}

private: // 定义接口执行函数

	// 执行文件下载处理
	std::shared_ptr<OutgoingResponse> execDownloadFile(const String& filename);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_DAO_CHU_KONG_CHU_WEI_CONTROLLER_