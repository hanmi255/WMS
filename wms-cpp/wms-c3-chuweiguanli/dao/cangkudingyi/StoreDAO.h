#pragma once
#ifndef STOREDAO
#define STOREDAO
#include "domain/do/cangkudingyi/StoreDO.h"
#include "BaseDAO.h"

class StoreDAO : public BaseDAO
{
public:
	string add(const StoreDO& obj);
	string modify(const StoreDO& obj);
};

#endif // !STOREDAO
