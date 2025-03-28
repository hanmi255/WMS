#ifndef _BAREAINFO_MAPPER_
#define _BAREAINFO_MAPPER_
#include "Mapper.h"
#include "domain/do/districtinfo/districtinfoDO.h"

class BareaNameMapper : public Mapper<BareaNameDO>
{
public:
	BareaNameDO mapper(ResultSet* resultSet) const override
	{
		BareaNameDO data;
		data.setId(resultSet->getString(1));
		data.setBarea_name(resultSet->getString(2));
		return data;
	}
};

class BareaInfoMapper : public Mapper<BareaInfoDO>
{
public:
	BareaInfoDO mapper(ResultSet* resultSet) const override
	{
		BareaInfoDO data;
		data.setId(resultSet->getString(1));
		data.setBarea_code(resultSet->getString(2));
		data.setBarea_name(resultSet->getString(3));
		data.setBarea_rdata(resultSet->getDouble(4));
		return data;
	}
};

class BareaInfoExportMapper : public Mapper<BareaInfoDO>
{
public:
	BareaInfoDO mapper(ResultSet* resultSet) const override
	{
		BareaInfoDO data;
		data.setBarea_code(resultSet->getString(1));
		data.setBarea_name(resultSet->getString(2));
		data.setBarea_rdata(resultSet->getDouble(3));
		return data;
	}
};

#endif // !_BAREAINFO_MAPPER_
