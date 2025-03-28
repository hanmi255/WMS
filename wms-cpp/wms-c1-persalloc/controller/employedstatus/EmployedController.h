#pragma once
#include <iostream>
#include "domain/GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/employedstatus/EmployedStatusDTO.h"
#include "domain/vo/employedstatus/EmployedStatusVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class EmployedController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(EmployedController)
public:

	// 根据编码code删除
	ENDPOINT_INFO(removeByCode) {
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);

		info->summary = ZH_WORDS_GETTER("employed.delete.summary");
	}
	ENDPOINT(API_M_DEL, "/es/remove-es", removeByCode, BODY_DTO(EmployedBatchRemoveDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execRemoveByCode(dto));
	}

	// 导入
	ENDPOINT_INFO(importStatus) {
		API_DEF_ADD_AUTH();
		info->summary = ZH_WORDS_GETTER("employed.import.summary");
		API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
	}
	ENDPOINT("POST", "/es/import", importStatus, REQUEST(std::shared_ptr<IncomingRequest>, request), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execUploadOne(request, authObject->getPayload()));
	}


	// 导出
	ENDPOINT_INFO(exportStatus) {
		API_DEF_ADD_AUTH();
	//	API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("file.field.filename"), "ba_pos_sta.xlsx", true);
		info->summary = ZH_WORDS_GETTER("employed.export.summary");
	}
	ENDPOINT("GET", "/es/export", exportStatus, API_HANDLER_AUTH_PARAME) {
		return execDownloadFile();
	}


private:
	Uint64JsonVO::Wrapper execRemoveByCode(const EmployedBatchRemoveDTO::Wrapper& code);
	// 执行文件下载处理
	std::shared_ptr<OutgoingResponse> execDownloadFile();
	// 执行单文件上传处理
	StringJsonVO::Wrapper execUploadOne(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload);
};


#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section