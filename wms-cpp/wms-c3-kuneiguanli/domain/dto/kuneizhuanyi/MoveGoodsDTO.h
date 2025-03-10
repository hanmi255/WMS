#pragma once

#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 基础DTO，包含所有转移任务的公共字段
*/
class MoveGoodsBaseDTO : public oatpp::DTO {
    DTO_INIT(MoveGoodsBaseDTO, DTO);
    // 转移任务ID
    DTO_FIELD(String, id);
    DTO_FIELD_INFO(id) {
        info->description = ZH_WORDS_GETTER("move-goods.field.id");
    }
    // 移动数量
    DTO_FIELD(String, moveNum);
    DTO_FIELD_INFO(moveNum) {
        info->description = ZH_WORDS_GETTER("move-goods.field.move-num");
    }
    // 到托盘
    DTO_FIELD(String, tinId);
    DTO_FIELD_INFO(tinId) {
        info->description = ZH_WORDS_GETTER("move-goods.field.tin-id");
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
* 获取转移任务详细信息的DTO
* 包含所有获取转移任务详细信息所需的字段
*/
class MoveGoodsDetailedDTO : public oatpp::DTO {
    DTO_INIT(MoveGoodsDetailedDTO, DTO);
    // 商品编码
    DTO_FIELD(String, goodsID);
    DTO_FIELD_INFO(goodsID) {
        info->description = ZH_WORDS_GETTER("move-goods.field.goods-id");
    }
    // 商品名称
    DTO_FIELD(String, goodsName);
    DTO_FIELD_INFO(goodsName) {
        info->description = ZH_WORDS_GETTER("move-goods.field.goods-name");
    }
    // 现有数量
    DTO_FIELD(String, nowNum);
    DTO_FIELD_INFO(nowNum) {
        info->description = ZH_WORDS_GETTER("move-goods.field.now-num");
    }
    // 移动数量
    DTO_FIELD(String, moveNum);
    DTO_FIELD_INFO(moveNum) {
        info->description = ZH_WORDS_GETTER("move-goods.field.move-num");
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
    // 单位
    DTO_FIELD(String, goodsUnit);
    DTO_FIELD_INFO(goodsUnit) {
        info->description = ZH_WORDS_GETTER("move-goods.field.goods-unit");
    }
    // 货主编码
    DTO_FIELD(String, cusCode);
    DTO_FIELD_INFO(cusCode) {
        info->description = ZH_WORDS_GETTER("move-goods.field.cus-code");
    }
    // 货主名称
    DTO_FIELD(String, cusName);
    DTO_FIELD_INFO(cusName) {
        info->description = ZH_WORDS_GETTER("move-goods.field.cus-name");
    }
    // 到货主编码
    DTO_FIELD(String, toCusCode);
    DTO_FIELD_INFO(toCusCode) {
        info->description = ZH_WORDS_GETTER("move-goods.field.to-cus-code");
    }
    // 到货主名称
    DTO_FIELD(String, toCusName);
    DTO_FIELD_INFO(toCusName) {
        info->description = ZH_WORDS_GETTER("move-goods.field.to-cus-name");
    }
    // 源托盘
    DTO_FIELD(String, tinFrom);
    DTO_FIELD_INFO(tinFrom) {
        info->description = ZH_WORDS_GETTER("move-goods.field.tin-from");
    }
    // 到托盘
    DTO_FIELD(String, tinTo);
    DTO_FIELD_INFO(tinTo) {
        info->description = ZH_WORDS_GETTER("move-goods.field.tin-to");
    }
    // 源储位
    DTO_FIELD(String, binFrom);
    DTO_FIELD_INFO(binFrom) {
        info->description = ZH_WORDS_GETTER("move-goods.field.bin-from");
    }
    // 到储位
    DTO_FIELD(String, binTo);
    DTO_FIELD_INFO(binTo) {
        info->description = ZH_WORDS_GETTER("move-goods.field.bin-to");
    }
    // 状态
    DTO_FIELD(String, moveStatus);
    DTO_FIELD_INFO(moveStatus) {
        info->description = ZH_WORDS_GETTER("move-goods.field.move-sta");
    }
};

/**
* 导出转移任务的DTO
* 包含导出转移任务生成的excel表格的地址
*/
class MoveGoodsDownLoadDTO : public oatpp::DTO {
    DTO_INIT(MoveGoodsDownLoadDTO, oatpp::DTO);
    // 返回导出转移任务文件地址
    DTO_FIELD(String, downLoadMoveGoods);
    DTO_FIELD_INFO(downLoadMoveGoods) {
        info->description = ZH_WORDS_GETTER("move-goods.field.down-load-move-goods");
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
