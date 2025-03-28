#ifndef _BAREAINFO_SERVICE_
#define _BAREAINFO_SERVICE_
#include "domain/do/districtinfo/districtinfoDO.h"
#include "domain/dto/districtinfo/BareaInfoDTO.h"
#include "domain/query/bareainfo/BareaInfoQuery.h"

class BareaInfoService
{
public:
	BareaInfoPageDTO::Wrapper list(const BareaInfoQuery::Wrapper& query);
};

#endif // !_BAREAINFO_SERVICE_
