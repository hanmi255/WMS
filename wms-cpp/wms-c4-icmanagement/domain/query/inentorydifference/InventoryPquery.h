#pragma once

#ifndef _INVENTORY_PQUERY_
#define _INVENTORY_PQUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 盘点人查询对象
 */
class InventoryPquery : public PageQuery
{
	DTO_INIT(InventoryPquery, PageQuery);
	// 盘点人
	API_DTO_FIELD(String, stt_name, ZH_WORDS_GETTER("mql.stt.stt_name"), false, "LiHua");

	//盘点日期
	API_DTO_FIELD(String, stt_date, ZH_WORDS_GETTER("mql.stt.stt_date"), false, "2099-12-31");

	// 储位
	API_DTO_FIELD(String, bin_id, ZH_WORDS_GETTER("mql.rest.bin_id"), false, "X1-1-03");

	//托盘
	API_DTO_FIELD(String, tin_id, ZH_WORDS_GETTER("mql.rest.tin_id"), false, "2222");

	//商品编码
	API_DTO_FIELD(String, goods_id, ZH_WORDS_GETTER("mql.goods.goods_id"), false, "22022");

	//商品名称
	API_DTO_FIELD(String, goods_name, ZH_WORDS_GETTER("mql.goods.goods_name"), false, ZH_WORDS_GETTER("inv.computer"));

	//账单数量
	API_DTO_FIELD(String, goods_qua, ZH_WORDS_GETTER("mql.goods.goods_qua"), false, "2443");

	//单位
	API_DTO_FIELD(String, goods_unit, ZH_WORDS_GETTER("mql.goods.goods_unit"), false, ZH_WORDS_GETTER("inv.box"));

	//生产日期
	API_DTO_FIELD(String, goods_pro_data, ZH_WORDS_GETTER("mql.goods.goods_pro_data"), false, "2099-12-31");

	//盘点数量
	API_DTO_FIELD(String, stt_qua, ZH_WORDS_GETTER("mql.stt.stt_qua"), false, "34");

	//货主
	API_DTO_FIELD(String, cus_code, ZH_WORDS_GETTER("mql.cus.cus_code"), false, "LiHua");

	//货主编码
	API_DTO_FIELD(String, cus_id, ZH_WORDS_GETTER("mql.cus.cus_id"), false, "X00001");

	//盘点状态
	API_DTO_FIELD(String, stt_sta, ZH_WORDS_GETTER("mql.stt.stt_sta"), false, ZH_WORDS_GETTER("inv.finish"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_INVENTORY_PQUERY_