#ifndef _DAREAINFO_DO_
#define _DAREAINFO_DO_
#include "../DoInclude.h"

class DareaInfoExportDO
{
	CC_SYNTHESIZE(string, area_code, Area_code);
	CC_SYNTHESIZE(string, area_name, Area_name);
public:
	DareaInfoExportDO()
	{
		area_code = "000";
		area_name = "xxx";
	}
};
class DareaInfoDO : public DareaInfoExportDO
{
	CC_SYNTHESIZE(string, id, Id);
public:
	DareaInfoDO()
	{
		id = "id";
		area_code = "000";
		area_name = "xxx";
	}
};

class DareaInfoAddDO
{
	CC_SYNTHESIZE(string, id, Id);
	CC_SYNTHESIZE(string, create_name, Create_name);
	CC_SYNTHESIZE(string, create_by, Create_by);
	CC_SYNTHESIZE(string, create_date, Create_date);
	CC_SYNTHESIZE(string, update_name, Update_name);
	CC_SYNTHESIZE(string, update_by, Update_by);
	CC_SYNTHESIZE(string, update_date, Update_date);
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	CC_SYNTHESIZE(string, sys_company_code, Sys_company_code);
	CC_SYNTHESIZE(string, area_code, Area_code);
	CC_SYNTHESIZE(string, area_name, Area_name);
public:
	DareaInfoAddDO()
	{
		id = "ex";
		create_name = "xxx";
		create_by = "xxx";
		create_date = "x-x-x";
		update_name = "xxx";
		update_by = "xxx";
		update_date = "x-x-x";
		sys_org_code = "org_code";
		sys_company_code = "company_code";
		area_code = "000";
		area_name = "000";
	}
};

class DareaInfoUpdDO
{
	CC_SYNTHESIZE(string, id, Id);
	CC_SYNTHESIZE(string, update_name, Update_name);
	CC_SYNTHESIZE(string, update_by, Update_by);
	CC_SYNTHESIZE(string, update_date, Update_date);
	CC_SYNTHESIZE(string, area_code, Area_code);
	CC_SYNTHESIZE(string, area_name, Area_name);
public:
	DareaInfoUpdDO()
	{
		id = "id";
		update_name = "update_name";
		update_by = "update_by";
		update_date = "update_date";
		area_code = "area_code";
		area_name = "area_name";
	}
};

#endif // !_DAREAINFO_DO_
