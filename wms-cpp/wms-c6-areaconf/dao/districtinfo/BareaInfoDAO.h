#ifndef _BAREAINFO_DAO_
#define _BAREAINFO_DAO_
#include "BaseDAO.h"
#include "domain/query/bareainfo/BareaInfoQuery.h"
#include "domain/do/districtinfo/districtinfoDO.h"

class BareaInfoDAO : public BaseDAO
{
public:
	std::list<BareaInfoDO> exportBareaInfo();
	std::list<BareaNameDO> nameList();
	std::list<BareaInfoDO> infoList(const BareaInfoQuery::Wrapper& query);
};

#endif 