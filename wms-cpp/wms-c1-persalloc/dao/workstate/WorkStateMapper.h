#pragma once
/*
 wangye 2025 02 28
*/
#ifndef _WORKSTATE_MAPPER_
#define _WORKSTATE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/workstate/WorkStateDO.h"

/**
 * ¹¤×÷×´Ì¬±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class WorkStateMapper : public Mapper<WorkStateDO>
{
public:
	WorkStateDO mapper(ResultSet* resultSet) const override
	{
		WorkStateDO data;
		data.setId(resultSet->getString(1));
		data.setCreate_name(resultSet->getString(2));
		data.setCreate_by(resultSet->getString(3));
		data.setCreate_date(resultSet->getString(4));
		data.setUpdate_name(resultSet->getString(5));
		data.setUpdate_by(resultSet->getString(6));
		data.setUpdate_date(resultSet->getString(7));
		data.setSys_org_code(resultSet->getString(8));
		data.setSys_company_code(resultSet->getString(9));
		data.setWork_sta_code(resultSet->getString(10));
		data.setWork_sta_name(resultSet->getString(11));
		return data;
	}
};

class WorkStateMapper2 : public Mapper<WorkStateDO>
{
public:
	WorkStateDO mapper(ResultSet* resultSet) const override
	{
		WorkStateDO data;
		data.setWork_sta_code(resultSet->getString(1));
		data.setWork_sta_name(resultSet->getString(2));
		return data;
	}
};



#endif // !_WORKSTATE_MAPPER_