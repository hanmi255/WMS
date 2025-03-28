#pragma once
#ifndef _BUSSTYPE_SERVICE_
#define _BUSSTYPE_SERVICE_
#include <list>
#include "../../domain/dto/busstype/BussTypeDTO.h"
#include "../../domain/query/busstype/BussTypeQuery.h"
#include "../../domain/vo/busstype/BussTypeVO.h"

class BussTypeService {
public:
	// 分页查询所有数据
	BussTypeListPageDTO::Wrapper listAll(const BussTypeQuery::Wrapper& query);
	// 通过业务类型Name查询单个数据
	BussTypeListPageDTO::Wrapper getByName(string id);
	// 通过业务类型Code查询单个数据
	BussTypeListPageDTO::Wrapper getByCode(string code);
	// 通过业务类型Text查询单个数据
	BussTypeListPageDTO::Wrapper getByText(string text);
	// 保存数据
	uint64_t saveData(const BussTypeAddDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const BussTypeAddDTO::Wrapper& dto);
};
#endif // !_BUSSTYPE_SERVICE_
