#pragma once
#ifndef _COSTSUM_DO_
#define _COSTSUM_DO_
#include "DoInclude.h"

//外包装车费数据库实体类
class CostSumDO
{
	// 费用
	CC_SYNTHESIZE(string, id, ID);
	//操作人
	CC_SYNTHESIZE(string, cost_data, cost_date);//operator 是一个关键字
	//操作日期
	CC_SYNTHESIZE(string, cus_code, client_c);
	//单号
	CC_SYNTHESIZE(string, cus_name, client_name);
	//商品
	CC_SYNTHESIZE(string, cost_code,cost_c );
	//商品名称
	CC_SYNTHESIZE(string, cost_name, cost_name);
	//商品数
	CC_SYNTHESIZE(string, cost_js, Cost_Js);
	//商品重量
	CC_SYNTHESIZE(string, yuanj,org_price);
	//费用RMB
	CC_SYNTHESIZE(string, bhsj, no_tax);
	//单价
	CC_SYNTHESIZE(string, shuie, Tax);
	CC_SYNTHESIZE(string, cost_sl, Number);
	CC_SYNTHESIZE(string, hansj, tax_price);
	CC_SYNTHESIZE(string, cost_unit, Unit);
};

// 给LoadingFeeDO智能指针设定一个别名方便使用
typedef std::shared_ptr<CostSumDO> PtrCostSumDO;
#endif // _LOADINGFEE_DO_