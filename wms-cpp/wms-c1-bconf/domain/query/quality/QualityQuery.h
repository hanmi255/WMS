#pragma once

#ifndef _QUALITY_QUERY_
#define _QUALITY_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 品质代码分页查询对象
 */
class QualityQuery : public PageQuery
{
	DTO_INIT(QualityQuery, PageQuery);
	// 品质代码 
	API_DTO_FIELD_DEFAULT(String, qm_qa_code, ZH_WORDS_GETTER("quality.qm_qa_code"));

	// 品质代码名称
	API_DTO_FIELD_DEFAULT(String, qm_qa_name, ZH_WORDS_GETTER("quality.qm_qa_name"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_QUALITY_QUERY_