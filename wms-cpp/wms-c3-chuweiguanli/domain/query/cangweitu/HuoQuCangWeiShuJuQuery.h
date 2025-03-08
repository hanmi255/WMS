#pragma once
#ifndef _HUO_QU_CANG_WEI_SHU_JU_QUERY_
#define _HUO_QU_CANG_WEI_SHU_JU_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 仓位数据查询对象
 */
class HuoQuCangWeiShuJuQuery : public PageQuery
{
	DTO_INIT(HuoQuCangWeiShuJuQuery, PageQuery);
	// 仓库
	DTO_FIELD(String, bin_store);
	DTO_FIELD_INFO(bin_store) {
		info->description = ZH_WORDS_GETTER("store.field.bin_store");
	}

	//储位
	API_DTO_FIELD_DEFAULT(String, bin_id, ZH_WORDS_GETTER("store.field.bin_id"));
	//层数
	API_DTO_FIELD_DEFAULT(String, znode, ZH_WORDS_GETTER("store.field.znode"));
	//行数
	API_DTO_FIELD_DEFAULT(String, xnode, ZH_WORDS_GETTER("store.field.xnode"));
	//列数
	API_DTO_FIELD_DEFAULT(String, ynode, ZH_WORDS_GETTER("store.field.ynode"));
	
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_HUO_QU_CANG_WEI_SHU_JU_QUERY_