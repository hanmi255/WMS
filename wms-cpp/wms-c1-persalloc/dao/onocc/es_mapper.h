#ifndef _ONOCC_MAPPER_
#define _ONOCC_MAPPER_

#include "Mapper.h"
#include "../../domain/do/onocc/onocc_do.h"



class EsMapper : public Mapper<EsDO>
{
public:
	EsDO mapper(ResultSet* resultSet) const override
	{
		EsDO data;
		data.setId(resultSet->getString(1));
		data.setPos_Sta_Code(resultSet->getString(2));
		data.setPos_Sta_Name(resultSet->getString(3));
		return data;
	}
};

class PtrEsMapper : public Mapper<PtrEsDO>
{
public:
	PtrEsDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<EsDO>();
		data->setId(resultSet->getString(1));
		data->setPos_Sta_Code(resultSet->getString(2));
		data->setPos_Sta_Name(resultSet->getString(3));
		return data;
	}
};
#endif