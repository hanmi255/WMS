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
		info->description = ZH_WORDS_GETTER("movegoods.field.id");
	}
	// 商品编码
	DTO_FIELD(String, goods_id);
	DTO_FIELD_INFO(goods_id) {
		info->description = ZH_WORDS_GETTER("movegoods.field.goods_id");
	}
	// 商品名称
	DTO_FIELD(String, goods_name);
	DTO_FIELD_INFO(goods_name) {
		info->description = ZH_WORDS_GETTER("movegoods.field.goods_name");
	}
	// 客户编码
	DTO_FIELD(String, cus_code);
	DTO_FIELD_INFO(cus_code) {
		info->description = ZH_WORDS_GETTER("movegoods.field.cus_code");
	}
	// 客户名称
	DTO_FIELD(String, cus_name);
	DTO_FIELD_INFO(cus_name) {
		info->description = ZH_WORDS_GETTER("movegoods.field.cus_name");
	}
	// 转移客户
	DTO_FIELD(String, to_cus_code);
	DTO_FIELD_INFO(to_cus_code) {
		info->description = ZH_WORDS_GETTER("movegoods.field.to_cus_code");
	}
	// 转移客户名称
	DTO_FIELD(String, to_cus_name);
	DTO_FIELD_INFO(to_cus_name) {
		info->description = ZH_WORDS_GETTER("movegoods.field.to_cus_name");
	}
	// 源托盘
	DTO_FIELD(String, tin_from);
	DTO_FIELD_INFO(tin_from) {
		info->description = ZH_WORDS_GETTER("movegoods.field.tin_from");
	}
	// 到托盘
	DTO_FIELD(String, tin_id);
	DTO_FIELD_INFO(tin_id) {
		info->description = ZH_WORDS_GETTER("movegoods.field.tin_id");
	}
	// 源储位
	DTO_FIELD(String, bin_from);
	DTO_FIELD_INFO(bin_from) {
		info->description = ZH_WORDS_GETTER("movegoods.field.bin_from");
	}
	// 到储位
	DTO_FIELD(String, bin_to);
	DTO_FIELD_INFO(bin_to) {
		info->description = ZH_WORDS_GETTER("movegoods.field.bin_to");
	}
	// 状态
	DTO_FIELD(String, move_sta);
	DTO_FIELD_INFO(move_sta) {
		info->description = ZH_WORDS_GETTER("movegoods.field.move_sta");
	}
	// 执行状态
	DTO_FIELD(String, run_sta);
	DTO_FIELD_INFO(run_sta) {
		info->description = ZH_WORDS_GETTER("movegoods.field.run_sta");
	}
};

/**
* 查询转移任务基础信息
*/
class MoveGoodsBaseQuery : public PageQuery {
	DTO_INIT(MoveGoodsBaseQuery, PageQuery);
	// 转移任务ID
<<<<<<< HEAD
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("movegoods.field.id");
=======
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
>>>>>>> 05f7ec7fb45d4bc1f52eea780440c95f076c61f0
	}
};

#include OATPP_CODEGEN_END(DTO)
