#pragma once

#ifndef _TIN_TRANSFER_DTO_
#define _TIN_TRANSFER_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * "生成托盘转移" - 列表数据对象
 */
class TinTransferListDTO : public oatpp::DTO
{
	DTO_INIT(TinTransferListDTO, DTO);

	//唯一标识
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("assignment.field.id");
	}

	// 移动日期
	DTO_FIELD(String, moveDate);
	DTO_FIELD_INFO(moveDate) {
		info->description = ZH_WORDS_GETTER("assignment.field.move-date");
	}
	// 库存类型
	DTO_FIELD(String, inventoryType);
	DTO_FIELD_INFO(inventoryType) {
		info->description = ZH_WORDS_GETTER("assignment.field.inventory-type");
	}
	// 储位
	DTO_FIELD(String, bin);
	DTO_FIELD_INFO(bin) {
		info->description = ZH_WORDS_GETTER("assignment.field.bin");
	}
	// 托盘
	DTO_FIELD(String, tin);
	DTO_FIELD_INFO(tin) {
		info->description = ZH_WORDS_GETTER("assignment.field.tin");
	}
	// 货主
	DTO_FIELD(String, cusCode);
	DTO_FIELD_INFO(cusCode) {
		info->description = ZH_WORDS_GETTER("assignment.field.cus-code");
	}
	// 货主名称
	DTO_FIELD(String, cusName);
	DTO_FIELD_INFO(cusName) {
		info->description = ZH_WORDS_GETTER("assignment.field.cus-name");
	}
	// 商品编码
	DTO_FIELD(String, goodsID);
	DTO_FIELD_INFO(goodsID) {
		info->description = ZH_WORDS_GETTER("assignment.field.goods-id");
	}

	//商品数量
	DTO_FIELD(Int64, goodsNum);
	DTO_FIELD_INFO(goodsNum) {
		info->description = ZH_WORDS_GETTER("assignment.field.goods-num");
	}

	// 商品名称
	DTO_FIELD(String, goodsName);
	DTO_FIELD_INFO(goodsName) {
		info->description = ZH_WORDS_GETTER("assignment.field.goods-name");
	}
	// 生产日期
	DTO_FIELD(String, produceDate);
	DTO_FIELD_INFO(produceDate) {
		info->description = ZH_WORDS_GETTER("assignment.field.produce-date");
	}
	
	//保质期
	DTO_FIELD(String, produceShelfLife);
	DTO_FIELD_INFO(produceShelfLife) {
		info->description = ZH_WORDS_GETTER("assignment.field.produce-shelf-life");
	}
	//单位
	DTO_FIELD(String, produceUnit);
	DTO_FIELD_INFO(produceUnit) {
		info->description = ZH_WORDS_GETTER("assignment.field.produce-unit");
	}
	//状态
	DTO_FIELD(String, moveSta);
	DTO_FIELD_INFO(moveSta) {
		info->description = ZH_WORDS_GETTER("assignment.field.move-sta");
	}
};

/**
 * "生成托盘转移" - 增加移动托盘的位置
 */
class TinTransferBaseDTO : public TinTransferListDTO
{
	DTO_INIT(TinTransferBaseDTO, TinTransferListDTO);
	// 转移托盘位置
	DTO_FIELD(String, toBin);
	DTO_FIELD_INFO(toBin) {
		info->description = ZH_WORDS_GETTER("assignment.field.bin-to");
	}
};

/**
 * "生成托盘转移" - 批量生成托盘转移任务、立即批量转移
 */
class TinTransferBatchDTO : public oatpp::DTO {
	DTO_INIT(TinTransferBatchDTO, DTO);
	DTO_FIELD(Vector<Object<TinTransferBaseDTO>>, items);
	DTO_FIELD_INFO(items) {
		info->description = ZH_WORDS_GETTER("assignment.fileld.items");
	}
};

/**
 * "生成托盘转移" - 传输对象
 */
class TinTransferDTO : public TinTransferBaseDTO {
	DTO_INIT(TinTransferDTO, TinTransferBaseDTO);
};

/**
 * "生成托盘转移" - 分页数据对象
 */
class TinTransferPageDTO : public PageDTO<TinTransferDTO::Wrapper>
{
	DTO_INIT(TinTransferPageDTO, PageDTO<TinTransferDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TIN_TRANSFER_DTO_