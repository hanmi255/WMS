#pragma once
/*
 @Author: nanbowan
*/
#ifndef _DegFileController_H_
#define _DegFileController_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/dto/library/LibraryDTO.h" 

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 文件操作接口
 */
class LibraryFileController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(LibraryFileController);
public:
	// 定义一个文件上传接口
	// 定义描述
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("dictionary.libraryope.import.summary"), uploadLibraryFile, StringJsonVO::Wrapper);
	// 定义端点
	API_HANDLER_ENDPOINT(API_M_POST, "/repository/libraryfile/upload", uploadLibraryFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadLibrary(request));

	// 定义一个文件下载接口
	// 定义描述
	ENDPOINT_INFO(downloadLibraryFile) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("dictionary.libraryope.export.summary"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("file.field.filename"), "file/data.xslx", true);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/repository/libraryfile/download", downloadLibraryFile, QUERY(String, filename)) {
		return execDownloadLibraryFile(filename);
	}



private: // 定义接口执行函数
	// 执行文件上传处理
	StringJsonVO::Wrapper execUploadLibrary(std::shared_ptr<IncomingRequest> request);
	// 执行文件下载处理
	std::shared_ptr<OutgoingResponse> execDownloadLibraryFile(const String& filename);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_DegFileController_H_