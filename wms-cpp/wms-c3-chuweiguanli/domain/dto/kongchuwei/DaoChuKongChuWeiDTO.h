#pragma once
#ifndef _DAO_CHU_KONG_CHU_WEI_DTO_
#define _DAO_CHU_KONG_CHU_WEI_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 空储位传输数据对象
 */
class DaoChuKongChuWeiDTO : public oatpp::DTO
{
	DTO_INIT(DaoChuKongChuWeiDTO, DTO);
	// 仓库
	DTO_FIELD(String, bin_store);
	DTO_FIELD_INFO(bin_store) {
		info->description = ZH_WORDS_GETTER("store.field.bin_store");
	}

	//储位属性
	API_DTO_FIELD_DEFAULT(String, ku_wei_shu_xing, ZH_WORDS_GETTER("store.field.ku_wei_shu_xing"));
	//产品属性
	API_DTO_FIELD_DEFAULT(String, CHP_SHU_XING, ZH_WORDS_GETTER("store.field.CHP_SHU_XING"));
	//储位编码
	API_DTO_FIELD_DEFAULT(String, ku_wei_bian_ma, ZH_WORDS_GETTER("store.field.ku_wei_bian_ma"));
	//所属客户
	API_DTO_FIELD_DEFAULT(String, suo_shu_ke_hu, ZH_WORDS_GETTER("store.field.suo_shu_ke_hu"));
	//最大体积
	API_DTO_FIELD_DEFAULT(String, zui_da_ti_ji, ZH_WORDS_GETTER("store.field.zui_da_ti_ji"));
	//上架次序
	API_DTO_FIELD_DEFAULT(String, shang_jia_ci_xu, ZH_WORDS_GETTER("store.field.shang_jia_ci_xu"));
	//长
	API_DTO_FIELD_DEFAULT(String, chang, ZH_WORDS_GETTER("store.field.chang"));
	//宽
	API_DTO_FIELD_DEFAULT(String, kuan, ZH_WORDS_GETTER("store.field.kuan"));
	//高
	API_DTO_FIELD_DEFAULT(String, gao, ZH_WORDS_GETTER("store.field.gao"));
	//最大托盘
	API_DTO_FIELD_DEFAULT(String, zui_da_tuo_pan, ZH_WORDS_GETTER("store.field.zui_da_tuo_pan"));
	//停用
	API_DTO_FIELD_DEFAULT(String, ting_yong, ZH_WORDS_GETTER("store.field.ting_yong"));
	//库位类型
	API_DTO_FIELD_DEFAULT(String, ku_wei_lei_xing, ZH_WORDS_GETTER("store.field.ku_wei_lei_xing"));
};

class DaoChuKongChuWeiPageDTO : public PageDTO<DaoChuKongChuWeiDTO::Wrapper>
{
	DTO_INIT(DaoChuKongChuWeiPageDTO, PageDTO<DaoChuKongChuWeiDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DAO_CHU_KONG_CHU_WEI_DTO_
