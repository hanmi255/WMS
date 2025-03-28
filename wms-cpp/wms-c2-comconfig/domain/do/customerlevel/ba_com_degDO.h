#pragma once
#ifndef _BA_COM_DEGDO_H_
#define _BA_COM_DEGDO_H_

#include "../DoInclude.h"
/**
 * 客户等级数据库实体
 */
class CustomerLevelDO
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
	CustomerLevelDO() {
		name = "";
		code = "";
		id = "";
		ban = "";
	}
};

// 给CustomerLevelDO智能指针设定一个别名方便使用
typedef std::shared_ptr<CustomerLevelDO> PtrCustomerLevelDO;
#endif // !_BA_COM_DEG_H_