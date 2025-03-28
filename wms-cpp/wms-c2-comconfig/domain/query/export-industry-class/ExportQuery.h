#pragma once
#ifndef _EXPORT_QUERY_
#define _EXPORT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 导入和导出公司信息分页查询对象
 */
class ExportAddQuery : public PageQuery
{
	DTO_INIT(ExportAddQuery, PageQuery);
	// ID
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("chengfeng.id");
	}
	// 行业分类代码
	DTO_FIELD(String, classfl_code);
	DTO_FIELD_INFO(classfl_code) {
		info->description = ZH_WORDS_GETTER("chengfeng.code");
	}
	// 行业分类名称
	DTO_FIELD(String, classfl_name);
	DTO_FIELD_INFO(classfl_name) {
		info->description = ZH_WORDS_GETTER("chengfeng.name");
	}
	// 停用
	DTO_FIELD(String, classfl_del);
	DTO_FIELD_INFO(classfl_del) {
		info->description = ZH_WORDS_GETTER("chengfeng.del");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPORT_QUERY_

