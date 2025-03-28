#pragma once

#ifndef _STUCODE_DO_
#define _STUCODE_DO_

#include "./DoInclude.h"

class StuCodeDO
{
	CC_SYNTHESIZE(string, code, Code);
	CC_SYNTHESIZE(string, name, Name);
	CC_SYNTHESIZE(string, id, Id);
public:
	StuCodeDO()
	{
		this->code = "";
		this->name = "";
		this->id = "";
	}
};




#endif // !_STUCODE_DO_
