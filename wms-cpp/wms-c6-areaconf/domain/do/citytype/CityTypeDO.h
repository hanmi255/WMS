#pragma once
/*
 @Author: 002
 @Date: 2025.3.2
*/
#ifndef _CITY_TYPE_DO_
#define _CITY_TYPE_DO_
#include "../DoInclude.h"

class CityTypeBaseDO
{
	CC_SYNTHESIZE(string, code, Code);
	CC_SYNTHESIZE(string, name, Name);
public:
	CityTypeBaseDO()
	{
		code = "";
		name = "";
	}
};

class CityTypeNameDO
{
	CC_SYNTHESIZE(string, id, Id);
	CC_SYNTHESIZE(string, name, Name);
public:
	CityTypeNameDO() {
		id = "";
		name = "";
	}
};

class CityTypeDO : public CityTypeNameDO
{
	CC_SYNTHESIZE(string, code, Code);
public:
	CityTypeDO() {
		id = "0";
		name = "";
		code = "";
	}
};

class CityTypeUpdDO : public CityTypeDO
{
	CC_SYNTHESIZE(string, uname, Uname);
	CC_SYNTHESIZE(string, uby, Uby);
	CC_SYNTHESIZE(string, udate, Udate);
	CC_SYNTHESIZE(string, orgcode, Orgcode);
	CC_SYNTHESIZE(string, companycode, Companycode);
public:
	CityTypeUpdDO()
	{
		id = "";
		uname = "";
		uby = "";
		udate = "";
		orgcode = "";
		companycode = "";
		code = "";
		name = "";
	}
};

class CityTypeAddDO : public CityTypeUpdDO
{
	CC_SYNTHESIZE(string, cname, Cname);
	CC_SYNTHESIZE(string, cby, Cby);
	CC_SYNTHESIZE(string, cdate, Cdate);
public:
	CityTypeAddDO()
	{
		id = "";
		cname = "";
		cby = "";
		cdate = "";
		uname = "";
		uby = "";
		udate = "";
		orgcode = "";
		companycode = "";
		code = "";
		name = "";
	}
};

#endif // !_CITY_TYPE_DO_
