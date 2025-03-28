#pragma once
/*
 @Author: laughter
*/
#ifndef _COMPANYATTR_DO_
#define _COMPANYATTR_DO_
#include "../DoInclude.h"

/**
 * 数据库实体类
 */
class CompanyattrDO
{
	// 编号
	//CC_SYNTHESIZE(string, id, Id);
	// 企业属性代码
	CC_SYNTHESIZE(string, com_type_code, com_type_Code);
	// 企业属性名称
	CC_SYNTHESIZE(string, com_type_name, com_type_Name);
	//// 年龄
	//CC_SYNTHESIZE(int, age, Age);
public:
	CompanyattrDO() {
		//id = "";
		com_type_code = "";
		com_type_name = "";
		//age = -1;
	}
};

class CompanyattrIdDO
{
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 企业属性代码
	CC_SYNTHESIZE(string, com_type_code, com_type_Code);
	// 企业属性名称
	CC_SYNTHESIZE(string, com_type_name, com_type_Name);
	//创建人名称
	CC_SYNTHESIZE(string, create_name, create_Name);
	//创建人登录名称
	CC_SYNTHESIZE(string, create_by, create_By);
	//创建时间
	CC_SYNTHESIZE(string, create_date, create_Date);
	//修改人名称
	CC_SYNTHESIZE(string, update_name, update_Name);
	//修改人登录名称
	CC_SYNTHESIZE(string, update_by, update_By);
	//修改时间时间
	CC_SYNTHESIZE(string, update_date, update_Date);
	//所属部门
	CC_SYNTHESIZE(string, sys_org_code, sys_org_Code);
	//所属公司
	CC_SYNTHESIZE(string, sys_company_code, sys_company_Code);
public:
	CompanyattrIdDO() {
		id = "";
		com_type_code = "";
		com_type_name = "";
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
// 给CompanyattrDO智能指针设定一个别名方便使用
typedef std::shared_ptr<CompanyattrDO> PtrCompanyattrDO;
#endif // !_Companyattr_DO_
