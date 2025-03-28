#pragma once
#ifndef _COMDEG_QUERY_
#define _COMDEG_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 公司等级分页查询对象
 */
class ComdegQuery : public PageQuery
{
	DTO_INIT(ComdegQuery, PageQuery);

	//企业等级名称
	API_DTO_FIELD_DEFAULT(String, degname, ZH_WORDS_GETTER("com.field.degname"));

	//企业等级代码
	API_DTO_FIELD_DEFAULT(String, degcode, ZH_WORDS_GETTER("com.field.degcode"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_COMDEG_QUERY_