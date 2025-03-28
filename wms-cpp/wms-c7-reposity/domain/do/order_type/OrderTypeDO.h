#pragma once
#ifndef _ORDERTYPE_DO_H
#define _ORDERTYPE_DO_H
#include "../DoInclude.h"

class OrderTypeAddDO {
	// 唯一编号
	CC_SYNTHESIZE(string, id, Id);
	// 订单类型代码
	CC_SYNTHESIZE(string, order_type_code, OrderTypeCode);
	// 订单类型名称
	CC_SYNTHESIZE(string, order_type_name, OrderTypeName);
	// 创建日期
	CC_SYNTHESIZE(string, create_date, CreateDate);
	// 创建人名称
	CC_SYNTHESIZE(string, create_name, CreateName);
	// 创建人登录名称
	CC_SYNTHESIZE(string, create_by, CreateBy);
	// 所属部门
	CC_SYNTHESIZE(string, sys_org_code, SysOrgCode);
	// 所属公司
	CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode);
public:
	OrderTypeAddDO() : id(""), order_type_code(""), order_type_name("") {}
	OrderTypeAddDO(string id, string order_type_code, string order_type_name)
	{
		this->id = id;
		this->order_type_code = order_type_code;
		this->order_type_name = order_type_name;
	}
};

class OrderTypeDO {
	// 唯一编号
	CC_SYNTHESIZE(string, id, Id);
	// 订单类型代码
	CC_SYNTHESIZE(string, order_type_code, OrderTypeCode);
	// 订单类型名称
	CC_SYNTHESIZE(string, order_type_name, OrderTypeName);
public:
	OrderTypeDO() :id(""), order_type_code(""), order_type_name("") {}
	OrderTypeDO(string id, string order_type_code, string order_type_name)
	{
		this->id = id;
		this->order_type_code = order_type_code;
		this->order_type_name = order_type_name;
	}
};


class OrderTypeNameDO {
	// 唯一编号
	CC_SYNTHESIZE(string, id, Id);
	// 订单类型名称
	CC_SYNTHESIZE(string, order_type_name, OrderTypeName);
public:
	OrderTypeNameDO() :id(""), order_type_name("") {}
	OrderTypeNameDO(string id, string order_type_name)
	{
		this->id = id;
		this->order_type_name = order_type_name;
	}
};

typedef std::shared_ptr<OrderTypeDO> PtrOrderTypeDO;
typedef std::shared_ptr<OrderTypeNameDO> PtrOrderTypeNameDO;

#endif //!_ORDERTYPE_DO_H