#ifndef _TP_DAO_H_
#define _TP_DAO_H_

#include "BaseDAO.h"
#include "domain/do/TuopanDO.h"
#include "domain/dto/tuopandingyi/AddTPDTO.h"

class TPDAO: public BaseDAO {
public:
	std::list<TuopanDO> queryTP();
	std::string addTP(const TuopanDO &data);
};

#endif // _TP_DAO_H_