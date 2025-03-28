#pragma once

#ifndef _LOADINGFEE_DO_
#define _LOADINGFEE_DO_
#include "DoInclude.h"

//外包装车费数据库实体类
class LoadingFeeDO
{
	// 费用
	CC_SYNTHESIZE(string, fee, Fee);
	//操作人
	CC_SYNTHESIZE(string, Operator, XOperator);//operator 是一个关键字
	//操作日期
	CC_SYNTHESIZE(string, operateDate, OperateDate);
	//单号
	CC_SYNTHESIZE(string, orderNo, OrderNo);
	//商品
	CC_SYNTHESIZE(string, goods, Goods);
	//商品名称
	CC_SYNTHESIZE(string, goodsName, GoodsName);
	//商品数
	CC_SYNTHESIZE(int, goodsNum, GoodsNum);
	//商品重量
	CC_SYNTHESIZE(double, goodsWeight, GoodsWeight);
	//费用RMB
	CC_SYNTHESIZE(double, feeRMB, FeeRMB);
	//单价
	CC_SYNTHESIZE(double, price, Price);
};

// 给LoadingFeeDO智能指针设定一个别名方便使用
typedef std::shared_ptr<LoadingFeeDO> PtrLoadingFeeDO;
#endif // _LOADINGFEE_DO_