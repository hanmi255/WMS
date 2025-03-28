#pragma once

#ifndef _BUSSTYPE_CONTROLLER_
#define _BUSSTYPE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "../../domain/vo/busstype/BussTypeVO.h"
#include "../../domain/dto/busstype/BussTypeDTO.h"
#include "../../domain/query/busstype/BussTypeQuery.h"


#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 
 */
class BussTypeController : public oatpp::web::server::api::ApiController
{

	API_ACCESS_DECLARE(BussTypeController);
public:
	//
	ENDPOINT_INFO(queryBussType) {
		// 
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("buss-type.get.query"));
		// 
		API_DEF_ADD_AUTH();
		API_DEF_ADD_RSP_JSON_WRAPPER(BussTypePageJsonVO);
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "buss_type_code", ZH_WORDS_GETTER("buss-type.field.buss-type-code"), "01", false);
		API_DEF_ADD_QUERY_PARAMS(String, "buss_type_name", ZH_WORDS_GETTER("buss-type.field.buss-type-name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "buss_type_text", ZH_WORDS_GETTER("buss-type.field.buss-type-text"), "", false);
	}	
	//
	ENDPOINT(API_M_GET, "/repository/busstype-query", queryBussType, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 
		API_HANDLER_QUERY_PARAM(userQuery, BussTypeQuery, queryParams);
		// 
		API_HANDLER_RESP_VO(execQueryBussType(userQuery, authObject->getPayload()));
	}

	
	ENDPOINT_INFO(addBussType) {

		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("buss-type.get.add"));
		API_DEF_ADD_AUTH();

		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	
	ENDPOINT(API_M_POST, "/repository/busstype-add", addBussType, BODY_DTO(BussTypeAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) 
	{

		API_HANDLER_RESP_VO(execAddBussType(dto));
	}
	

	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("buss-type.get.modify"), modifyBussType, Uint64JsonVO::Wrapper);
	//
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/repository/busstype-modify", modifyBussType, BODY_DTO(BussTypeAddDTO::Wrapper, dto), execModifyBussType(dto));

private:

	BussTypePageJsonVO::Wrapper execQueryBussType(const BussTypeQuery::Wrapper& query, const PayloadDTO& payload);
	Uint64JsonVO::Wrapper execAddBussType(const BussTypeAddDTO::Wrapper& dto);
	Uint64JsonVO::Wrapper execModifyBussType(const BussTypeAddDTO::Wrapper& dto);
};


#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_BUSSTYPE_CONTROLLER_