#pragma once
#ifndef _StoreService_
#define _StoreService_
#include "domain/dto/cangkudingyi/StoreDTO.h"

class StoreService {
public:
	string addStore(const StoreAddDTO::Wrapper dto, const PayloadDTO& payload);
	string modifyStore(const StoreModifyDTO::Wrapper dto, const PayloadDTO& payload);
};

#endif // !_StoreService_
