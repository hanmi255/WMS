#pragma once
#ifndef _BINDAO_
#define _BINDAO_
#include "BaseDAO.h"
#include "domain/do/BinDO.h"
#include "domain/query/keyongchuwei/BinQuery.h"

class BinDAO : public BaseDAO
{
private:
	inline std::string queryConditionBuilder(const BinPageQuery::Wrapper& query, SqlParams& params);
public:
	std::list<BinDO> selectWithPage(const BinPageQuery::Wrapper& query);
	uint64_t count(const BinPageQuery::Wrapper& query);
	std::vector<std::vector<string>> selectByIds(const vector<string>& ids);
};

#endif // !_BINDAO_
