#pragma once
#pragma once

#ifndef _SHUXINGCONTROLLER_H_
#define _SHUXINGCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "../../domain/dto/chanpingshuxingdto/ShuxingDTO.h"
#include "../../service/chanpingshuxing/shuxingService.h"
#include "Macros.h"
#include "ExcelComponent.h"
#include OATPP_CODEGEN_BEGIN(ApiController)


class ShuxingController : public oatpp::web::server::api::ApiController
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(ShuxingController);
public:
	//修改描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("shuxing.xiugai.miaoshu"), xiugai, Uint64JsonVO::Wrapper);
	//API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/pa/modify", xiugai, BODY_DTO(ShuxingDTO::Wrapper, dto), XiugaiShuxing(dto, authObject->getPayload()));
	ENDPOINT(API_M_PUT, "/pa/modify", xiugai, BODY_DTO(ShuxingDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(XiugaiShuxing(dto, authObject->getPayload()));
	}
	//删除描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("shuxing.shanchu.miaoshu"), shanchu, Uint64JsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/pa/delete", shanchu, BODY_DTO(ShuxingShanChuDTO::Wrapper, dto), ShanchuShuxing(dto));
	 
	//导出产品属性
	// 定义描述
	ENDPOINT_INFO(daochu) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("shuxing.daochu.miaoshu"), Void);
		API_DEF_ADD_AUTH();
		//API_DEF_ADD_QUERY_PARAMS(UInt64, "id", ZH_WORDS_GETTER("shuxing.daochu.shuoming"), 1, true);
	}
	ENDPOINT(API_M_GET, "/pa/download", daochu, REQUEST(std::shared_ptr<IncomingRequest>, request), API_HANDLER_AUTH_PARAME) {
		return DaochuShuxing( );
	}
	// 导入属性
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("shuxing.daoru.miaoshu"), daoru, StringJsonVO::Wrapper);
	
	//API_HANDLER_ENDPOINT(API_M_POST, "/pa/upload", daoru, REQUEST(std::shared_ptr<IncomingRequest>, request), DaoruShuxing(request));
	ENDPOINT(API_M_POST, "/pa/upload", daoru, REQUEST(std::shared_ptr<IncomingRequest>, request), API_HANDLER_AUTH_PARAME) {

		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(DaoruShuxing(request, authObject->getPayload()));
	}
private: // 定义接口执行函数
	// 修改属性
	StringJsonVO::Wrapper XiugaiShuxing(const ShuxingDTO::Wrapper& dto,const PayloadDTO& payload);
	//删除属性
	StringJsonVO::Wrapper ShanchuShuxing(const ShuxingShanChuDTO::Wrapper& dto);
	//导出属性
	std::shared_ptr<OutgoingResponse> DaochuShuxing( );
	//导入属性
	StringJsonVO::Wrapper DaoruShuxing(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload);
};
/////////1111111111111
#include OATPP_CODEGEN_END(ApiController)

#endif  