#pragma once
#ifndef _HUO_QU_KE_ZHUAN_YI_LIE_BIAO_DTO_
#define _HUO_QU_KE_ZHUAN_YI_LIE_BIAO_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��������ת���б����ݶ���
 */
class HuoQuKeZhuanYiLieBiaoDTO : public oatpp::DTO
{
	DTO_INIT(HuoQuKeZhuanYiLieBiaoDTO, DTO);
	//����
	API_DTO_FIELD_DEFAULT(String, op, ZH_WORDS_GETTER("tuopanzhuanyi.field.op"));

	// �ƶ�����
	API_DTO_FIELD_DEFAULT(String, yidongdate, ZH_WORDS_GETTER("tuopanzhuanyi.field.movedate"));

	// �������
	API_DTO_FIELD_DEFAULT(String, kuctype, ZH_WORDS_GETTER("tuopanzhuanyi.field.kuctype"));

	// ��λ
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("tuopanzhuanyi.field.id"));

	// ����
	API_DTO_FIELD_DEFAULT(String, bin_id, ZH_WORDS_GETTER("tuopanzhuanyi.field.bin_id"));

	//����
	API_DTO_FIELD_DEFAULT(String, cus_code, ZH_WORDS_GETTER("tuopanzhuanyi.field.cus_code"));

	//��������
	API_DTO_FIELD_DEFAULT(String, zhong_wen_qch, ZH_WORDS_GETTER("tuopanzhuanyi.field.zhong_wen_qch"));

	//��Ʒ����
	API_DTO_FIELD_DEFAULT(String, goods_id, ZH_WORDS_GETTER("tuopanzhuanyi.field.goods_id"));

	//��Ʒ����
	API_DTO_FIELD_DEFAULT(String, goods_qua, ZH_WORDS_GETTER("tuopanzhuanyi.field.goods_qua"));

	//��Ʒ����
	API_DTO_FIELD_DEFAULT(String, shp_ming_cheng, ZH_WORDS_GETTER("tuopanzhuanyi.field.shp_ming_cheng"));

	//��������
	API_DTO_FIELD_DEFAULT(String, goods_pro_date, ZH_WORDS_GETTER("tuopanzhuanyi.field.goods_pro_date"));

	//������
	API_DTO_FIELD_DEFAULT(String, bzhi_qi, ZH_WORDS_GETTER("tuopanzhuanyi.field.bzhi_qi"));

	//��λ
	API_DTO_FIELD_DEFAULT(String, goods_unit, ZH_WORDS_GETTER("tuopanzhuanyi.field.goods_unit"));

	//״̬
	API_DTO_FIELD_DEFAULT(String, stt_sta, ZH_WORDS_GETTER("tuopanzhuanyi.field.stt_sta"));

};


/**
 * ��������ת�Ʒ�ҳ���ݶ���
 */
class HuoQuKeZhuanYiLieBiaoListPageDTO : public PageDTO<HuoQuKeZhuanYiLieBiaoDTO::Wrapper>
{
	DTO_INIT(HuoQuKeZhuanYiLieBiaoListPageDTO, PageDTO<HuoQuKeZhuanYiLieBiaoDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_