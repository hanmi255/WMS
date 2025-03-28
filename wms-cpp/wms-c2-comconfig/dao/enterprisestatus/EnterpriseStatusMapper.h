#pragma once
#ifndef _ENTERPRISESTATUSMAPPER_
#define _ENTERPRISESTATUSMAPPER_

#include "Mapper.h"
#include "../../domain/do/enterprisestatus/EnterpriseStatusDO.h"

/**
 * 示例表字段匹配映射
 */
class EnterpriseStatusMapper : public Mapper<EnterpriseStatusDO>
{
public:
	EnterpriseStatusDO mapper(ResultSet* resultSet) const override
	{
		EnterpriseStatusDO data;
		data.setkehuzhuangtai_code(resultSet->getString(1));
		data.setkehuzhuangtai_name(resultSet->getString(2));
		data.setcus_sta_del(resultSet->getString(3));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrEnterpriseStatusMapper : public Mapper<PtrEnterpriseStatusDO>
{
public:
	PtrEnterpriseStatusDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<EnterpriseStatusDO>();
	    data->setkehuzhuangtai_code(resultSet->getString(1));
		data->setkehuzhuangtai_name(resultSet->getString(2));
		data->setcus_sta_del(resultSet->getString(3));
		return data;
	}
};


class EnterpriseStatusListMapper : public Mapper<EnterpriseStatusListDO>
{
public:
	EnterpriseStatusListDO mapper(ResultSet* resultSet) const override
	{
		EnterpriseStatusListDO data;
		data.setid(resultSet->getString(1));
		data.setkehuzhuangtai_code(resultSet->getString(2));
		data.setkehuzhuangtai_name(resultSet->getString(3));
		return data;
	}
};
class PtrEnterpriseStatusListMapper : public Mapper<PtrEnterpriseStatusListDO>
{
public:
	PtrEnterpriseStatusListDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<EnterpriseStatusListDO>();
		data->setid(resultSet->getString(1));
		data->setkehuzhuangtai_code(resultSet->getString(2));
		data->setkehuzhuangtai_name(resultSet->getString(3));
		return data;
	}
};

#endif // !_ENTERPRISESTATUSMAPPER_