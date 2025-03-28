#pragma once
#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/companyattributes/AttriInfoVO.h"
#include "domain/dto/companyattributes/AttriInfoDTO.h"
#include <iostream>

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

// jvo枚举类型
enum JvoType {
	success,
	error
};

/*工具函数声明区*/
//vector<string> castTovector(Vector<String> vec);
//void initJvo_delete(const AttriDeleteInfoDTO::Wrapper& dto, JvoType jvotype);
//vector<AttriInfoJsonDTO::Wrapper> getDataFromExcel(const string& ExcelPath, const PayloadDTO& dto);
//vector<std::string> getSheetTitle(const string& ExcelPath);
//bool checkExeclDataIsVaild(const string& ExcelPath);
//void deleteTempExecl(const string& ExecPath);
//bool regexCheck(const string& typecodes, const string& typenames);
/*工具函数声明区*/

class AttriController : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(AttriController);
public:
	// 1. 删除企业属性 -- 支持批量删除
	ENDPOINT_INFO(removeCompAttributes) {
		info->summary = ZH_WORDS_GETTER("attrikq.remove-attri.summary");
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("attrikq.remove-attri.summary"),AttriDeleteJsonVO::Wrapper);
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/entattr/delete-entattr", removeCompAttributes, BODY_DTO(AttriDeleteInfoDTO::Wrapper, id), execRemoveAttri(id));

	// 2. 导出企业属性 -- 单文件下载
	ENDPOINT_INFO(downloadArrtibutes) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("attrikq.download-arrti.summary"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("attrikq.download-arrti.summary"), "test.xlsx", true);
	}
	ENDPOINT(API_M_GET, "/entattr/download-entattr", downloadArrtibutes, QUERY(String, filename)) {
		return execDownloadArrtibutes(filename);
	}
	 
	// 3. 导入企业属性 -- 单文件上传
	ENDPOINT_INFO(uploadArrtibutes) {
		info->summary = ZH_WORDS_GETTER("attrikq.remove-attri.summary");
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("attrikq.upload-artri.summary"), StringJsonVO::Wrapper);
	}
	// 定义端点
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/entattr/upload-entattr", uploadArrtibutes, REQUEST(std::shared_ptr<IncomingRequest>, request), execUploadAttri(request, authObject->getPayload()));


private:
	/*删除企业属性*/
	AttriDeleteJsonVO::Wrapper execRemoveAttri(const AttriDeleteInfoDTO::Wrapper& id);
	/*导出企业数据，生成Execl文件*/
	std::shared_ptr<OutgoingResponse> execDownloadArrtibutes(const String& filename);
	/*导入Execl文件*/
	StringJsonVO::Wrapper execUploadAttri(std::shared_ptr<IncomingRequest> reque,const PayloadDTO& dto);

};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section


/*

*/