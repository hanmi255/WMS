#pragma once
#ifndef _HUO_QU_KE_ZHUAN_YI_LIE_BIAO_DTO_
#define _HUO_QU_KE_ZHUAN_YI_LIE_BIAO_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 生成托盘转移列表数据对象
 */
class HuoQuKeZhuanYiLieBiaoDTO : public oatpp::DTO
{
	DTO_INIT(HuoQuKeZhuanYiLieBiaoDTO, DTO);

	//// 移动日期
	//API_DTO_FIELD_DEFAULT(String, move_date, ZH_WORDS_GETTER("tuopanzhuanyi.field.move_date"));

	// 库存类型
	API_DTO_FIELD_DEFAULT(String, kuctype, ZH_WORDS_GETTER("tuopanzhuanyi.field.kuctype"));

	// 储位
	API_DTO_FIELD_DEFAULT(String, ku_wei_bian_ma, ZH_WORDS_GETTER("tuopanzhuanyi.field.ku_wei_bian_ma"));

	// 托盘
	API_DTO_FIELD_DEFAULT(String, bin_id, ZH_WORDS_GETTER("tuopanzhuanyi.field.bin_id"));

	//货主
	API_DTO_FIELD_DEFAULT(String, cus_code, ZH_WORDS_GETTER("tuopanzhuanyi.field.cus_code"));

	//货主名称
	API_DTO_FIELD_DEFAULT(String, zhong_wen_qch, ZH_WORDS_GETTER("tuopanzhuanyi.field.zhong_wen_qch"));

	//商品编码
	API_DTO_FIELD_DEFAULT(String, goods_id, ZH_WORDS_GETTER("tuopanzhuanyi.field.goods_id"));

	//商品数量
	API_DTO_FIELD_DEFAULT(String, goods_qua, ZH_WORDS_GETTER("tuopanzhuanyi.field.goods_qua"));

	//商品名称
	API_DTO_FIELD_DEFAULT(String, shp_ming_cheng, ZH_WORDS_GETTER("tuopanzhuanyi.field.shp_ming_cheng"));

	//生产日期
	API_DTO_FIELD_DEFAULT(String, goods_pro_data, ZH_WORDS_GETTER("tuopanzhuanyi.field.goods_pro_data"));

	//保质期
	API_DTO_FIELD_DEFAULT(String, bzhi_qi, ZH_WORDS_GETTER("tuopanzhuanyi.field.bzhi_qi"));

	//单位
	API_DTO_FIELD_DEFAULT(String, goods_unit, ZH_WORDS_GETTER("tuopanzhuanyi.field.goods_unit"));

	////状态
	//API_DTO_FIELD_DEFAULT(String, stt_sta, ZH_WORDS_GETTER("tuopanzhuanyi.field.stt_sta"));

};


/**
 * 生成托盘转移分页数据对象
 */
class HuoQuKeZhuanYiLieBiaoListPageDTO : public PageDTO<HuoQuKeZhuanYiLieBiaoDTO::Wrapper>
{
	DTO_INIT(HuoQuKeZhuanYiLieBiaoListPageDTO, PageDTO<HuoQuKeZhuanYiLieBiaoDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_