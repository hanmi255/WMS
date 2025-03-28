#pragma once
#pragma once
#ifndef _GOODSSTATECONTROLLER_H_
#define _GOODSSTATECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/goodsstate/GoodStateDTO.h"
#include "domain/vo/goodsstate/GoodsStateVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class GoodsStateController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(GoodsStateController);
public: // 定义接口
	// 1.文件上传
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("goodsstate.upload.summary"), uploadFile, StringJsonVO::Wrapper);
	// 定义端点
	API_HANDLER_ENDPOINT(API_M_POST, "pis/upload-pis", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadOne(request));

	//2.文件下载
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("goodsstate.download.summary"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("file.field.filename"), "file/test.jpg", true);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "pis/download-pis", downloadFile, QUERY(String, filename)) {
		return execDownloadFile(filename);
	}

	 // 3.批量删除接口
	ENDPOINT_INFO(batchDeleteGoodsState) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("goodsstate.batch.delete.summary"), StringJsonVO::Wrapper);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "pis/batch-delete-pis", batchDeleteGoodsState, BODY_DTO(BatchDeleteRequestDTO::Wrapper, dto), execBatchRemoveGoodsState(dto));
private: // 定义接口执行函数
	//1.上传文件
	StringJsonVO::Wrapper execUploadOne(std::shared_ptr<IncomingRequest> request);
	//2.下载文件
	std::shared_ptr<OutgoingResponse> execDownloadFile(const String& filename);
	//3.批量删除
	StringJsonVO::Wrapper execBatchRemoveGoodsState(const BatchDeleteRequestDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_GOODSSTATECONTROLLER_H_