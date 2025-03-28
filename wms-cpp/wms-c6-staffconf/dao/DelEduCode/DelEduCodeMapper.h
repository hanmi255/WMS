#ifndef _ROLELIST_MAPPER_
#define _ROLELIST_MAPPER_

#include "Mapper.h"
#include"domain/do/education/EduCodeDO.h"
class EduCodeMapper : public Mapper<EduCodeDO>
{
public:
	EduCodeDO mapper(ResultSet* resultSet) const override
	{
		EduCodeDO data;
		data.setEdu_sta_code(resultSet->getString(1));
		data.setEdu_sta_name(resultSet->getString(2));
		return data;
	}
};

#endif // !_ROLELIST_MAPPER_
