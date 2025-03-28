#ifndef _OPERSTEP_SERVICE_
#define _OPERSTEP_SERVICE_
#include "domain/dto/oper_step/OperStepDTO.h"
#include "dao/oper_step/OperStepDAO.h"

class OperStepService
{
public:
	// É¾³ý
	bool deleteData(const OperStepDeleteDTO::Wrapper& dto);
	// ÐÞ¸Ä
	bool modifyData(const OperStepDTO::Wrapper& dto, const PayloadDTO& payload);
	// µ¼Èë
	bool importData(const std::vector<std::vector<std::string>>& vec, const PayloadDTO& payload);

	std::vector<std::vector<std::string>> selectAll();
};

#endif // !_OPERSTEP_SERVICE_
