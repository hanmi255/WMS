#pragma once

#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ����DTO����������ת������Ĺ����ֶ�
*/
class MoveGoodsBaseDTO : public oatpp::DTO {
    DTO_INIT(MoveGoodsBaseDTO, DTO);
    // ת������Id
    DTO_FIELD(String, id);
    DTO_FIELD_INFO(id) {
        info->description = ZH_WORDS_GETTER("movegoods.field.id");
    }
    // �ƶ�����
<<<<<<< HEAD
    DTO_FIELD(String, base_goodscount);
    DTO_FIELD_INFO(base_goodscount) {
        info->description = ZH_WORDS_GETTER("movegoods.field.base_goodscount");
=======
    DTO_FIELD(String, moveNum);
    DTO_FIELD_INFO(moveNum) {
        info->description = ZH_WORDS_GETTER("move-goods.field.move-num");
>>>>>>> 05f7ec7fb45d4bc1f52eea780440c95f076c61f0
    }
    // ������
    DTO_FIELD(String, tin_id);
    DTO_FIELD_INFO(tin_id) {
        info->description = ZH_WORDS_GETTER("movegoods.field.tin_id");
    }
    // ����λ
    DTO_FIELD(String, bin_to);
    DTO_FIELD_INFO(bin_to) {
        info->description = ZH_WORDS_GETTER("movegoods.field.bin_to");
    }
};

/**
* �޸�ת�������DTO
* ���������޸�ת������������ֶ�
*/
class MoveGoodsModifyDTO : public MoveGoodsBaseDTO {
    DTO_INIT(MoveGoodsModifyDTO, MoveGoodsBaseDTO);
    // ת�ƿͻ�
    DTO_FIELD(String, to_cus_code);
    DTO_FIELD_INFO(to_cus_code) {
        info->description = ZH_WORDS_GETTER("movegoods.field.to_cus_code");
    }
    // ת�ƿͻ�����
    DTO_FIELD(String, to_cus_name);
    DTO_FIELD_INFO(to_cus_name) {
        info->description = ZH_WORDS_GETTER("movegoods.field.to_cus_name");
    }
    // ��������
    DTO_FIELD(String, goods_pro_data);
    DTO_FIELD_INFO(goods_pro_data) {
        info->description = ZH_WORDS_GETTER("movegoods.field.goods_pro_data");
    }
    // ����������
    DTO_FIELD(String, to_goods_pro_data);
    DTO_FIELD_INFO(to_goods_pro_data) {
        info->description = ZH_WORDS_GETTER("movegoods.field.to_goods_pro_data");
    }
    // ״̬
    DTO_FIELD(String, move_sta);
    DTO_FIELD_INFO(move_sta) {
        info->description = ZH_WORDS_GETTER("movegoods.field.move_sta");
    }
};

/**
* ��ȡת��������ϸ��Ϣ��DTO
* �������л�ȡת��������ϸ��Ϣ������ֶ�
*/
class MoveGoodsDetailedDTO : public oatpp::DTO {
    DTO_INIT(MoveGoodsDetailedDTO, DTO);
    // ��Ʒ����
    DTO_FIELD(String, goods_id);
    DTO_FIELD_INFO(goods_id) {
        info->description = ZH_WORDS_GETTER("movegoods.field.goods_id");
    }
    // ��Ʒ����
    DTO_FIELD(String, goods_name);
    DTO_FIELD_INFO(goods_name) {
        info->description = ZH_WORDS_GETTER("movegoods.field.goods_name");
    }
    // ��������
<<<<<<< HEAD
    DTO_FIELD(String, goods_qua);
    DTO_FIELD_INFO(goods_qua) {
        info->description = ZH_WORDS_GETTER("movegoods.field.goods_qua");
    }
    // �ƶ�����
    DTO_FIELD(String, base_goodscount);
    DTO_FIELD_INFO(base_goodscount) {
        info->description = ZH_WORDS_GETTER("movegoods.field.base_goodscount");
=======
    DTO_FIELD(String, nowNum);
    DTO_FIELD_INFO(nowNum) {
        info->description = ZH_WORDS_GETTER("move-goods.field.now-num");
    }
    // �ƶ�����
    DTO_FIELD(String, moveNum);
    DTO_FIELD_INFO(moveNum) {
        info->description = ZH_WORDS_GETTER("move-goods.field.move-num");
>>>>>>> 05f7ec7fb45d4bc1f52eea780440c95f076c61f0
    }
    // ��������
    DTO_FIELD(String, goods_pro_data);
    DTO_FIELD_INFO(goods_pro_data) {
        info->description = ZH_WORDS_GETTER("movegoods.field.goods_pro_data");
    }
    // ����������
    DTO_FIELD(String, to_goods_pro_data);
    DTO_FIELD_INFO(to_goods_pro_data) {
        info->description = ZH_WORDS_GETTER("movegoods.field.to_goods_pro_data");
    }
    // ��λ
    DTO_FIELD(String, goods_unit);
    DTO_FIELD_INFO(goods_unit) {
        info->description = ZH_WORDS_GETTER("movegoods.field.goods_unit");
    }
    // �ͻ�����
    DTO_FIELD(String, cus_code);
    DTO_FIELD_INFO(cus_code) {
        info->description = ZH_WORDS_GETTER("movegoods.field.cus_code");
    }
    // �ͻ�����
    DTO_FIELD(String, cus_name);
    DTO_FIELD_INFO(cus_name) {
        info->description = ZH_WORDS_GETTER("movegoods.field.cus_name");
    }
    // ת�ƿͻ�
    DTO_FIELD(String, to_cus_code);
    DTO_FIELD_INFO(to_cus_code) {
        info->description = ZH_WORDS_GETTER("movegoods.field.to_cus_code");
    }
    // ת�ƿͻ�����
    DTO_FIELD(String, to_cus_name);
    DTO_FIELD_INFO(to_cus_name) {
        info->description = ZH_WORDS_GETTER("movegoods.field.to_cus_name");
    }
    // Դ����
    DTO_FIELD(String, tin_from);
    DTO_FIELD_INFO(tin_from) {
        info->description = ZH_WORDS_GETTER("movegoods.field.tin_from");
    }
    // ������
    DTO_FIELD(String, tin_id);
    DTO_FIELD_INFO(tin_id) {
        info->description = ZH_WORDS_GETTER("movegoods.field.tin_id");
    }
    // Դ��λ
    DTO_FIELD(String, bin_from);
    DTO_FIELD_INFO(bin_from) {
        info->description = ZH_WORDS_GETTER("movegoods.field.bin_from");
    }
    // ����λ
    DTO_FIELD(String, bin_to);
    DTO_FIELD_INFO(bin_to) {
        info->description = ZH_WORDS_GETTER("movegoods.field.bin_to");
    }
    // ״̬
    DTO_FIELD(String, move_sta);
    DTO_FIELD_INFO(move_sta) {
        info->description = ZH_WORDS_GETTER("movegoods.field.move_sta");
    }
};

/**
* ����ת�������DTO
* ��������ת���������ɵ�excel���ĵ�ַ
*/
class MoveGoodsDownLoadDTO : public oatpp::DTO {
    DTO_INIT(MoveGoodsDownLoadDTO, oatpp::DTO);
<<<<<<< HEAD
	// ���ص���ת�������ļ���ַ
	DTO_FIELD(String, download_movegoods);
	DTO_FIELD_INFO(download_movegoods) {
		info->description = ZH_WORDS_GETTER("movegoods.field.download_movegoods");
	}
=======
    // ���ص���ת�������ļ���ַ
    DTO_FIELD(String, downLoadMoveGoods);
    DTO_FIELD_INFO(downLoadMoveGoods) {
        info->description = ZH_WORDS_GETTER("move-goods.field.down-load-move-goods");
    }
>>>>>>> 05f7ec7fb45d4bc1f52eea780440c95f076c61f0
};

/**
<<<<<<< HEAD
 * ����ת�������DTO
 */
class MoveGoodsBatchModifyDTO : public MoveGoodsBaseDTO {
    DTO_INIT(MoveGoodsBatchModifyDTO, DTO);
=======
* ����ת�������DTO
*/
class MoveGoodsBatchDTO : public oatpp::DTO {
    DTO_INIT(MoveGoodsBatchDTO, DTO);
>>>>>>> 05f7ec7fb45d4bc1f52eea780440c95f076c61f0
    DTO_FIELD(Vector<Object<MoveGoodsBaseDTO>>, items);
    DTO_FIELD_INFO(items) {
        info->description = ZH_WORDS_GETTER("movegoods.field.items");
    }
};

<<<<<<< HEAD
/**
 * ɾ��ת������֧����������DTO
 */
class BatchRemoveMoveGoodsDTO : public oatpp::DTO {
    DTO_INIT(BatchRemoveMoveGoodsDTO, DTO);
    DTO_FIELD(Vector<String>, items);
    DTO_FIELD_INFO(items) {
        info->description = ZH_WORDS_GETTER("movegoods.field.items");
    }
};

/**
 * �������
 * ��������ת���������Ϣ
 */
class MoveGoodsDTO : public MoveGoodsDetailedDTO {
    DTO_INIT(MoveGoodsDTO, MoveGoodsDetailedDTO);
    // ת������Id
    DTO_FIELD(String, id);
    DTO_FIELD_INFO(id) {
        info->description = ZH_WORDS_GETTER("movegoods.field.id");
    }
    // ����������
    DTO_FIELD(String, create_name);
    DTO_FIELD_INFO(create_name) {
        info->description = ZH_WORDS_GETTER("movegoods.field.create_name");
    }
    // ��������
    DTO_FIELD(String, create_date);
    DTO_FIELD_INFO(create_date) {
        info->description = ZH_WORDS_GETTER("movegoods.field.create_date");
    }
    // ����������
    DTO_FIELD(String, update_name);
    DTO_FIELD_INFO(update_name) {
        info->description = ZH_WORDS_GETTER("movegoods.field.update_name");
    }
    // ��������
    DTO_FIELD(String, update_date);
    DTO_FIELD_INFO(update_date) {
        info->description = ZH_WORDS_GETTER("movegoods.field.update_date");
    }
    // ִ��״̬
    DTO_FIELD(String, run_sta);
    DTO_FIELD_INFO(run_sta) {
        info->description = ZH_WORDS_GETTER("movegoods.field.run_sta");
    }
=======

/**
* �������
* ��������ת���������Ϣ
*/
class MoveGoodsDTO : public MoveGoodsModifyDTO {
    DTO_INIT(MoveGoodsDTO, MoveGoodsModifyDTO);
>>>>>>> 05f7ec7fb45d4bc1f52eea780440c95f076c61f0
};

/**
* ��ҳ��ȡת���������
*/
class MoveGoodsPageDTO : public PageDTO<MoveGoodsDTO::Wrapper> {
    DTO_INIT(MoveGoodsPageDTO, PageDTO<MoveGoodsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
