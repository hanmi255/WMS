#pragma once
#ifndef _STUCODE_QUERY_
#define _STUCODE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class StuCodeQuery : public PageQuery
{
	DTO_INIT(StuCodeQuery, PageQuery);

	DTO_FIELD(String, code);
	DTO_FIELD_INFO(code)
	{
		info->description = "academic code";
	}

	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name)
	{
		info->description = "academic name";
	}
};




#include OATPP_CODEGEN_END(DTO)
#endif // !_STUCODE_QUERY_
