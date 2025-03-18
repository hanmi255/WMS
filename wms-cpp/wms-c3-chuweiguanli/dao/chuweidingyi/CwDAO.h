#pragma once

#include "domain/do/BinDO.h"
#include "BaseDAO.h"

class CwDAO : public BaseDAO
{
public:
	string add(const BinDO& obj);
};


