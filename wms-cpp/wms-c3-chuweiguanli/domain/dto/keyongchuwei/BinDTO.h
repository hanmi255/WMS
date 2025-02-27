#pragma once
#ifndef _BINDTO_
#define _BINDTO_
#include "domain/GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class BinBaseDTO : public oatpp::DTO
{
	DTO_INIT(BinBaseDTO, DTO);

	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("bin.id");
	}

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

	DTO_FIELD(String, zui_da_ti_ji);
	DTO_FIELD_INFO(zui_da_ti_ji) {
		info->description = ZH_WORDS_GETTER("bin.zui_da_ti_ji");
	}

	DTO_FIELD(String, shang_jia_ci_xu);
	DTO_FIELD_INFO(shang_jia_ci_xu) {
		info->description = ZH_WORDS_GETTER("bin.shang_jia_ci_xu");
	}

	DTO_FIELD(String, chang);
	DTO_FIELD_INFO(chang) {
		info->description = ZH_WORDS_GETTER("bin.chang");
	}

	DTO_FIELD(String, kuan);
	DTO_FIELD_INFO(kuan) {
		info->description = ZH_WORDS_GETTER("bin.kuan");
	}

	DTO_FIELD(String, gao);
	DTO_FIELD_INFO(gao) {
		info->description = ZH_WORDS_GETTER("bin.gao");
	}

	DTO_FIELD(String, zui_da_tuo_pan);
	DTO_FIELD_INFO(zui_da_tuo_pan) {
		info->description = ZH_WORDS_GETTER("bin.zui_da_tuo_pan");
	}
};

class BinPageDTO : public PageDTO<BinBaseDTO::Wrapper> {
	DTO_INIT(BinPageDTO, PageDTO<BinBaseDTO::Wrapper>);
};

class BinDTO : public BinBaseDTO {
	DTO_INIT(BinDTO, BinBaseDTO);
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_BINDTO_
