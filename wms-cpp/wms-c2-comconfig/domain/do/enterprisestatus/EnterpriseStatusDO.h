#pragma once
#ifndef _ENTERPRISESTATUSDO_
#define _ENTERPRISESTATUSDO_
#include "../DoInclude.h"

class EnterpriseStatusDO
{
	// 编号
	CC_SYNTHESIZE(string, enterpriseid, kehuzhuangtai_code);
	// 企业名
	CC_SYNTHESIZE(string, enterprisename, kehuzhuangtai_name);
	// 状态
	CC_SYNTHESIZE(string, status, cus_sta_del);
public:
	EnterpriseStatusDO() {
		enterpriseid = "C001";
		enterprisename = "客户1";
		status = "Y";
	}
};

class EnterpriseStatusListDO
{
	// 唯一编码
	CC_SYNTHESIZE(string, statusonlyid, id);
	// 编号
	CC_SYNTHESIZE(string, enterpriseid, kehuzhuangtai_code);
	// 企业名
	CC_SYNTHESIZE(string, enterprisename, kehuzhuangtai_name);
public:
	EnterpriseStatusListDO() {
		statusonlyid = " ";
		enterpriseid = "C001";
		enterprisename = "客户1";
	}
};

// 给DO智能指针设定一个别名方便使用
typedef std::shared_ptr<EnterpriseStatusDO> PtrEnterpriseStatusDO;
typedef std::shared_ptr<EnterpriseStatusListDO> PtrEnterpriseStatusListDO;
#endif // !_ENTERPRISESTATUSDO_
