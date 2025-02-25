#pragma once

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/chuweidingyi/AddCWDTO.h"
#include OATPP_CODEGEN_BEGIN(ApiController)

class ChuWeiDingYiController : public oatpp::web::server::api::ApiController
{
	//	定义控制器访问入口
	API_ACCESS_DECLARE(ChuWeiDingYiController);

	//  定义接口
public:
	// 定义 录入储位接口 描述

	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("chuwei.add.summary"), addCW, Uint64JsonVO::Wrapper);
	// 定义 录入储位接口 处理

	ENDPOINT(API_M_POST, "/chuweiguanli/chuweidingyi/add-CW", addCW, BODY_DTO(AddCWDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME)
	{
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddCW(dto, authObject->getPayload()));
	}

private:
	StringJsonVO::Wrapper execAddCW(const AddCWDTO::Wrapper dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController);