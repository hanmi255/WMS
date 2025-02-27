#pragma once
#ifndef _BIN_TRANSFER_QUERY_
#define _BIN_TRANSFER_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 生成储位管理分页查询对象
 */
class BinTransferQuery : public PageQuery
{

	DTO_INIT(BinTransferQuery, PageQuery);

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
	// 到日期时间
	DTO_FIELD(String, toMoveDate);
	DTO_FIELD_INFO(toMoveDate) {
		info->description = ZH_WORDS_GETTER("assignment.field.to-move-date");
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
	// 到生产日期
	DTO_FIELD(String, toProduceDate);
	DTO_FIELD_INFO(toProduceDate) {
		info->description = ZH_WORDS_GETTER("assignment.field.to-produce-date");
	}

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_BIN_TRANSFER_QUERY_