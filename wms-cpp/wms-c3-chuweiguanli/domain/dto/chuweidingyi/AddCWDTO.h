#pragma once
#include "domain/GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class AddCWDTO : public oatpp::DTO {
	DTO_INIT(AddCWDTO, DTO);


	DTO_FIELD(String, bin_store);
	DTO_FIELD_INFO(bin_store) {
		info->description = ZH_WORDS_GETTER("Cangku.info.store_name");
	}

	DTO_FIELD(String, suo_shu_ke_hu);
	DTO_FIELD_INFO(suo_shu_ke_hu) {
		info->description = ZH_WORDS_GETTER("chuwei.add.kehu");
	}

	DTO_FIELD(String, ku_wei_bian_ma);
	DTO_FIELD_INFO(ku_wei_bian_ma) {
		info->description = ZH_WORDS_GETTER("chuwei.add.kuweibianma");
	}

	DTO_FIELD(String, ku_wei_tiao_ma);
	DTO_FIELD_INFO(ku_wei_tiao_ma) {
		info->description = ZH_WORDS_GETTER("chuwei.add.kuweitiaoma");
	}

	DTO_FIELD(String, ku_wei_lei_xing);
	DTO_FIELD_INFO(ku_wei_lei_xing) {
		info->description = ZH_WORDS_GETTER("chuwei.add.kuweileixing");
	}

	DTO_FIELD(String, ku_wei_shu_xing);
	DTO_FIELD_INFO(ku_wei_shu_xing) {
		info->description = ZH_WORDS_GETTER("chuwei.add.kuweishuxing");
	}

	DTO_FIELD(String, CHP_SHU_XING);
	DTO_FIELD_INFO(CHP_SHU_XING) {
		info->description = ZH_WORDS_GETTER("chuwei.add.chanqinshuxing");
	}


	DTO_FIELD(String, shang_jia_ci_xu);
	DTO_FIELD_INFO(shang_jia_ci_xu) {
		info->description = ZH_WORDS_GETTER("chuwei.add.shangjiacixv");
	}

	DTO_FIELD(String, qu_huo_ci_xu);
	DTO_FIELD_INFO(qu_huo_ci_xu) {
		info->description = ZH_WORDS_GETTER("chuwei.add.quhuocixv");
	}


	DTO_FIELD(String, LORA_bqid);
	DTO_FIELD_INFO(LORA_bqid) {
		info->description = ZH_WORDS_GETTER("chuwei.add.diancibiaoqianID");
	}

	// 坐标字段命名优化
	DTO_FIELD(String, xnode);
	DTO_FIELD_INFO(xnode) {
		info->description = ZH_WORDS_GETTER("chuwei.add.x_node");
	}

	DTO_FIELD(String, ynode);
	DTO_FIELD_INFO(ynode) {
		info->description = ZH_WORDS_GETTER("chuwei.add.y_node");
	}

	DTO_FIELD(String, znode);
	DTO_FIELD_INFO(znode) {
		info->description = ZH_WORDS_GETTER("chuwei.add.z_node");
	}

	DTO_FIELD(String, ming_xi);
	DTO_FIELD_INFO(ming_xi) {
		info->description = ZH_WORDS_GETTER("chuwei.add.beizhu");
	}

	DTO_FIELD(String, ming_xi1);
	DTO_FIELD_INFO(ming_xi1) {
		info->description = ZH_WORDS_GETTER("chuwei.add.beizhu1");
	}

	DTO_FIELD(String, ming_xi2);
	DTO_FIELD_INFO(ming_xi2) {
		info->description = ZH_WORDS_GETTER("chuwei.add.beizhu2");
	}

	DTO_FIELD(String, ming_xi3);
	DTO_FIELD_INFO(ming_xi3) {
		info->description = ZH_WORDS_GETTER("chuwei.add.dongxian");
	}
};

#include OATPP_CODEGEN_END(DTO)