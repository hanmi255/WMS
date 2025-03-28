#pragma once
#pragma once
#ifndef _INFO_FILE_CONTROLLER_
#define _INFO_FILE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/vo/info-file/InfoFileVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
* 文件操作示例接口
*/
class InfoFileController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(InfoFileController);
public:
	// 3. 导入企业属性 -- 单文件上传
	ENDPOINT_INFO(UploadCompanyGrade) {
		info->summary = ZH_WORDS_GETTER("file.upload.summary");
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("file.upload.summary"), StringJsonVO::Wrapper);
	}
	// 定义端点
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/entleve/upload-file", UploadCompanyGrade, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadGrade(request, authObject->getPayload()));
	//// 定义一个单文件上传接口
	//// 定义描述
	//API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("file.upload.summary"), uploadFile, StringJsonVO::Wrapper);
	//// 定义端点
	//API_HANDLER_ENDPOINT(API_M_POST, "/entleve/upload-file", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadOne(request));
private: // 定义接口执行函数
	// 执行单文件上传处理
	StringJsonVO::Wrapper execUploadGrade(std::shared_ptr<IncomingRequest> request, const PayloadDTO& dto);
};
#include OATPP_CODEGEN_END(ApiController)

#endif // !_COMPANY_INFO_FILE_CONTROLLER_