#pragma once

#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 基础DTO，包含所有转移任务的公共字段
 */
class MoveGoodsBaseDTO : public oatpp::DTO {
    DTO_INIT(MoveGoodsBaseDTO, DTO);
    // 转移任务ID
    DTO_FIELD(String, moveId);
    DTO_FIELD_INFO(moveId) {
        info->description = ZH_WORDS_GETTER("move-goods.field.id");
    }
    // 移动数量
    DTO_FIELD(Int32, moveNum);
    DTO_FIELD_INFO(moveNum) {
        info->description = ZH_WORDS_GETTER("move-goods.field.move-num");
    }
    // 到托盘
    DTO_FIELD(String, tinTo);
    DTO_FIELD_INFO(tinTo) {
        info->description = ZH_WORDS_GETTER("move-goods.field.tin-to");
    }
    // 到储位
    DTO_FIELD(String, binTo);
    DTO_FIELD_INFO(binTo) {
        info->description = ZH_WORDS_GETTER("move-goods.field.bin-to");
    }
};

/**
 * 修改转移任务的DTO
 * 包含所有修改转移任务所需的字段
 */
class MoveGoodsModifyDTO : public MoveGoodsBaseDTO {
    DTO_INIT(MoveGoodsModifyDTO, MoveGoodsBaseDTO);
    // 到货主名称
    DTO_FIELD(String, toCustomerName);
    DTO_FIELD_INFO(toCustomerName) {
        info->description = ZH_WORDS_GETTER("move-goods.field.to-cus-name");
    }
    // 生产日期
    DTO_FIELD(String, produceDate);
    DTO_FIELD_INFO(produceDate) {
        info->description = ZH_WORDS_GETTER("move-goods.field.produce-date");
    }
    // 到生产日期
    DTO_FIELD(String, toProduceDate);
    DTO_FIELD_INFO(toProduceDate) {
        info->description = ZH_WORDS_GETTER("move-goods.field.to-produce-date");
    }
    // 状态
    DTO_FIELD(String, moveStatus);
    DTO_FIELD_INFO(moveStatus) {
        info->description = ZH_WORDS_GETTER("move-goods.field.move-sta");
    }
};

/**
 * 批量转移任务的DTO
 */
class MoveGoodsBatchDTO : public oatpp::DTO {
    DTO_INIT(MoveGoodsBatchDTO, DTO);

    DTO_FIELD(Vector<Object<MoveGoodsBaseDTO>>, items);
    DTO_FIELD_INFO(items) {
        info->description = ZH_WORDS_GETTER("move-goods.field.items");
    }
};


/**
 * 传输对象
 * 包含单个转移任务的信息
 */
class MoveGoodsDTO : public MoveGoodsModifyDTO {
    DTO_INIT(MoveGoodsDTO, MoveGoodsModifyDTO);
};

/**
 * 分页获取转移任务对象
 */
class MoveGoodsPageDTO : public PageDTO<MoveGoodsDTO::Wrapper> {
    DTO_INIT(MoveGoodsPageDTO, PageDTO<MoveGoodsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
