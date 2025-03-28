#pragma once
#ifndef _METHOD_SERVICE_
#define _METHOD_SERVICE_
#include <list>
#include "../../domain/do/cost-way/CostwayDO.h"
#include "../../dao/costmethod/MethodDAO.h"
#include "../../domain/vo/costmethod/MethodVO.h"
#include "../../domain/query/costmethod/BillMethodQuery.h"
#include "../../domain/dto/costmethod/MethodDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class MethodService
{
public:
	// 分页查询所有数据
	 MethodPageDTO::Wrapper listAll(const BillmethodQuery::Wrapper& query);
	// 通过ID查询单个数据
	//SampleDTO::Wrapper getById(uint64_t id);
	// 保存数据
	string addData(const MethodAddDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const MethodDTO::Wrapper& dto);

	MethodPageDTO::Wrapper qall(const BillmethodQueryomit::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_

