#pragma once

#include "domain/dto/chuweidingyi/AddCWDTO.h"

class CwService {
public:
	string addCW(const AddCWDTO::Wrapper dto, const PayloadDTO& payload);
};