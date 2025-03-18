#ifndef _TP_SERVIICE_H_
#define _TP_SERVIICE_H_

#include "domain/dto/tuopandingyi/QueryTPDTO.h"
#include "domain/dto/tuopandingyi/AddTPDTO.h"
#include <string>

class TPService {
public:
	oatpp::List<QueryTPDTO::Wrapper> queryTP();
	std::string addTP(const AddTPDTO::Wrapper &dto, const PayloadDTO& payload);
};

#endif
