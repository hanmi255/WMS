#pragma once
#ifndef _StoreService_
#define _StoreService_
#include "domain/dto/cangkudingyi/StoreDTO.h"
#include "domain/dto/cangkudingyi/CangkuListDTO.h"
#include "domain/query/cangkudingyi/CangkuListQuery.h"

class StoreService {
public:
	string addStore(const StoreAddDTO::Wrapper dto, const PayloadDTO& payload);
	string modifyStore(const StoreModifyDTO::Wrapper dto, const PayloadDTO& payload);
	CangkuListPageDTO::Wrapper listAll(const CangkuListQuery::Wrapper& query);
};

#endif // !_StoreService_
