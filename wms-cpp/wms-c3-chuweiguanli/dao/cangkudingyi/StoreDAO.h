#pragma once
#ifndef STOREDAO
#define STOREDAO
#include "domain/do/StoreDO.h"
#include "BaseDAO.h"
#include "domain/query/cangkudingyi/CangkuListQuery.h"
#include "dao/cangkudingyi/StoreMapper.h"

class StoreDAO : public BaseDAO
{
private:
	inline std::string queryConditionBuilder(const CangkuListQuery::Wrapper& query, SqlParams& params);
public:
	string add(const StoreDO& obj);
	string modify(const StoreDO& obj);
	uint64_t count(const CangkuListQuery::Wrapper& query);
	std::list<StoreDO> selectWithPage(const CangkuListQuery::Wrapper& query);
};

#endif // !STOREDAO
