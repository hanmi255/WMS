#ifndef _ONOCC_SERVICE_
#define _ONOCC_SERVICE_

#include <list>
#include "domain/query/onocc/onocc_query.h"
#include "domain/dto/onocc/onocc_dto.h"
#include "domain/vo/onocc/onocc_vo.h"

class EsService
{
public:
	// 分页查询所有数据
	EsPageDTO::Wrapper listAll(const EsQuery::Wrapper& query);
	// 保存数据
	std::string saveData(const EsAddDTO::Wrapper& dto, const PayloadDTO& payload);
	// 修改数据
	bool updateData(const EsDTO::Wrapper& dto,const PayloadDTO& payload);
};

#endif