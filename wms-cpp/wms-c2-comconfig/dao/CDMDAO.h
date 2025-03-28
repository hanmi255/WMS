#pragma once
#ifndef CDMDAO
#define CDMDAO
#include "domain/do/comdegdm/CdmDO.h"
#include "BaseDAO.h"

class CdmDAO : public BaseDAO
{
public:
   string modify(const CdmDO & obj);
};
#endif 