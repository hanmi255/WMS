#pragma once
#ifndef _GETENTERPRISELEVELNAME_QUERY_
#define _GETENTERPRISELEVELNAME_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取企业等级名称列表初始化
 */
class getLevelNameQuery : public PageQuery
{
	DTO_INIT(getLevelNameQuery, PageQuery);
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("enterprise.level.name");
	}
	// 编码
	DTO_FIELD(String, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("enterprise.level.code");
	}
	// id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("enterprise.level.id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GETENTERPRISELEVELNAME_QUERY_