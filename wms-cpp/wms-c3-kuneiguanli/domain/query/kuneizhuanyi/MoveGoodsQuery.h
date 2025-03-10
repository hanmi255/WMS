#pragma once

#include "domain/GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 分页查询转移任务列表
*/
class MoveGoodsQuery : public PageQuery {
	DTO_INIT(MoveGoodsQuery, PageQuery);
	// 转移任务ID
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("move-goods.field.id");
	}
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
	// 货主
	DTO_FIELD(String, cusCode);
	DTO_FIELD_INFO(cusCode) {
		info->description = ZH_WORDS_GETTER("move-goods.field.cus-code");
	}
	// 货主名称
	DTO_FIELD(String, cusName);
	DTO_FIELD_INFO(cusName) {
		info->description = ZH_WORDS_GETTER("move-goods.field.cus-name");
	}
	// 到货主
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
	DTO_FIELD(String, moveSta);
	DTO_FIELD_INFO(moveSta) {
		info->description = ZH_WORDS_GETTER("move-goods.field.move-sta");
	}
	// 执行状态
	DTO_FIELD(String, runSta);
	DTO_FIELD_INFO(runSta) {
		info->description = ZH_WORDS_GETTER("move-goods.field.run-sta");
	}
};

/**
* 查询转移任务基础信息
*/
class MoveGoodsBaseQuery : public PageQuery {
	DTO_INIT(MoveGoodsBaseQuery, PageQuery);
	// 转移任务ID
	DTO_FIELD(oatpp::List<oatpp::String>, items);
	DTO_FIELD_INFO(items) {
		info->description = ZH_WORDS_GETTER("move-goods.field.items");
	}
};

// 查询导出转移任务
class MoveGoodsExcelQuery : public oatpp::DTO
{
	DTO_INIT(MoveGoodsExcelQuery, DTO);

	DTO_FIELD(String, file_path);
	DTO_FIELD_INFO(file_path) {
		info->description = ZH_WORDS_GETTER("move-goods.field.file_path");
	}

	DTO_FIELD(String, ids);
	DTO_FIELD_INFO(ids) {
		info->description = ZH_WORDS_GETTER("move-goods.field.id");
	}
};

#include OATPP_CODEGEN_END(DTO)
