#pragma once
/*
 @Author: gutianxuan
*/
#include "../DoInclude.h"

/**
 * 订单类型数据库实体类
 */
class TemperatureDO
{

	//注意：数据库中为 id deg_type_code 小写类型，后面的Id是set、get函数的后缀
	// 唯一id
	CC_SYNTHESIZE(string, id, Id);
	//创建人名称
	CC_SYNTHESIZE(string, create_name, Create_Name);
	//创建人登陆名称
	CC_SYNTHESIZE(string, create_by, Create_By);
	//创建日期
	CC_SYNTHESIZE(string, create_date, Create_Date);

	//更新人名称
	CC_SYNTHESIZE(string, update_name, Update_Name);
	//更新人登陆名称
	CC_SYNTHESIZE(string, update_by, Update_By);
	//更新日期
	CC_SYNTHESIZE(string, update_date, Update_Date);

	//所属部门
	CC_SYNTHESIZE(string, sys_org_code, Sys_Org_Code);
	//所属公司
	CC_SYNTHESIZE(string, sys_company_code, Sys_Company_Code);

	// 温层代码
	CC_SYNTHESIZE(string, deg_type_code, Deg_Type_Code);
	// 温层名称
	CC_SYNTHESIZE(string, deg_type_name, Deg_Type_Name);


public:
	TemperatureDO() {
		id = "0";
		create_name = "admin";
		create_by = "admin";
		create_date = "";
		update_name = "";
		update_by = "";
		update_date = "";
		sys_org_code = "";
		sys_company_code = "";
		deg_type_code = "";
		deg_type_name = "";

	}
};

class TemperatureNameDO {
	// 唯一编号
	CC_SYNTHESIZE(string, id, Id);
	// 订单类型名称
	CC_SYNTHESIZE(string, deg_type_name, Deg_Type_Name);
public:
	TemperatureNameDO() {
		id = "0";
		deg_type_name = "";
	}
	TemperatureNameDO(string id, string deg_type_name)
	{
		this->id = id;
		this->deg_type_name = deg_type_name;
	}
};

typedef std::shared_ptr<TemperatureDO> PtrTemperatureDO;
typedef std::shared_ptr<TemperatureNameDO> PtrTemperatureNameDO;










// 给智能指针设定一个别名方便使用
