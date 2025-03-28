#pragma once
#ifndef _STOCK_DO_
#define _STOCK_DO_
#include "DoInclude.h"

class StockYJDO {
	// Î¨Ò»±àºÅ,Ö÷¼ü
	CC_SYNTHESIZE(string, id, Id);
	CC_SYNTHESIZE(string, kuctype, KuCType);
	CC_SYNTHESIZE(uint64_t, base_goodscount, Base_GoodsCount);
	CC_SYNTHESIZE(string, base_unit, Base_Unit);
	CC_SYNTHESIZE(string, ku_wei_bian_ma, Ku_Wei_Bian_Ma);
	CC_SYNTHESIZE(string, bin_id, Bin_Id);
	CC_SYNTHESIZE(string, cus_code, Cus_Code);
	CC_SYNTHESIZE(string, zhong_wen_qch, Zhong_Wen_Qch);
	CC_SYNTHESIZE(string, goods_id, Goods_Id);
	CC_SYNTHESIZE(string, shp_ming_cheng, Shp_Ming_Cheng);
	CC_SYNTHESIZE(string, shl_dan_wei, Shl_Dan_Wei);
	CC_SYNTHESIZE(string, goods_pro_data, Goods_Pro_Data);
	CC_SYNTHESIZE(string, bzhi_qi, Bzhi_Qi);
	CC_SYNTHESIZE(string, dqr, Dqr);
	CC_SYNTHESIZE(double, res_date, Res_Date);
	CC_SYNTHESIZE(int, qu_huo_ci_xu, Qu_Huo_Ci_Xu);
	CC_SYNTHESIZE(int, shang_jia_ci_xu, Shang_Jia_Ci_Xu);
	CC_SYNTHESIZE(string, shp_bian_makh, Shp_Bian_Makh);
	CC_SYNTHESIZE(string, guoqibili, GuoQiBiLi);
	CC_SYNTHESIZE(string, cusname, Cus_Name);
};

typedef std::shared_ptr<StockYJDO> PtrStockYJDO;


#endif // !_STOCK_DO_



