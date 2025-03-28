#ifndef _AREAINFO_MAPPER_
#define _AREAINFO_MAPPER_
#include "Mapper.h"
#include "domain/do/areainfo/AreaInfoDO.h"

class AreaInfoMapper : public Mapper<AreaInfoDO>
{
public:
	AreaInfoDO mapper(ResultSet* resultSet) const override
	{
		AreaInfoDO data;
		data.setCity_code(resultSet->getString(1));
		data.setCity_name(resultSet->getString(2));
		data.setCity_serc(resultSet->getString(3));
		data.setCity_type_name(resultSet->getString(4));
		data.setBarea_name(resultSet->getString(5));
		data.setDarea_name(resultSet->getString(6));
		data.setCity_del(resultSet->getString(7));
		return data;
	}
};

class AreaInfoListMapper : public Mapper<AreaInfoListDO>
{
public:
	AreaInfoListDO mapper(ResultSet* resultSet) const override
	{
		AreaInfoListDO data;
		data.setId(resultSet->getString(1));
		data.setCity_code(resultSet->getString(2));
		data.setCity_name(resultSet->getString(3));
		data.setCity_serc(resultSet->getString(4));
		data.setCity_type_name(resultSet->getString(5));
		data.setBarea_name(resultSet->getString(6));
		data.setDarea_name(resultSet->getString(7));
		data.setCity_del(resultSet->getString(8));
		return data;
	}
};

class AreaNameTreeMapper : public Mapper<AreaNameTreeDO>
{
public:
	AreaNameTreeDO mapper(ResultSet* resultSet) const override
	{
		AreaNameTreeDO data;
		data.setId(resultSet->getString(1));
		data.setCity_code(resultSet->getString(2));
		data.setCity_name(resultSet->getString(3));
		return data;
	}
};

#endif // !_AREAINFO_MAPPER_
