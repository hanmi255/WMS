#pragma once
#ifndef _BINDTO_
#define _BINDTO_
#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class BinPageDTO : public oatpp::DTO {
	DTO_INIT(BinPageDTO, DTO);

	DTO_FIELD(String, bin_store);
	DTO_FIELD_INFO(bin_store) {
		info->description = ZH_WORDS_GETTER("bin.bin_store");
	}

	DTO_FIELD(String, suo_shu_ke_hu);
	DTO_FIELD_INFO(suo_shu_ke_hu) {
		info->description = ZH_WORDS_GETTER("bin.suo_shu_ke_hu");
	}

	DTO_FIELD(String, chu_wei_lei_xing);
	DTO_FIELD_INFO(chu_wei_lei_xing) {
		info->description = ZH_WORDS_GETTER("bin.chu_wei_lei_xing");
	}

	DTO_FIELD(String, chu_wei);
	DTO_FIELD_INFO(chu_wei) {
		info->description = ZH_WORDS_GETTER("bin.chu_wei");
	}

	DTO_FIELD(String, shang_jia_ci_xu);
	DTO_FIELD_INFO(shang_jia_ci_xu) {
		info->description = ZH_WORDS_GETTER("bin.shang_jia_ci_xu");
	}

	DTO_FIELD(String, gao_du);
	DTO_FIELD_INFO(gao_du) {
		info->description = ZH_WORDS_GETTER("bin.gao_du");
	}
};

class BinDTO : public BinPageDTO {
	DTO_INIT(BinDTO, BinPageDTO);

	DTO_FIELD(String, chang_du);
	DTO_FIELD_INFO(chang_du) {
		info->description = ZH_WORDS_GETTER("bin.chang_du");
	}

	DTO_FIELD(String, kuan_du);
	DTO_FIELD_INFO(kuan_du) {
		info->description = ZH_WORDS_GETTER("bin.kuan_du");
	}

	DTO_FIELD(String, zui_da_ti_ji);
	DTO_FIELD_INFO(zui_da_ti_ji) {
		info->description = ZH_WORDS_GETTER("bin.zui_da_ti_ji");
	}

	DTO_FIELD(String, zui_da_tuo_pan);
	DTO_FIELD_INFO(zui_da_tuo_pan) {
		info->description = ZH_WORDS_GETTER("bin.zui_da_tuo_pan");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_BINDTO_
