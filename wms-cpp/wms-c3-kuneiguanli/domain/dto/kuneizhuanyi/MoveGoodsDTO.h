#pragma once

#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����DTO����������ת������Ĺ����ֶ�
 */
class MoveGoodsBaseDTO : public oatpp::DTO {
    DTO_INIT(MoveGoodsBaseDTO, DTO);
    // ת������ID
    DTO_FIELD(String, moveId);
    DTO_FIELD_INFO(moveId) {
        info->description = ZH_WORDS_GETTER("move-goods.field.id");
    }
    // �ƶ�����
    DTO_FIELD(Int32, moveNum);
    DTO_FIELD_INFO(moveNum) {
        info->description = ZH_WORDS_GETTER("move-goods.field.move-num");
    }
    // ������
    DTO_FIELD(String, tinTo);
    DTO_FIELD_INFO(tinTo) {
        info->description = ZH_WORDS_GETTER("move-goods.field.tin-to");
    }
    // ����λ
    DTO_FIELD(String, binTo);
    DTO_FIELD_INFO(binTo) {
        info->description = ZH_WORDS_GETTER("move-goods.field.bin-to");
    }
};

/**
 * �޸�ת�������DTO
 * ���������޸�ת������������ֶ�
 */
class MoveGoodsModifyDTO : public MoveGoodsBaseDTO {
    DTO_INIT(MoveGoodsModifyDTO, MoveGoodsBaseDTO);
    // ����������
    DTO_FIELD(String, toCustomerName);
    DTO_FIELD_INFO(toCustomerName) {
        info->description = ZH_WORDS_GETTER("move-goods.field.to-cus-name");
    }
    // ��������
    DTO_FIELD(String, produceDate);
    DTO_FIELD_INFO(produceDate) {
        info->description = ZH_WORDS_GETTER("move-goods.field.produce-date");
    }
    // ����������
    DTO_FIELD(String, toProduceDate);
    DTO_FIELD_INFO(toProduceDate) {
        info->description = ZH_WORDS_GETTER("move-goods.field.to-produce-date");
    }
    // ״̬
    DTO_FIELD(String, moveStatus);
    DTO_FIELD_INFO(moveStatus) {
        info->description = ZH_WORDS_GETTER("move-goods.field.move-sta");
    }
};

/**
 * ����ת�������DTO
 */
class MoveGoodsBatchDTO : public oatpp::DTO {
    DTO_INIT(MoveGoodsBatchDTO, DTO);

    DTO_FIELD(Vector<Object<MoveGoodsBaseDTO>>, items);
    DTO_FIELD_INFO(items) {
        info->description = ZH_WORDS_GETTER("move-goods.field.items");
    }
};


/**
 * �������
 * ��������ת���������Ϣ
 */
class MoveGoodsDTO : public MoveGoodsModifyDTO {
    DTO_INIT(MoveGoodsDTO, MoveGoodsModifyDTO);
};

/**
 * ��ҳ��ȡת���������
 */
class MoveGoodsPageDTO : public PageDTO<MoveGoodsDTO::Wrapper> {
    DTO_INIT(MoveGoodsPageDTO, PageDTO<MoveGoodsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
