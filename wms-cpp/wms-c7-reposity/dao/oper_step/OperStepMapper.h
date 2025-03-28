# ifndef _OperStep_MAPPER_
# define _OperStep_MAPPER_
#include "Mapper.h"
#include "domain/do/oper_step/OperStepDO.h"


class OperStepMapper : public Mapper<OperStepDO>
{
public:
	OperStepDO mapper(ResultSet* resultSet) const override
	{
		OperStepDO data;
		data.setCreate_name(resultSet->getString(1));
		data.setCreate_by(resultSet->getString(2));
		data.setCreate_date(resultSet->getString(3));
		data.setUpdate_name(resultSet->getString(4));
		data.setUpdate_by(resultSet->getString(5));
		data.setUpdate_date(resultSet->getString(6));
		data.setSys_org_code(resultSet->getString(7));
        data.setSys_company_code(resultSet->getString(8));
        data.setOper_step_code(resultSet->getString(9));
        data.setOper_step_name(resultSet->getString(10));
		return data;
	}
};


#endif // !_AREAINFO_MAPPER_