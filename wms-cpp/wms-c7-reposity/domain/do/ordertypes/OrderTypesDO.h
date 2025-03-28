#pragma once
/*
 @Author: nanbowan
*/
#include "../DoInclude.h"

/**
 * 订单类型数据库实体类
 */
class OrderTypesDO
{
	// 唯一id
	CC_SYNTHESIZE(string, id, Id);
	// 订单类型代码
	CC_SYNTHESIZE(string, order_type_code, Code);
	// 订单类型名称
	CC_SYNTHESIZE(string, order_type_name, Name);

public:
	OrderTypesDO() {
		id = "0";
		order_type_code = "";
		order_type_name = "";
	}
};

// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<OrderTypesDO> PtrOrderTypesDO;


