#pragma once

#ifndef _PIS_DO_
#define _PIS_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class PisDO
{
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 品检状态代码
	CC_SYNTHESIZE(string, code, Code);
	// 品检状态名称
	CC_SYNTHESIZE(string, name, Name);
	// 基础信息
	CC_SYNTHESIZE(string, create_name, Create_Name);
	CC_SYNTHESIZE(string, create_by, Create_By);
	CC_SYNTHESIZE(string, update_name, Update_Name);
	CC_SYNTHESIZE(string, update_by, Update_By);
	CC_SYNTHESIZE(string, update_date, Update_Date);
	CC_SYNTHESIZE(string, sys_org_code, Sys_Org_Code);
	CC_SYNTHESIZE(string, sys_company_code, Sys_Company_Code);

public:
	PisDO() {
	}
};

// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<PisDO> PtrPisDO;
#endif // !_SAMPLE_DO_
