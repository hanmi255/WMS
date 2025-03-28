#pragma once

#ifndef _COMPANY_INFORMATION_CONTROLLER_
#define _COMPANY_INFORMATION_CONTROLLER_

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/PageQuery.h" 
#include "ExcelComponent.h"
#include "FastDfsClient.h"
#include "ApiHelper.h"
#include "ServerInfo.h"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

/*
* 导入和导出公司信息
*/

class ComInfoController : public oatpp::web::server::api::ApiController {
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ComInfoController);
public:
	ENDPOINT_INFO(importCompanyInfo) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("comconfig.cominfo.import"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "Sheet name", ZH_WORDS_GETTER("comconfig.file.sheetname"), "Page", true);
		API_DEF_ADD_QUERY_PARAMS(Int16, "Number of sheet page", ZH_WORDS_GETTER("comconfig.file.sheetnumber"), 1, true);
	}
	// 定义端点
	ENDPOINT(API_M_POST, "/cominfo/upload-cominfo", importCompanyInfo, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
		auto jvo = execInputComInfo(request);
		//return createResponse(Status::CODE_200, "企业信息导入完成");
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
	// **导出企业信息**
	// 定义描述
	ENDPOINT_INFO(exportCompanyInfo) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("comconfig.cominfo.export"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("comconfig.file.filename"), "file.xlsx", true);
		//其他分页查询参数
		//API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("comconfig.cominfo.id"),"Apple" , false);
		//API_DEF_ADD_QUERY_PARAMS(String, "create_name", ZH_WORDS_GETTER("comconfig.cominfo.create_name"), "Steve Jobs", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "create_by", ZH_WORDS_GETTER("comconfig.cominfo.create_by"), "Jobs", fasle);
		//API_DEF_ADD_QUERY_PARAMS(String, "create_date", ZH_WORDS_GETTER("comconfig.field.filename"), "1976/4/1", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "update_name", ZH_WORDS_GETTER("comconfig.cominfo.update_name"), " ", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "update_by", ZH_WORDS_GETTER("comconfig.cominfo.update_by"), " ", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "update_date", ZH_WORDS_GETTER("comconfig.cominfo.update_date"), " ", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "sys_org_code", ZH_WORDS_GETTER("comconfig.cominfo.sys_org_code"), " ", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "sys_company_code", ZH_WORDS_GETTER("comconfig.cominfo.sys_company_code"), " ", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "com_code", ZH_WORDS_GETTER("comconfig.cominfo.com_code"), " ", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "com_zh_name", ZH_WORDS_GETTER("comconfig.cominfo.com_zh_name"), " ", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "com_zh_aname", ZH_WORDS_GETTER("comconfig.cominfo.com_zh_aname"), " ", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "com_zh_addr", ZH_WORDS_GETTER("comconfig.cominfo.com_zh_addr"), " ", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "com_en_name", ZH_WORDS_GETTER("comconfig.cominfo.com_en_name"), " ", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "com_en_aname", ZH_WORDS_GETTER("comconfig.cominfo.com_en_aname"), " ", false);
	}
	// 定义端点
	ENDPOINT(API_M_GET, "/cominfo/download-cominfo", exportCompanyInfo, QUERY(String, filename)) {
		return execOutputComInfo(filename);
	}
private:
	// 导入企业信息
	StringJsonVO::Wrapper execInputComInfo(std::shared_ptr<IncomingRequest> request);

	// 导出企业信息
	std::shared_ptr<OutgoingResponse> execOutputComInfo(const String& filename);
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section

#endif // !_COMPANY_INFORMATION_CONTROLLER_
