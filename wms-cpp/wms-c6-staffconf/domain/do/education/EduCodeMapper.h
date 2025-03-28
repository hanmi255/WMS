#pragma once
#ifndef _EDUCODE_MAPPER_
#define _EDUCODE_MAPPER_

#include "Mapper.h"
#include"domain/do/education/EducationDO.h"

/**
 * ÐÔ±ð±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class EduMapper : public Mapper<EducationDO>
{
public:
	EducationDO mapper(ResultSet* resultSet) const override
	{
		EducationDO data;
		data.setId(resultSet->getString(1));
		data.setEduCode(resultSet->getString(2));
		data.setEduName(resultSet->getString(3));
		return data;
	}
};


#endif // !_EDUCODE_MAPPER_