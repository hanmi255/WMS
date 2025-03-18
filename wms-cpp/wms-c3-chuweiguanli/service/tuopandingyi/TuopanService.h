#pragma once
#ifndef _TUOPAN_SERVICE_
#define _TUOPAN_SERVICE_
#include <list>
#include "domain/dto/tuopandingyi/TuopanDTO.h"
#include "domain/query/tuopandingyi/TuopanQuery.h"

/**
 * 托盘服务实现
 */
class TuopanService
{
public:
	// 分页查询所有托盘数据
	TuopanPageDTO::Wrapper listAll(const TuopanQuery::Wrapper& query);
	//// 通过ID查询单个数据
	//SampleDTO::Wrapper getById(uint64_t id);
	//// 保存数据
	//uint64_t saveData(const SampleAddDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const TuopanDTO::Wrapper& dto);
	// 批量删除数据
	bool removeData(oatpp::List<oatpp::String>& idlist);
};

#endif // !_TUOPAN_SERVICE_