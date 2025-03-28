#pragma once

#ifndef _PIS_SERVICE_
#define _PIS_SERVICE_
#include <list>
#include "domain/vo/ba_qm_sta/PisVO.h"
#include "domain/query/ba_qm_sta/PisQuery.h"
#include "domain/dto/ba_qm_sta/PisDTO.h"

class PisService
{
public:
	// 分页查询所有数据
	PisPageDTO::Wrapper listAll(const PisQuery::Wrapper& query);
	// 保存数据
	std::string saveData(const PisAddDTO::Wrapper& dto,const PayloadDTO& payload);
	// 修改数据
	bool updateData(const PisDTO::Wrapper& dto, const PayloadDTO& payload);

	// 通过code查询数据
	//PisDTO::Wrapper getByCode(const string& code);
	// 通过sta查询单个数据
	//PisDTO::Wrapper getByName(const string& name);
};

#endif // !_SAMPLE_SERVICE_
