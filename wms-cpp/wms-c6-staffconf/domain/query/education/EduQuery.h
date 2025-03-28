#pragma once

#ifndef _EDU_QUERY_
#define _EDU_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class EduQuery : public PageQuery
{
	DTO_INIT(EduQuery, PageQuery);
	 //字段id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("education.filed.id");
	}
	// 学历代码
	DTO_FIELD(String, educode);
	DTO_FIELD_INFO(educode) {
		info->description = ZH_WORDS_GETTER("education.filed.educode");
	}
	// 学历名称
	DTO_FIELD(String, eduname);
	DTO_FIELD_INFO(eduname) {
		info->description = ZH_WORDS_GETTER("education.filed.eduname");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EDU_QUERY_