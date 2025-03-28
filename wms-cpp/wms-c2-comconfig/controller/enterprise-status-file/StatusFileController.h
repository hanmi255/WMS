#pragma once
#ifndef _STATUSFILECONTROLLER_H_
#define _STATUSFILECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 文件操作示例接口
 */
class StatusFileController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(StatusFileController);
public:

	// **导入企业信息**
	// 定义描述
	ENDPOINT_INFO(uploadFileMore) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("file.upload-more.status-summary"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "filepath", ZH_WORDS_GETTER("/entstat/upload-more"), "'D:\\sample.xlsx'", true);
	}
	// 定义端点
	ENDPOINT(API_M_POST, "/entstat/upload-file", uploadFileMore, QUERY(String, filepath)) {
		auto jvo = execUploadMore(filepath);
		return createResponse([&]() {
			switch (jvo->code) {
			case 200: return Status::CODE_200; // OK
			case 204: return Status::CODE_204; // No Content
			case 400: return Status::CODE_400; // Bad Request
			case 404: return Status::CODE_404; // Not Found
			case 415: return Status::CODE_415; // Unsupported Media Type
			case 500: return Status::CODE_500; // Internal Server Error
			default:  return Status::CODE_500; // 默认返回 500，避免未知错误
			}
			}(), jvo->message + "\n" + jvo->data.getValue(""));
	}



	// 定义一个文件下载接口
	// 定义描述
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("file.download.summary"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("file.field.filename"), "file/test.xlsx", true);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/entstat/download-file", downloadFile, QUERY(String, filename)) {
		return execDownloadFile(filename);
	}

private: // 定义接口执行函数
	// 执行多文件上传处理
	StringJsonVO::Wrapper execUploadMore(const String& filepath);
	// 执行文件下载处理
	std::shared_ptr<OutgoingResponse> execDownloadFile(const String& filename);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_STATUSFILECONTROLLER_H_