#pragma once

#ifndef _UNLOADINGFEE_DO_
#define _UNLOADINGFEE_DO_
#include "DoInclude.h"

//外包卸货费数据库实体类
class UnloadingFeeDO
{
	// 费用
	CC_SYNTHESIZE(string, fee, Fee);
	//验收人
	CC_SYNTHESIZE(string, acceptor, Acceptor);
	//验收日期
	CC_SYNTHESIZE(string, acceptDate, AcceptDate);
	//单号
	CC_SYNTHESIZE(string, orderNo, OrderNo);
	//商品
	CC_SYNTHESIZE(string, goods, Goods);
	//商品名称
	CC_SYNTHESIZE(string, goodsName, GoodsName);
	//卸货数
	CC_SYNTHESIZE(int, unloadingNum, UnloadingNum);
	//卸货重量
	CC_SYNTHESIZE(double, unloadingWeight, UnloadingWeight);
	//费用RMB
	CC_SYNTHESIZE(double, feeRMB, FeeRMB);
	//单价
	CC_SYNTHESIZE(double, price, Price);
};

// 给UnloadingFeeDO智能指针设定一个别名方便使用
typedef std::shared_ptr<UnloadingFeeDO> PtrUnloadingFeeDO;
#endif // !_UNLOADINGFEE_DO_