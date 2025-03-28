#pragma once
#pragma once
#ifndef _BILLINGNAME_DO_
#define _BILLINGNAME_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class BillingNameDO
{
	// 唯一主键
	CC_SYNTHESIZE(string, id, Id); 
	CC_SYNTHESIZE(string, cost_code,Cost_code);
	CC_SYNTHESIZE(string, cost_name,Cost_name);
	CC_SYNTHESIZE(string, cost_type_code,Cost_type_code);
public:
	BillingNameDO() {
		id = "";
		cost_code = "";
		cost_name = "";
		cost_type_code = "";
	}
};

// 给BillingNameDO智能指针设定一个别名方便使用
typedef std::shared_ptr<BillingNameDO> PtrBillingNameDO;
#endif // !_BILLINGNAME_DO_