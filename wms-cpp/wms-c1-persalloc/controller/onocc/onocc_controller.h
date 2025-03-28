#pragma once

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/onocc/onocc_query.h"
#include "domain/dto/onocc/onocc_dto.h"
#include "domain/vo/onocc/onocc_vo.h"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class onocc_controller : public oatpp::web::server::api::ApiController {
	API_ACCESS_DECLARE(onocc_controller);
public:
	//获取在职状态列表
	ENDPOINT_INFO(queryEs)
	{
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("es.query-all.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_RSP_JSON_WRAPPER(EsPageJsonVO);
		API_DEF_ADD_QUERY_PARAMS(String, "pos_sta_code", ZH_WORDS_GETTER("es.field.pos_sta_code"), "zz", false);
		API_DEF_ADD_QUERY_PARAMS(String, "pos_sta_name", ZH_WORDS_GETTER("es.field.pos_sta_name"), ZH_WORDS_GETTER("es.default-name"), false);
	}
	ENDPOINT(API_M_GET,"/es/query",queryEs, QUERIES(QueryParams, queryParams),API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_QUERY_PARAM(esQuery, EsQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryEs(esQuery));
	}
	//录入在职状态
	ENDPOINT_INFO(addEs)
	{
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("es.add.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_POST, "/es/add", addEs,BODY_DTO(EsAddDTO::Wrapper,dto), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_RESP_VO(execAddEs(dto,authObject->getPayload()));
	}
	//修改在职状态
	ENDPOINT_INFO(modifyEs)
	{
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("es.modify.summary"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_PUT, "/es/modify", modifyEs,BODY_DTO(EsDTO::Wrapper,dto), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_RESP_VO(execModifyEs(dto,authObject->getPayload()));
	}
private:
	StringJsonVO::Wrapper execModifyEs(const EsDTO::Wrapper& dto,const PayloadDTO& payload);
	StringJsonVO::Wrapper execAddEs(const EsAddDTO::Wrapper& dto,const PayloadDTO& payload);
	EsPageJsonVO::Wrapper execQueryEs(const EsQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section