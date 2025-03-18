#pragma once
#ifndef _TUOPAN_MAPPER_
#define _TUOPAN_MAPPER_

#include "Mapper.h"
#include "../../domain/do/TuopanDO.h"

/**
 * ÍĞÅÌ±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class TuopanMapper : public Mapper<TuopanDO>
{
public:
	TuopanDO mapper(ResultSet* resultSet) const override
	{
		TuopanDO data;
		
		//data.setCreateName(resultSet->getString(2));
		//data.setCreateBy(resultSet->getString(3));
		//data.setCreateDate(resultSet->getString(4));
		//data.setUpdateName(resultSet->getString(5));
		//data.setUpdateBy(resultSet->getString(6));
		//data.setUpdateName(resultSet->getString(7));
		data.setTinId(resultSet->getString(1));
		data.setTinSort(resultSet->getString(2));
		data.setBinId(resultSet->getString(3));
		data.setTinStatus(resultSet->getString(4));
		data.setBpmStatus(resultSet->getString(5));	
		data.setSysOrgCode(resultSet->getString(6));
		data.setSysCompanyCode(resultSet->getString(7));
		data.setId(resultSet->getString(8));
		return data;
	}
};


 // ÍĞÅÌ±í×Ö¶ÎÆ¥ÅäÓ³Éä - ´´½¨ÖÇÄÜÖ¸Õë¶ÔÏó 
class PtrTuopanMapper : public Mapper<PtrTuopanDO>
{
public:
	PtrTuopanDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<TuopanDO>();
		
		//data->setCreateName(resultSet->getString(2));
		//data->setCreateBy(resultSet->getString(3));
		//data->setCreateDate(resultSet->getString(4));
		//data->setUpdateName(resultSet->getString(5));
		//data->setUpdateBy(resultSet->getString(6));
		//data->setUpdateName(resultSet->getString(7));
		data->setTinId(resultSet->getString(1));
		data->setTinSort(resultSet->getString(2));
		data->setBinId(resultSet->getString(3));
		data->setTinStatus(resultSet->getString(4));
		data->setBpmStatus(resultSet->getString(5));		
		data->setSysOrgCode(resultSet->getString(6));
		data->setSysCompanyCode(resultSet->getString(7));
		data->setId(resultSet->getString(8));
		return data;
	}
};

#endif // !_TUOPAN_MAPPER_