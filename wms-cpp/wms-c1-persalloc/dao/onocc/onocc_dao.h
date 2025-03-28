#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/onocc/onocc_do.h"
#include "../../domain/query/onocc/onocc_query.h"

class EsDAO :public BaseDAO
{
	inline std::string queryConditionBuilder(const EsQuery::Wrapper& query, SqlParams& params);
public:
	uint64_t count(const EsQuery::Wrapper& query);
	std::list<EsDO> selectWithPage(const EsQuery::Wrapper& query);
	std::string insert(const EsDO& iObj);
	int update(const EsDO& uObj);
};

#endif

