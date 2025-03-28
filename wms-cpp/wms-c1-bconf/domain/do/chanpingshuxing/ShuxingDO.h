#pragma once
#include "../DoInclude.h"

/**
 * 产品属性数据库实体类
 */
class ShuxingDO
{
	// 主键
	CC_SYNTHESIZE(string, id, Id);
	
	//创建人名称
	CC_SYNTHESIZE(string, create_name, Create_name);
	//创建人登录名称
	CC_SYNTHESIZE(string, create_by, Create_by);
	//创建日期
	CC_SYNTHESIZE(string, create_date, Create_date);
	//更新人名称
	CC_SYNTHESIZE(string, update_name, Update_name);
	//更新人登录名称
	CC_SYNTHESIZE(string, update_by, Update_by);
	//更新日期
	CC_SYNTHESIZE(string, update_date, Update_date);
	//所属部门
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	//所属公司
	CC_SYNTHESIZE(string, sys_company_code, Sys_company_code);
	//产品属性编码
	CC_SYNTHESIZE(string, goods_type_code, Goods_type_code);
	//产品属性名称
	CC_SYNTHESIZE(string, goods_type_name, Goods_type_name);
public:
	ShuxingDO() {
		id = "";
		create_name = "";
		create_by = "";
		create_date = "";
		update_name = "";
		update_date = "";
		sys_org_code = "";
		sys_company_code = "";
		goods_type_code = "";
		goods_type_name = "";
	}
};


typedef std::shared_ptr<ShuxingDO> PtrShuxingDO;