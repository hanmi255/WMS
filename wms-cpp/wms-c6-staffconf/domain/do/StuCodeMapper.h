#pragma once

#ifndef _STUCODE_MAPPER_
#define _STUCODE_MAPPER_

#include "Mapper.h"

#include "StuCodeDO.h"


class StuCodeMapper : public Mapper<StuCodeDO>
{
public:
	StuCodeDO mapper(ResultSet* resultSet) const override
	{
		StuCodeDO data;
		data.setName(resultSet->getString(1));
		data.setCode(resultSet->getString(2));
		data.setId(resultSet->getString(3));
		return data;
	}
};



#endif // !_STUCODE_MAPPER_
