#ifndef _SEXCODE_CONTROLLER_
#define _SEXCODE_CONTROLLER_

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/vo/stucode/StuCodeVO.h"	
#include "domain/dto/stucode/StuCodeDTO.h"
#include "domain/dto/stucode/StuCodeDelDTO.h"
#include "domain/query/stucode/StuCodeQuery.h"
#include "domain/vo/file/FileVO.h"
#include "oatpp-swagger/Types.hpp"
#include "service/StuCodeService.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include <filesystem>  // C++17 的文件系统库
#include <fstream>     // 文件操作
#include <string>      // 字符串操作
#include <iostream>    // 输出日志
#include "Macros.h"
#include "ExcelComponent.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class SexCodeController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(SexCodeController);
public:
	// 获取性别代码列表
	ENDPOINT_INFO(CodeList)
	{
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("stucode.get"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StuCodePageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("stucode.field.code"), "ES004", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("stucode.field.name"), ZH_WORDS_GETTER("stucode.field.simple.name"), false);
	}
	ENDPOINT(API_M_GET, "/staffconf/sexcode/list", CodeList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(stucodeQuery, StuCodeQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryStucode(stucodeQuery));
	}
	// 修改性别代码
	ENDPOINT_INFO(Modify)
	{
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("stucode.modify"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("sex.filed.id"), "40289fe39406320f01940873c96f002e", true);
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("sex.filed.sexcode"), "SEX004", true);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sex.filed.sexname"), "xxxx", true);
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_PUT, "/staffconf/sexcode/modify", Modify, BODY_DTO(StuCodeDTO::Wrapper, stucodeDto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execModifyStucode(stucodeDto, authObject->getPayload()));
	}
	// 录入性别代码
	ENDPOINT_INFO(Add)
	{
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("stucode.set"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("sex.filed.sexcode"), "SEX004", true);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("sex.filed.sexname"), "xxxx", true);
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_POST, "/staffconf/sexcode/add", Add, BODY_DTO(StuCodeDTO::Wrapper, stucodeDto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execSetStucode(stucodeDto, authObject->getPayload()));
	}
	// 删除性别代码
	ENDPOINT_INFO(Del)
	{
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("stucode.del"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_DEL, "/staffconf/sexcode/delete", Del, BODY_DTO(StuCodeDelDTO::Wrapper, stucodeDto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execDelStucode(stucodeDto));
	}
	// 导入性别代码
	ENDPOINT_INFO(Import) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("file.upload.summary"), StringJsonVO::Wrapper);
	}
	ENDPOINT(API_M_POST, "/staffconf/sexcode/import", Import, REQUEST(std::shared_ptr<IncomingRequest>, request), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execUploadOne(request, authObject->getPayload()));
	}
	// 导出性别代码
	ENDPOINT_INFO(Export) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("file.download.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
	}
	ENDPOINT(API_M_GET, "/staffconf/sexcode/export", Export, API_HANDLER_AUTH_PARAME) {
		return execDownloadFile();
	}
private:
	StuCodePageJsonVO::Wrapper execQueryStucode(StuCodeQuery::Wrapper& stucodeQuery);
	StringJsonVO::Wrapper execModifyStucode(const StuCodeDTO::Wrapper& stucodeDto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execSetStucode(const StuCodeDTO::Wrapper& stucodeDto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execDelStucode(const StuCodeDelDTO::Wrapper& stucodeDto);
	StringJsonVO::Wrapper execUploadOne(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload);
	std::shared_ptr<OutgoingResponse> execDownloadFile();
};


#include OATPP_CODEGEN_END(ApiController)

#endif // !_SEX_CONTROLLER_
