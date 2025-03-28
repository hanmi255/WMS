#pragma once

#ifndef _STUCODE_DAO_
#define _STUCODE_DAO_

#include "BaseDAO.h"
#include <list>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "domain/vo/stucode/StuCodeVO.h"	
#include "domain/dto/stucode/StuCodeDTO.h"	
#include "domain/dto/stucode/StuCodeDelDTO.h"	
#include "domain/query/stucode/StuCodeQuery.h"
#include "domain/do/StuCodeDO.h"
#include "domain/do/StuCodeMapper.h"
#include "SimpleDateTimeFormat.h"
//#include "id/UuidFacade.h"
#include "id/SnowFlake.h"


class StuCodeDAO :public BaseDAO
{
public:
	list<StuCodeDO> selectStuCodeWithPage(const StuCodeQuery::Wrapper& query);

	uint64_t countCode(const StuCodeQuery::Wrapper& query);

	uint64_t updateStuCode(const StuCodeDTO::Wrapper& dto,const PayloadDTO auth);

	uint64_t insertStuCode(const StuCodeDTO::Wrapper& dto,const PayloadDTO auth);

	uint64_t deleteSexCode(const StuCodeDelDTO::Wrapper& dto);

};



#endif // !_STUCODE_DAO_
