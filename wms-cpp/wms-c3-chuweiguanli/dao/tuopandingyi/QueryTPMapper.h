#ifndef _QUERY_TP_MAPPER_H_
#define _QUERY_TP_MAPPER_H_

#include "Mapper.h"
#include "domain/do/TuopanDO.h"

class QueryTPMapper: public Mapper<TuopanDO> {
public:
	TuopanDO mapper(ResultSet* resultSet) const override
	{
		TuopanDO data;
		data.setId(resultSet->getString(1));
		data.setTinId(resultSet->getString(2));
		return data;
	}
};

#endif // _QUERY_TP_MAPPER_H_