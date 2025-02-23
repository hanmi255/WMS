#pragma once
#ifndef _BIN_QUERY_H_
#define _BIN_QUERY_H_
#include "domain/GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class BinQuery : public PageQuery
{
	DTO_INIT(BinQuery, PageQuery);

	DTO_FIELD(String, bin_store);
	DTO_FIELD_INFO(bin_store) {
		info->description = ZH_WORDS_GETTER("bin.bin_store");
	}

	DTO_FIELD(String, ku_wei_lei_xing);
	DTO_FIELD_INFO(ku_wei_lei_xing) {
		info->description = ZH_WORDS_GETTER("bin.ku_wei_lei_xing");
	}

	DTO_FIELD(String, ku_wei_bian_ma);
	DTO_FIELD_INFO(ku_wei_bian_ma) {
		info->description = ZH_WORDS_GETTER("bin.ku_wei_bian_ma");
	}

	DTO_FIELD(String, ku_wei_tiao_ma);
	DTO_FIELD_INFO(ku_wei_tiao_ma) {
		info->description = ZH_WORDS_GETTER("bin.ku_wei_tiao_ma");
	}

	DTO_FIELD(String, xnode);
	DTO_FIELD_INFO(xnode) {
		info->description = ZH_WORDS_GETTER("bin.xnode");
	}

	DTO_FIELD(String, ynode);
	DTO_FIELD_INFO(ynode) {
		info->description = ZH_WORDS_GETTER("bin.ynode");
	}

	DTO_FIELD(String, znode);
	DTO_FIELD_INFO(znode) {
		info->description = ZH_WORDS_GETTER("bin.znode");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_BIN_QUERY_H_