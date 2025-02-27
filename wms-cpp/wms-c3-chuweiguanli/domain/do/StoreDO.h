#pragma once
#ifndef STOREDO
#define STOREDO
#include "DoInclude.h"

class StoreDO
{
	CC_SYNTHESIZE(string, id, Id); // 唯一标识 主键
	CC_SYNTHESIZE(string, store_code, StoreCode); // 仓库编码
	CC_SYNTHESIZE(string, store_name, StoreName); // 仓库名称
	CC_SYNTHESIZE(string, store_text, StoreText); // 仓库描述
	CC_SYNTHESIZE(string, create_name, CreateName); // 创建人名称
	CC_SYNTHESIZE(string, create_by, CreateBy); // 创建人登录名称
	CC_SYNTHESIZE(string, create_date, CreateDate); // 创建日期
	CC_SYNTHESIZE(string, update_name, UpdateName); // 更新人名称
	CC_SYNTHESIZE(string, update_by, UpdateBy); // 更新人登录名称
	CC_SYNTHESIZE(string, update_date, UpdateDate); // 更新日期
	CC_SYNTHESIZE(string, sys_org_code, SysOrgCode); // 所属部门
	CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode); // 所属公司
public:
	StoreDO() {
		id = "";
		store_code = "";
		store_name = "";
		store_text = "";
		create_name = "";
		create_by = "";
		create_date = "";
		update_name = "";
		update_by = "";
		update_date = "";
		sys_org_code = "";
		sys_company_code = "";
	}
};

#endif // !STOREDO