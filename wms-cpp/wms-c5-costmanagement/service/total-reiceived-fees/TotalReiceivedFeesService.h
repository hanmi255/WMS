#pragma once
#ifndef _TOTAL_REC_
#define _TOTAL_REC_

#include "domain/query/total-reiceived-fees/TotalReiceivedFeesQuery.h"
#include "domain/vo/total-reiceived-fees/TotalReiceivedFeesVO.h"

class TotalReiceivedFeesService {
public:
	TotalReiceivedFeesPageVO::Wrapper listAll(const TotalReiceivedFeesQuery::Wrapper& query);

	vector<vector<string>> exportAll(const TotalReiceivedFeesQuery::Wrapper& query);
};


#endif // !_TOTAL_REC_
