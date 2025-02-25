#pragma once
#ifndef _BINSERVICE_
#define _BINSERVICE_
#include "domain/dto/keyongchuwei/BinDTO.h"
#include "domain/query/keyongchuwei/BinQuery.h"

class BinService {
public:
	BinPageDTO::Wrapper querylist(const BinPageQuery::Wrapper& query);
	vector<vector<string>> querybyids(const vector<string>& ids);
};

#endif // ! _BINSERVICE_