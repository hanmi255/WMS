#pragma once
#ifndef _CDMService_
#define _CDMService_
#include "domain/dto/CDMattr/CDMDTO.h"
class CDMService {
public:

	string modifyCDM(const CDMListDTO::Wrapper dto, const PayloadDTO& payload);
};
#endif 