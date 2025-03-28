#pragma once
#ifndef _ACTTYPECONTROLLER_H_
#define _ACTTYPECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "domain/query/act_type/ActTypeQuery.h"
#include "domain/dto/act_type/ActTypeDTO.h"
#include "domain/vo/act_type/ActTypeVo.h"
#include "../../lib-oatpp/include/domain/dto/PayloadDTO.h"
// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
* 作业类型获取作业类型列表（条件 + 分页）和录入作业类型
*/
class ActTypeController : public oatpp::web::server::api::ApiController	// 1 继承控制器 
{
public:
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ActTypeController);
	// 3 定义接口

	//  定义查询接口描述
	ENDPOINT_INFO(queryActType) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("act_type.get.act_type_list"));
		//API_DEF_ADD_TITLE(ZH_WORDS_GETTER("user.query-all.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ActTypePageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "act_type_code", ZH_WORDS_GETTER("act_type.field.act_type_code"), "01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "act_type_name", ZH_WORDS_GETTER("act_type.field.act_type_name"), "shang jia", false);
		API_DEF_ADD_QUERY_PARAMS(String, "oper_step_code", ZH_WORDS_GETTER("act_type.field.oper_step_code"), "11", false);
	}
	// 定义查询作业类型接口处理
	ENDPOINT(API_M_GET, "/repository/queryall-acttype", queryActType, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(actQuery, ActTypeQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryActType(actQuery));
	}

	ENDPOINT_INFO(addActType) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("act_type.post.act_type_add"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	// 定义新增接口处理,录入作业类型
	ENDPOINT(API_M_POST, "/repository/adddata-acttype", addActType, BODY_DTO(ActTypeBaseDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddActType(dto, authObject->getPayload()));
	}
private:
	// 4 定义执行函数
	ActTypePageJsonVO::Wrapper execQueryActType(const ActTypeQuery::Wrapper& query);
	Uint64JsonVO::Wrapper execAddActType(const ActTypeBaseDTO::Wrapper& dto, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_ACTTYPECONTROLLER_H_