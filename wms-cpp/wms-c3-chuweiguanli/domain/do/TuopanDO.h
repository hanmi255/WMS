#pragma once
/*

*/
#ifndef _TUOPANDO_H_
#define _TUOPANDO_H_
#include "DoInclude.h"

class TuopanDO{
	CC_SYNTHESIZE(string, id, Id);//唯一标识 主键
	CC_SYNTHESIZE(string, create_name, CreateName);//创建人名称
	CC_SYNTHESIZE(string, create_by, CreateBy);//创建人登录名称
	CC_SYNTHESIZE(string, create_date, CreateDate);//创建日期
	CC_SYNTHESIZE(string, update_name, UpdateName);//更新人名称
	CC_SYNTHESIZE(string, update_by, UpdateBy);//更新人登录名称
	CC_SYNTHESIZE(string, update_date, UpdateDate);//更新日期
	CC_SYNTHESIZE(string, sys_org_code, SysOrgCode);//所属部门
	CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode);//所属公司
	CC_SYNTHESIZE(string, bpm_status,BpmStatus);//流程状态
	CC_SYNTHESIZE(string, tin_id, TinId);//托盘号
	CC_SYNTHESIZE(string, tin_sort, TinSort);//托盘顺序
	CC_SYNTHESIZE(string, bin_id, BinId);//储位
	CC_SYNTHESIZE(string, tin_status, TinStatus);//托盘状态

public:
	TuopanDO() {
		id = "";
		create_name = "";
		create_by = "";
		create_date = "";
		update_name = "";
		update_by = "";
		update_date = "";
		sys_org_code = "";
		sys_company_code = "";
		bpm_status = "";
		tin_id = "";
		tin_sort = "";
		bin_id = "";
		tin_status = "";
	}

};
// 给TuopanDO智能指针设定一个别名方便使用
typedef std::shared_ptr<TuopanDO> PtrTuopanDO;
#endif // !_TUOPANDO_H_