#pragma once
#ifndef _BUSSTYPE_DO_
#define _BUSSTYPE_DO_
#include "../DoInclude.h"

class BussTypeDO {
	// 唯一编号
	CC_SYNTHESIZE(string, id, Id);
	// 业务类型名称
	CC_SYNTHESIZE(string, buss_type_name, BussTypeName);
	// 业务类型代码
	CC_SYNTHESIZE(string, buss_type_code, BussTypeCode);
	// 业务类型备注
	CC_SYNTHESIZE(string, buss_type_text, BussTypeText);
	CC_SYNTHESIZE(string, create_name, CreateName);
	CC_SYNTHESIZE(string, create_by, CreateBy);
	CC_SYNTHESIZE(string, create_date, CreateDate);
	CC_SYNTHESIZE(string, sys_org_code, SysOrgCode);
	CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode);

public:
	BussTypeDO(){
		id = "0";
		buss_type_code = "";
		buss_type_name = "";
		buss_type_text = "";
	}
	BussTypeDO(string id, string code, string name, string text)
	{
		this->id = id;
		this->buss_type_name = name;
		this->buss_type_code = code;
		this->buss_type_text = text;
	}
};

//class BussTypeAddDO {
//	CC_SYNTHESIZE(string, id, Id);
//	CC_SYNTHESIZE(string, buss_type_code, BussTypeCode);
//	CC_SYNTHESIZE(string, buss_type_name, BussTypeName);
//	CC_SYNTHESIZE(string, buss_type_text, BussTypeText);
//	CC_SYNTHESIZE(string, create_name, CreateName);
//	CC_SYNTHESIZE(string, create_by, CreateBy);
//	CC_SYNTHESIZE(string, create_date, CreateDate);
//	CC_SYNTHESIZE(string, sys_org_code, SysOrgCode);
//	CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode);
//public:
//	BussTypeAddDO(){}
//	BussTypeAddDO(string id, string code, string name, string text,string CreatBy,string CreateDate,string SysCompanyCode,string SysOrgCode)
//	{
//		this->id = id;
//		this->buss_type_code = code;
//		this->buss_type_name = name;
//		this->buss_type_text = text;
//		this->create_by = CreatBy;
//		this->create_date = CreateDate;
//		this->sys_company_code = SysCompanyCode;
//		this->sys_org_code = SysOrgCode;
//	}
//};

typedef std::shared_ptr<BussTypeDO> PtrBussTypeDO;
//typedef std::shared_ptr<BussTypeAddDO> PtrBussTypeAddDO;
#endif // _BUSSTYPE_DO_