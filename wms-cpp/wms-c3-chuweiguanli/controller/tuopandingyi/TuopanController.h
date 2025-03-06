#pragma once

#ifndef _TUOPAN_CONTROLLER_
#define _TUOPAN_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
//#include "domain/dto/sample/SampleDTO.h"
#include "domain/vo/tuopandingyi/TuopanVO.h"
#include "domain/query/tuopandingyi/TuopanQuery.h"
#include "domain/dto/tuopandingyi/DeleteTuopanDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 托盘控制器
 */
class TuopanController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(TuopanController);
	// 3 定义接口
public:
	// 托盘分页查询接口描述
	ENDPOINT_INFO(querySample) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("tuopan.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(TuopanPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "tin_id", ZH_WORDS_GETTER("tuopan.field.id"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "tin_sort", ZH_WORDS_GETTER("tuopan.field.order"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "bin_id", ZH_WORDS_GETTER("tuopan.field.place"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "tin_status", ZH_WORDS_GETTER("tuopan.field.status"), "xxx", false);
	}
	// 托盘分页查询接口处理
	ENDPOINT(API_M_GET, "/chuweiguanli/tuopandingyi/fenyechaxun", querySample, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, TuopanQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryTuopan(userQuery, authObject->getPayload()));
	}

	// 托盘修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("tuopan.put.summary"), modifySample, Uint64JsonVO::Wrapper);
	// 托盘修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/chuweiguanli/tuopandingyi/xiugaituopan", modifySample, BODY_DTO(TuopanDTO::Wrapper, dto), execModifyTuopan(dto));

	// 托盘删除接口描述
	ENDPOINT_INFO(removeSample) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("tuopan.delete.summary"), Uint64JsonVO::Wrapper);
	}
	// 托盘删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/chuweiguanli/tuopandingyi/shanchutuopan/{id}", removeSample,BODY_DTO(DeleteTuopanDTO::Wrapper,idlist), execRemoveTuopan(idlist));

	// 3.3 托盘分页查询数据
	TuopanPageJsonVO::Wrapper execQueryTuopan(const TuopanQuery::Wrapper& query, const PayloadDTO& payload);
	// 3.3 托盘修改数据
	StringJsonVO::Wrapper execModifyTuopan(const TuopanDTO::Wrapper& dto);
	// 3.3 托盘删除数据
	StringJsonVO::Wrapper execRemoveTuopan(const DeleteTuopanDTO::Wrapper& idlist);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _TUOPAN_CONTROLLER_