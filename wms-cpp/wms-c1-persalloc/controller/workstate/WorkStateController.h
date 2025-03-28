#pragma once
// 王也 2025/2/24
#ifndef _WORKSTATE_CONTROLLER_
#define _WORKSTATE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "domain/GlobalInclude.h"
#include "ExcelComponent.h"
#include "domain/dto/workstate/WorkStateDTO.h"
#include "domain/vo/workstate/WorkStateVO.h"

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class WorkStateController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(WorkStateController);
public: // 定义接口

	// 1.1 定义工作状态删除接口描述
	ENDPOINT_INFO(workstate) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("ba_work_st.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("ba_work_st.field.id"), "1", true);
	}
	// 1.2 定义工作状态删除接口处理
	API_HANDLER_ENDPOINT(API_M_DEL, "ops/delete", workstate, QUERY(String, id), execRemoveWorkState(id));

	// 定义一个单文件上传接口
	//2.1 工作状态文件上传
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("ba_work_st.upload.summary"), uploadFile, StringJsonVO::Wrapper);
	// 定义端点
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "ops/upload", uploadFile, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadOne(request, authObject->getPayload()));



	

	//3.1 工作状态文件下载
	ENDPOINT_INFO(downloadExcel) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("ba_work_st.download.summary"),Void);
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("ba_work_st.download.filename"), "workState.xlsx", true);
		API_DEF_ADD_AUTH();
	}
	// 定义端点
	ENDPOINT(API_M_GET, "ops/download", downloadExcel, QUERY(String, filename), API_HANDLER_AUTH_PARAME) {
		return execDownloadExcel(filename);
	}





private: 
	// 定义上传工作状态文件接口执行函数
	StringJsonVO::Wrapper execUploadOne(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload);
	
	// 定义下载工作状态文件接口执行函数
	std::shared_ptr<OutgoingResponse> execDownloadExcel(const String& filename);
	// 定义删除工作状态接口执行函数
	Uint64JsonVO::Wrapper execRemoveWorkState(const String& id);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_WORKSTATE_CONTROLLER_