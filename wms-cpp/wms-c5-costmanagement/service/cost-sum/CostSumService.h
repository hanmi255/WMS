#pragma once
#ifndef _COSTSUM_SERVICE_
#define _COSTSUM_SERVICE_
#include  "../../domain/dto/cost-sum-dto/CostSumDTO.h"
#include "../../domain/query/cost-sum-query/CostSumQuery.h"
#include "../../domain/do/CostSumDO.h"
class CostSumService {
public:
	CostSumPageDTO::Wrapper listall(const CostSumQuery::Wrapper& query); 
	list<CostSumDO> exportdata(const CostSumQuery::Wrapper& query);
};
#endif