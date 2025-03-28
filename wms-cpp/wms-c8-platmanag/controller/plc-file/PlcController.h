#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: tutu
 @Date: 2025/02/23 13:09:12

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _Plc_CONTROLLER_
#define _Plc_CONTROLLER_

#include "domain/GlobalInclude.h"
#include "domain/vo/plc-file/PlcFileVO.h"
#include "domain/query/plc-file/PlcFileQuery.h"
#include "domain/vo/BaseJsonVO.h"
#include "iostream"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

/**
 * 月台管理-PLC指令
 */
class PlcController : public oatpp::web::server::api::ApiController {

	API_ACCESS_DECLARE(PlcController);

public:
	ENDPOINT_INFO(queryAll) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("plc.query-all.summary")); 
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(PlcPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "plc_type1", ZH_WORDS_GETTER("plc.query.type1"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "plc_type2", ZH_WORDS_GETTER("plc.query.type2"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "com_remark1", ZH_WORDS_GETTER("plc.query.remark1"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "com_remark2", ZH_WORDS_GETTER("plc.query.remark2"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "com_no", ZH_WORDS_GETTER("plc.query.com_no"), "", false);
	}
	ENDPOINT(API_M_GET, "/platmanag/plc", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型  
		API_HANDLER_QUERY_PARAM(plcQuery, PlcFileQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAll(plcQuery));
	}
	//查看详情
	ENDPOINT_INFO(queryPlcById) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("plc.query-all.detail"), PlcJsonVO::Wrapper);
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("plc.query-all.detail"), "1", true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/platmanag/plc/query-by-id", queryPlcById, QUERY(String, id), execQueryById(id));
	//新增plc
	ENDPOINT_INFO(addPlc) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("plc.query-all.add"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/platmanag/plc", addPlc, BODY_DTO(PlcAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execAddPlc(dto, authObject->getPayload()));
	}
	//修改PLC指令接口
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("plc.query-all.edit"), modifyPlc, PlcdetailDTO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/platmanag/plc", modifyPlc, BODY_DTO(PlcdetailDTO::Wrapper, dto), execModifyPlc(dto));
	//删除PLC指令
	ENDPOINT_INFO(removePlc) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("plc.query-all.delete"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("plc.file.id"), "1", true);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/platmanag/plc/{id}", removePlc, PATH(String, id), execRemovePlc(id));
	//多文件上传接口
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("plc.query-all.uploadfiles"), uploadFiles, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT(API_M_POST, "/platmanag/plc/uploadfiles", uploadFiles, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadFiles(request));
	//文件下载
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("plc.query-all.downloadfile"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("plc.query-all.filename"), "file/test.jpg", true);
	}
	ENDPOINT(API_M_GET, "/platmanag/plc/download", downloadFile, QUERY(String, filename)) {
		return execDownloadFile(filename);
	}
private:
	PlcPageJsonVO::Wrapper execQueryAll(const PlcFileQuery::Wrapper& query);
	PlcJsonVO::Wrapper execQueryById(const String& id);
	Uint64JsonVO::Wrapper execAddPlc(const PlcAddDTO::Wrapper& dto, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execModifyPlc(const PlcdetailDTO::Wrapper& dto);
	Uint64JsonVO::Wrapper execRemovePlc(const String& id);
	StringJsonVO::Wrapper execUploadFiles(std::shared_ptr<IncomingRequest> request);
	std::shared_ptr<OutgoingResponse> execDownloadFile(const String& filename);
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section

#endif // !_Plc_CONTROLLER_