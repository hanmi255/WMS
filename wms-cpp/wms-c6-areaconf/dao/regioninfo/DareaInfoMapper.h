#ifndef _DAREAINFO_MAPPER_
#define _DAREAINFO_MAPPER_
#include "Mapper.h"
#include "domain/do/regioninfo/DareaInfoDO.h"

class DareaInfoMapper : public Mapper<DareaInfoDO>
{
public:
	DareaInfoDO mapper(ResultSet* resultSet) const override
	{
		DareaInfoDO data;
		data.setId(resultSet->getString(1));
		data.setArea_code(resultSet->getString(2));
		data.setArea_name(resultSet->getString(3));
		return data;
	}
};

class DareaInfoExportMapper : public Mapper<DareaInfoExportDO>
{
public:
	DareaInfoExportDO mapper(ResultSet* resultSet) const override
	{
		DareaInfoExportDO data;
		data.setArea_code(resultSet->getString(1));
		data.setArea_name(resultSet->getString(2));
		return data;
	}
};

#endif // !_DAREAINFO_MAPPER_
