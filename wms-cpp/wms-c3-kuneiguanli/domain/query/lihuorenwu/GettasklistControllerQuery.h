#pragma once


#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 理货任务分页查询对象
 */
class GettasklistControllerQuery : public PageQuery
{

	DTO_INIT(GettasklistControllerQuery, PageQuery);

	//唯一标识
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("assignment.field.id");
	}

	// 库存类型
	DTO_FIELD(String, inventoryType);
	DTO_FIELD_INFO(inventoryType) {
		info->description = ZH_WORDS_GETTER("output.con.inventoryType");
	}
	// 数量
	DTO_FIELD(String, goods_qua);
	DTO_FIELD_INFO(goods_qua) {
		info->description = ZH_WORDS_GETTER("output.con.goods_qua");
	}
	// 单位
	DTO_FIELD(String, shl_dan_wei);
	DTO_FIELD_INFO(shl_dan_wei) {
		info->description = ZH_WORDS_GETTER("output.con.shl_dan_wei");
	}
	// 基本单位数量
	DTO_FIELD(String,base_goodscount);
	DTO_FIELD_INFO(base_goodscount) {
		info->description = ZH_WORDS_GETTER("output.con.base_goodscount");
	}
	// 基本单位
	DTO_FIELD(String,base_unit);
	DTO_FIELD_INFO(base_unit) {
		info->description = ZH_WORDS_GETTER("output.con.base_unit");
	}
	// 储位
	DTO_FIELD(String, bin);
	DTO_FIELD_INFO(bin) {
		info->description = ZH_WORDS_GETTER("output.con.bin");
	}
	// 托盘
	DTO_FIELD(String, tin);
	DTO_FIELD_INFO(tin) {
		info->description = ZH_WORDS_GETTER("output.con.tin");
	}
	// 货主
	DTO_FIELD(String, cusCode);
	DTO_FIELD_INFO(cusCode) {
		info->description = ZH_WORDS_GETTER("output.con.cusCode");
	}
	// 货主名称
	DTO_FIELD(String, cusName);
	DTO_FIELD_INFO(cusName) {
		info->description = ZH_WORDS_GETTER("output.con.cusName");
	}
	// 商品
	DTO_FIELD(String, commodity);
	DTO_FIELD_INFO(commodity) {
		info->description = ZH_WORDS_GETTER("output.con.commodity");
	}
	// 商品名称
	DTO_FIELD(String,shp_ming_cheng);
	DTO_FIELD_INFO(shp_ming_cheng) {
		info->description = ZH_WORDS_GETTER("output.con.shp_ming_cheng");
	}
	//生成日期
	DTO_FIELD(String, goods_pro_data);
	DTO_FIELD_INFO(goods_pro_data) {
		info->description = ZH_WORDS_GETTER("output.con.goods_pro_data");
	}
	//保质期
	DTO_FIELD(String, bzhi_qi);
	DTO_FIELD_INFO(bzhi_qi) {
		info->description = ZH_WORDS_GETTER("output.con.bzhi_qi");
	}
	//到期日
	  DTO_FIELD(String, to_goods_pro_data);
	DTO_FIELD_INFO(to_goods_pro_data) {
		info->description = ZH_WORDS_GETTER("output.con.to_goods_pro_data");
	}
	//仓库
	DTO_FIELD(String, bin_store);
	DTO_FIELD_INFO(bin_store) {
		info->description = ZH_WORDS_GETTER("output.con.bin_store");
	}

};

#include OATPP_CODEGEN_END(DTO)

