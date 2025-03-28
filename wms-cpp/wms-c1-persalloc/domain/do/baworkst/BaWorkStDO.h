#ifndef _BAWORKST_DO_
#define _BAWORKST_DO_
#include "../DoInclude.h"

/**
 * 工作状态实体类
 */
class BaWorkStDO
{
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 创建人名称
	CC_SYNTHESIZE(string, create_name,CreateName);
	// 创建人登录名称
	CC_SYNTHESIZE(string, create_by, CreateBy);
	// 创建日期
	CC_SYNTHESIZE(string, create_date, CreateDate);
	// 更新人名称
	CC_SYNTHESIZE(string, update_name, UpdateName);
	//更新人登录名称
	CC_SYNTHESIZE(string, update_by, UpdateBy);
	//更新日期
	CC_SYNTHESIZE(string, update_date, UpdateDate);
	//所属部门
	CC_SYNTHESIZE(string, sys_org_code, SysOrgCode);
	//所属公司
	CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode);
	//工作状态代码
	CC_SYNTHESIZE(string, work_sta_code,WorkStaCode);
	//工作状态名称
	CC_SYNTHESIZE(string, work_sta_name,WorkStaName);
	
public:
	BaWorkStDO() {
		id = "0";
		create_name = "";
		create_by = "";
		create_date = "";
		update_name = "";
		update_by = "";
		update_date = "";
		sys_org_code = "";
		sys_company_code = "";
		work_sta_code = "";
		work_sta_name = "";
	}
};

// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<BaWorkStDO> PtrBaWorkStDO;
#endif // !_SAMPLE_DO_