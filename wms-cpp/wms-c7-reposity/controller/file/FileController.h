#pragma once
/*
 @Author: nanbowan
*/
#ifndef _FILECONTROLLER_H_
#define _FILECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/dto/ordertypes/OrderTypesDTO.h" 

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * 文件操作接口
 */
class FileController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(FileController);
public:
	// 定义一个文件上传接口
	// 定义描述
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("dictionary.ope.import.summary"), uploadFile, StringJsonVO::Wrapper);
	// 定义端点
	API_HANDLER_ENDPOINT(API_M_POST, "/repository/ordertypefile/upload", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadOne(request));

	// 定义一个文件下载接口
	// 定义描述
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("dictionary.ope.export.summary"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("file.field.filename"), "file/data.xslx", true);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/repository/ordertypefile/download", downloadFile, QUERY(String, filename)) {
		return execDownloadFile(filename);
	}



private: // 定义接口执行函数
	// 执行文件上传处理
	StringJsonVO::Wrapper execUploadOne(std::shared_ptr<IncomingRequest> request);
	// 执行文件下载处理
	std::shared_ptr<OutgoingResponse> execDownloadFile(const String& filename);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FILECONTROLLER_H_