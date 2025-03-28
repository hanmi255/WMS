#pragma once

#ifndef _STT_ON_MOVE_QUERY_
#define _STT_ON_MOVE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* 动碰盘点分页查询对象
*/
class SttOnMoveQuery : public PageQuery
{
	DTO_INIT(SttOnMoveQuery, PageQuery);

	//最早移动日期
	API_DTO_FIELD_DEFAULT(String, last_move_start,ZH_WORDS_GETTER("sttOnMove.field.lastMoveStart"));
	// 最晚移动日期
	API_DTO_FIELD_DEFAULT(String, last_move_end,ZH_WORDS_GETTER("sttOnMove.field.lastMoveEnd"));
	// 库存类型
	API_DTO_FIELD_DEFAULT(String, cktype, ZH_WORDS_GETTER("sttOnMove.field.kuctype"));
	// 储位 or 库位编码
	API_DTO_FIELD_DEFAULT(String, bin_id, ZH_WORDS_GETTER("sttOnMove.field.kuWeiBianMa"));
	// 托盘
	API_DTO_FIELD_DEFAULT(String, tin_id, ZH_WORDS_GETTER("sttOnMove.field.binId"));
	// 货主
	API_DTO_FIELD_DEFAULT(String, cus_code, ZH_WORDS_GETTER("sttOnMove.field.cusCode"));
	// 货主名称
	API_DTO_FIELD_DEFAULT(String, cus_name, ZH_WORDS_GETTER("sttOnMove.field.zhongWenQch"));
	// 商品编码
	API_DTO_FIELD_DEFAULT(String, goods_id, ZH_WORDS_GETTER("sttOnMove.field.goodsId"));
	// 最小商品数量
	API_DTO_FIELD_DEFAULT(String, goods_qua_min, ZH_WORDS_GETTER("sttOnMove.field.goodsQuaMin"));
	// 最大商品数量
	API_DTO_FIELD_DEFAULT(String, goods_qua_max, ZH_WORDS_GETTER("sttOnMove.field.goodsQuaMax"));
	// 商品名称
	API_DTO_FIELD_DEFAULT(String, goods_name, ZH_WORDS_GETTER("sttOnMove.field.shpMingCheng"));
	// 最早生产日期
	API_DTO_FIELD_DEFAULT(String, goods_pro_data_start, ZH_WORDS_GETTER("sttOnMove.field.goodsProDataStart"));
	// 最晚生产日期
	API_DTO_FIELD_DEFAULT(String, goods_pro_data_end, ZH_WORDS_GETTER("sttOnMove.field.goodsProDataEnd"));
};

#include OATPP_CODEGEN_END(DTO)

#endif