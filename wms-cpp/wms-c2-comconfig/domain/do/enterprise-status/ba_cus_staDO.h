#pragma once
#ifndef _BA_CUS_STADO_H_
#define _BA_CUS_STADO_H_

#include "../DoInclude.h"
/**
 * 客户状态数据库实体
 */
class CustomerStatusDO
{
	// 名称
	CC_SYNTHESIZE(string, name, Name);
	// 编号
	CC_SYNTHESIZE(string, code, Code);
	// 唯一id
	CC_SYNTHESIZE(string, id, Id);
	// 是否停用
	CC_SYNTHESIZE(string, ban, Ban);
public:
	CustomerStatusDO() {
		name = "";
		code = "";
		id = "";
		ban = "";
	}
};

// 给CustomerStatusDO智能指针设定一个别名方便使用
typedef std::shared_ptr<CustomerStatusDO> PtrCustomerStatusDO;
#endif // !_BA_CUS_STADO_H_