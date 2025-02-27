#pragma once
#ifndef _BIN_QUERY_H_
#define _BIN_QUERY_H_
#include "domain/GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class BinExcelQuery : public oatpp::DTO
{
	DTO_INIT(BinExcelQuery, DTO);
	
	DTO_FIELD(String, file_path);
	DTO_FIELD_INFO(file_path) {
		info->description = ZH_WORDS_GETTER("bin.file_path");
	}

	DTO_FIELD(String, ids);
	DTO_FIELD_INFO(ids) {
		info->description = ZH_WORDS_GETTER("bin.ids");
	}
};

class BinPageQuery : public PageQuery
{
	DTO_INIT(BinPageQuery, PageQuery);

	DTO_FIELD(String, bin_store);
	DTO_FIELD_INFO(bin_store) {
		info->description = ZH_WORDS_GETTER("bin.bin_store");
	}

	DTO_FIELD(String, ku_wei_shu_xing);
	DTO_FIELD_INFO(ku_wei_shu_xing) {
		info->description = ZH_WORDS_GETTER("bin.ku_wei_shu_xing");
	}

	DTO_FIELD(String, ku_wei_bian_ma);
	DTO_FIELD_INFO(ku_wei_bian_ma) {
		info->description = ZH_WORDS_GETTER("bin.ku_wei_bian_ma");
	}

	DTO_FIELD(String, suo_shu_ke_hu);
	DTO_FIELD_INFO(suo_shu_ke_hu) {
		info->description = ZH_WORDS_GETTER("bin.suo_shu_ke_hu");
	}

	DTO_FIELD(String, shang_jia_ci_xu);
	DTO_FIELD_INFO(shang_jia_ci_xu) {
		info->description = ZH_WORDS_GETTER("bin.shang_jia_ci_xu");
	}

	DTO_FIELD(String, gao);
	DTO_FIELD_INFO(gao) {
		info->description = ZH_WORDS_GETTER("bin.gao");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_BIN_QUERY_H_