#pragma once
#ifndef _TP_CONTROLLER_H_
#define _TP_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/tuopandingyi/QueryTPVO.h"
#include "domain/dto/tuopandingyi/AddTPDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class TPController : public oatpp::web::server::api::ApiController {
    // 定义控制器访问接口
	API_ACCESS_DECLARE(TPController);
public:
	// 获取托盘名称列表
	ENDPOINT_INFO(QueryTP) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("TP.QueryTPSummary"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(QueryTPListJsonVO);
	}
	ENDPOINT(API_M_GET, "/chuweiguanli/tuopandingyi/querytp", QueryTP, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryTP());
	}

	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("TP.AddTPSummary"), addTP, Uint64JsonVO::Wrapper)
	ENDPOINT(API_M_POST, "/chuweiguanli/tuopandingyi/addtp", addTP, BODY_DTO(AddTPDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddTP(dto, authObject->getPayload()));
	}
private:
	// 获取托盘名称列表
	QueryTPListJsonVO::Wrapper execQueryTP();
	StringJsonVO::Wrapper execAddTP(const AddTPDTO::Wrapper &dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)
#endif