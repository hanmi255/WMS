#ifndef _DAREAINFO_SERVICE_
#define _DAREAINFO_SERVICE_
#include "domain/dto/regioninfo/DareaInfoDTO.h"
#include "dao/regioninfo/DareaInfoDAO.h"
#include "domain/query/dareainfo/DareaInfoQuery.h"

class DareaInfoService
{
public:
	DareaInfoPageDTO::Wrapper listAll(const DareaInfoQuery::Wrapper& query);
	string AddOne(const DareaInfoAddDTO::Wrapper& dto, const PayloadDTO& payload);
	bool Update(const DareaInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	bool Delete(const string& area_code);
	std::vector<std::vector<std::string>> Export();
	void Import(std::vector<std::vector<std::string>> vec, const PayloadDTO& payload);
};

#endif // !_DAREAINFO_SERVICE_
