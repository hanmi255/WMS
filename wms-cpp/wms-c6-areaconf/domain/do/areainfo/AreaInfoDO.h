#ifndef _AREAINFO_DO_
#define _AREAINFO_DO_
#include "../DoInclude.h"

class city_type_codeDO
{
	CC_SYNTHESIZE(string, city_type_code, City_type_code);
public:
	city_type_codeDO()
	{
		city_type_code = "0";
	}
};

class darea_codeDO
{
	CC_SYNTHESIZE(string, darea_code, Darea_code);
public:
	darea_codeDO()
	{
		darea_code = "0";
	}
};

class barea_codeDO
{
	CC_SYNTHESIZE(string, barea_code, Barea_code);
public:
	barea_codeDO()
	{
		barea_code = "0";
	}
};

class AreaInfoUpdDO
{
	CC_SYNTHESIZE(string, id, Id);
	CC_SYNTHESIZE(string, update_name, Update_name);
	CC_SYNTHESIZE(string, update_by, Update_by);
	CC_SYNTHESIZE(string, update_date, Update_date);
	CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
	CC_SYNTHESIZE(string, sys_company_code, Sys_company_code);
	CC_SYNTHESIZE(string, city_code, City_code);
	CC_SYNTHESIZE(string, city_name, City_name);
	CC_SYNTHESIZE(string, city_serc, City_serc);
	CC_SYNTHESIZE(string, city_type_code, City_type_code);
	CC_SYNTHESIZE(string, barea_code, Barea_code);
	CC_SYNTHESIZE(string, darea_code, Darea_code);
	CC_SYNTHESIZE(string, city_del, City_del);
public:
	AreaInfoUpdDO()
	{
		update_name = "admin";
		update_by = "admin";
		update_date = "2025-2-23";
		sys_org_code = "org_code";
		sys_company_code = "company_code";
		city_code = "00";
		city_name = "XX";
		city_serc = "xx";
		city_type_code = "0";
		barea_code = "0";
		darea_code = "0";
		city_del = "N";
	}
};

class AreaInfoDO
{
	CC_SYNTHESIZE(string, city_code, City_code);
	CC_SYNTHESIZE(string, city_name, City_name);
	CC_SYNTHESIZE(string, city_serc, City_serc);
	CC_SYNTHESIZE(string, city_type_name, City_type_name);
	CC_SYNTHESIZE(string, barea_name, Barea_name);
	CC_SYNTHESIZE(string, darea_name, Darea_name);
	CC_SYNTHESIZE(string, city_del, City_del);
public:
	AreaInfoDO()
	{
		city_code = "code";
		city_name = "name";
		city_serc = "serc";
		city_type_name = "type_code";
		barea_name = "barea_code";
		darea_name = "darea_code";
		city_code = "city_code";
	}
};

class AreaInfoListDO : public AreaInfoDO
{
	CC_SYNTHESIZE(string, id, Id);
public:
	AreaInfoListDO()
	{
		id = "001";
		city_code = "code";
		city_name = "name";
		city_serc = "serc";
		city_type_name = "type_code";
		barea_name = "barea_code";
		darea_name = "darea_code";
		city_code = "city_code";
	}
};

class AreaNameTreeDO
{

	CC_SYNTHESIZE(string, cid, Cid);
	CC_SYNTHESIZE(string, parentId, ParentId);
	CC_SYNTHESIZE(string, id, Id);
	CC_SYNTHESIZE(string, city_code, City_code);
	CC_SYNTHESIZE(string, city_name, City_name);
public:
	AreaNameTreeDO(){}
	AreaNameTreeDO(string cid, string parentId, string id,string city_code, string city_name )
	{
		this->cid = cid;
		this->parentId = parentId;
		this->id = id;
		this->city_code = city_code;
		this->city_name = city_name;
	}
};

class AreaInfoAddDO
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
	CC_SYNTHESIZE(string, city_serc, City_serc);
	CC_SYNTHESIZE(string, city_code, City_code);
	CC_SYNTHESIZE(string, city_name, City_name);
	CC_SYNTHESIZE(string, city_type_code, City_type_code);
	CC_SYNTHESIZE(string, barea_code, Barea_code);
	CC_SYNTHESIZE(string, darea_code, Darea_code);
	CC_SYNTHESIZE(string, city_del, City_del);
public:
	AreaInfoAddDO()
	{
		id = "id";
		create_name = "admin";
		create_by = "admin";
		create_date = "2025-2-23";
		city_code = "00";
		city_name = "XX";
		city_serc = "xx";
		city_type_code = "0";
		barea_code = "0";
		darea_code = "0";
		city_del = "N";
		update_name = "update_name";
		update_by = "update_by";
		update_date = "update_date";
		sys_org_code = "sys_org_code";
		sys_company_code = "sys_company_code";
	}
};

#endif // !_AREAINFO_DO_
