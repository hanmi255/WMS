#pragma once
/*
 @Author: laughter
*/
#ifndef _COMPANYATTR_MAPPER_
#define _COMPANYATTR_MAPPER_

#include "Mapper.h"
#include "../../domain/do/companyattr/CompanyattrDO.h"

/**
 * ×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class CompanyattrMapper : public Mapper<CompanyattrDO>
{
public:
	CompanyattrDO mapper(ResultSet* resultSet) const override
	{
		CompanyattrDO data;
		//data.setId(resultSet->getUInt64(1));
		data.setcom_type_Code(resultSet->getString(1));
		data.setcom_type_Name(resultSet->getString(2));
		//data.setAge(resultSet->getInt(4));
		return data;
	}
};

/**
 * ×Ö¶ÎÆ¥ÅäÓ³Éä-´´½¨ÖÇÄÜÖ¸Õë¶ÔÏó
 */
class PtrCompanyattrMapper : public Mapper<PtrCompanyattrDO>
{
public:
	PtrCompanyattrDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<CompanyattrDO>();
		//data->setId(resultSet->getUInt64(1));
		data->setcom_type_Code(resultSet->getString(1));
		data->setcom_type_Name(resultSet->getString(2));
		//data->setAge(resultSet->getInt(4));
		return data;
	}
};

#endif // !_COMPANYATTR_MAPPER_
