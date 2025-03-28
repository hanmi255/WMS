

#ifndef _CUSTOMER_DO_
#define _CUSTOMER_DO_
#include "../DoInclude.h"


/**
 * 示例数据库实体类
 */
class CustomerBillDO
{
	// 客户编码
	CC_SYNTHESIZE(string, cus_code, Id);
	// 中文全称
	CC_SYNTHESIZE(string, cus_name, Name);

public:
	CustomerBillDO() {
		cus_code = "";
		cus_code = "";

	}
};

// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<CustomerBillDO> PtrCustomerBillDO;
#endif // !_SAMPLE_DO_
