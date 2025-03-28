#pragma once
#ifndef _Comdeg_Controller_
#define _Comdeg_Controller_

#include "domain/GlobalInclude.h"
#include "domain/dto/comdeg/ComdegDTO.h"
#include "domain/vo/comdeg/ComdegVO.h"
#include "domain/query/comdeg/ComdegQuery.h"
#include "../lib-oatpp/include/domain/vo/BaseJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

/**
 * 公司等级信息管理
 */
class ComdegController : public oatpp::web::server::api::ApiController {

    API_ACCESS_DECLARE(ComdegController)

public:
	ENDPOINT_INFO(querycomdegAll) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("com.query-all.summary"));
		
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(ComdegPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "degname", ZH_WORDS_GETTER("com.field.degname"), "1", false);
		API_DEF_ADD_QUERY_PARAMS(String, "degcode", ZH_WORDS_GETTER("com.field.degcode"), "A", false);
		
	}


	// 定义公司等级信息查询接口处理
    ENDPOINT(API_M_GET, "/entlevel/get-entlevellist", querycomdegAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {

		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(comdegQuery, ComdegQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execcomdegAll(comdegQuery));
    }

	//定义公司等级信息新增接口描述
	ENDPOINT_INFO(addcomdeg) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("com.add.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
	}
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/entattr/add-entlevel", addcomdeg, BODY_DTO(ComdegAddDTO::Wrapper, dto)
										, execAddComdeg(dto, authObject->getPayload()));
	
	//定义公司等级信息新增接口处理
	/*ENDPOINT(API_M_POST, "/entattr/add-entlevel", addcomdeg, BODY_DTO(ComdegDetailDTO::Wrapper, dto)) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddComdeg(dto, authObject->getPayload()));
	}*/

private:
	//公司等级信息分页查询数据
	ComdegPageJsonVO::Wrapper execcomdegAll(const ComdegQuery::Wrapper& query);
	//公司等级信息新增数据
	Uint64JsonVO::Wrapper execAddComdeg(const ComdegAddDTO::Wrapper& dto, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section

#endif // !_Comdeg_Controller_