#ifndef _DAREAINFO_DAO_
#define _DAREAINFO_DAO_
#include "BaseDAO.h"
#include "domain/query/dareainfo/DareaInfoQuery.h"
#include "DareaInfoMapper.h"
#include "domain/do/regioninfo/DareaInfoDO.h"

class DareaInfoDAO : public BaseDAO
{
public:
	std::list<DareaInfoDO> select(const DareaInfoQuery::Wrapper& query);
	std::list<DareaInfoExportDO> select();
	bool insert(const DareaInfoAddDO& iObj);
	void insert(const list<DareaInfoAddDO>& iObj);
	bool update(const DareaInfoUpdDO& iObj);
	bool delet(const string& area_code);
};

#endif // !_DAREAINFO_DAO_
