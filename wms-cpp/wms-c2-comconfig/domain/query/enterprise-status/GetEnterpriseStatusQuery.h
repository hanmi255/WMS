#pragma once
#ifndef _GETENTERPRISELEVESTATUS_QUERY_
#define _GETENTERPRISELEVESTATUS_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取企业等级名称列表初始化
 */
class GetEnterpriseStatusQuery : public PageQuery
{
	DTO_INIT(GetEnterpriseStatusQuery, PageQuery);
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("enterprise.file.statusname");
	}
	// 编码
	DTO_FIELD(String, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("enterprise.file.statusid");
	}
	// id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("enterprise.file.only");
	}
	// 是否停用
	DTO_FIELD(String, ban);
	DTO_FIELD_INFO(ban) {
		info->description = ZH_WORDS_GETTER("enterprise.file.stop");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GETENTERPRISELEVESTATUS_QUERY_