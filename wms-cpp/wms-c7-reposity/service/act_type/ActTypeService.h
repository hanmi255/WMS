#pragma once
#ifndef _ActTypeService_H_
#define _ActTypeService_H_
#include <list>
#include "../../domain/vo/act_type/ActTypeVo.h"
#include "../../domain/query/act_type/ActTypeQuery.h"
#include "../../domain/dto/act_type/ActTypeDTO.h"

class ActTypeService 
{
public:
	// 分页查询所有数据
	ActTypePageDTO::Wrapper listAll(const ActTypeQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const ActTypeBaseDTO::Wrapper& dto, const PayloadDTO& payload);
};

#endif // !_ActTypeService_H_
