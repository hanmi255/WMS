#pragma once
#ifndef _ENTERPRISELEVELSERVICE_
#define _ENTERPRISELEVELSERVICE_
#include <list>
#include "../../domain/vo/enterprise-level/GetEnterpriseLevelNameVO.h"
#include "../../domain/query/enterprise-level/GetEnterPirseLevelNameQuery.h"
#include "../../domain/dto/enterprise-level/GetEnterpriseLevelNameDTO.h"


class EnterpriseLevelService
{
public:
	//获取企业等级名称列表
	EnterpriseLevelNameDTO::Wrapper getEnterpriseLevelName();
};

#endif // !_ENTERPRISELEVELSERVICE_