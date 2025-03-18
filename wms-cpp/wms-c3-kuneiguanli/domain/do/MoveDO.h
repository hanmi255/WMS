#pragma once
#ifndef _MOVE_DO_
#define _MOVE_DO_
#include "domain/do/DoInclude.h"

class MoveDO {
	CC_SYNTHESIZE(string, move_date, MoveDate);        //创建日期/移动日期
	CC_SYNTHESIZE(string, kuctype, KucType);							   // 库存类型
	CC_SYNTHESIZE(string, ku_wei_bian_ma, KuWeiBianMa);			   // 储位
	CC_SYNTHESIZE(string, bin_id, BinId);				   // 托盘
	CC_SYNTHESIZE(string, cus_code, CusCode);			   // 货主
	CC_SYNTHESIZE(string, zhong_wen_qch, ZhongWenQch);			   // 货主名称
	CC_SYNTHESIZE(string, goods_id, GoodsId);				   // 商品编码
	CC_SYNTHESIZE(string, goods_qua, GoodsQua);			   // 商品数量
	CC_SYNTHESIZE(string, shp_ming_cheng, ShpMingCheng);		   // 商品名称
	CC_SYNTHESIZE(string, goods_pro_data, GoodsProData);   // 生产日期
	CC_SYNTHESIZE(string, bzhi_qi, BzhiQi);	   // 保质期
	CC_SYNTHESIZE(string, goods_unit, GoodsUnit);				   // 单位
	CC_SYNTHESIZE(string, stt_sta, SttSta);			   // 状态
	
	

public:
	MoveDO()
	{
		move_date = "";
		kuctype = "";
		ku_wei_bian_ma = "";
		bin_id = "";
		cus_code = "";
		zhong_wen_qch = "";
		goods_id = "";
		goods_qua = "";
		shp_ming_cheng = "";
		goods_pro_data = "";
		bzhi_qi = "";
		goods_unit = "";
		stt_sta = "";
		
	}
};
// 给MoveDO智能指针设定一个别名方便使用
typedef std::shared_ptr<MoveDO> PtrMoveDO;
#endif // !_MOVE_DO_