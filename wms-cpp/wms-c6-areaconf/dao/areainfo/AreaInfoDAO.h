#ifndef _AREAINFO_DAO_
#define _AREAINFO_DAO_
#include "BaseDAO.h"
#include "domain/do/areainfo/AreaInfoDO.h"
#include "domain/query/areainfo/AreaInfoQuery.h"

class AreaInfoDAO : public BaseDAO
{
public:
	bool delet(const string& id);
	bool update(const AreaInfoUpdDO& uObj);
	bool add(const AreaInfoAddDO& uObj);
	bool insertUplExl(const std::list<AreaInfoAddDO>& iObj);
	std::list<AreaInfoDO> select();
	std::list<AreaInfoListDO> selectList(const AreaInfoQuery::Wrapper& query);
	std::list<AreaNameTreeDO> selectName();
};

#endif