#pragma once
#ifndef _QUALITYCONTROLLER_H_
#define _QUALITYCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/qcd/QualityDTO2.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class QualityController2 : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(QualityController2);

public:
	// ******************************最后代码要记得加AUTH权限*****************************************************
	
	// 删除品质代码
	ENDPOINT_INFO(removeQcd) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("qcd.delete.summary"), StringJsonVO::Wrapper);
	}
	// 接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/qcd/delete-qcd", removeQcd, BODY_DTO(DeleteDTO::Wrapper, dto), execDeleteQuality(dto));


	// 单文件上传
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("qcd.upload.summary"), uploadFile, StringJsonVO::Wrapper);
	// 定义端点
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/qcd/upload-qcd", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadFile(request, authObject->getPayload()));

	// 文件下载
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("qcd.download.summary"), Void);

		// 定义授权参数
		API_DEF_ADD_AUTH();

		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("file.field.filename"), "quality_codes" , true);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/qcd/download-qcd", downloadFile, QUERY(String, filename), API_HANDLER_AUTH_PARAME) {
		return execDownloadFile(filename);
	}

private:

	// 删除品质代码
	StringJsonVO::Wrapper execDeleteQuality(const DeleteDTO::Wrapper& dto);
	// 执行单文件上传处理
	StringJsonVO::Wrapper execUploadFile(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload);
	// 执行文件下载处理
	std::shared_ptr<OutgoingResponse> execDownloadFile(const String& filename);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_QUALITYCONTROLLER_H_