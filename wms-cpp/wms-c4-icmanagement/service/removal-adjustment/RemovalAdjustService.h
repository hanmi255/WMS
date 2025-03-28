#pragma once
#ifndef _REMOVAL_SERVICE_
#define _REMOVAL_SERVICE_
#include <list>
//#include "domain/vo/sample/SampleVO.h"
#include "../../domain/vo/removal-adjustment/RemovalVO.h"
//#include "domain/query/sample/SampleQuery.h"
#include "../../domain/query/removal-adjustment/RemovalQuery.h"
//#include "domain/dto/sample/SampleDTO.h"
#include "../../domain/dto/removal-adjustment/RemovalDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class RemovalService
{
public:
	// 分页查询所有数据
	RemovalPageDTO::Wrapper listAll(const RemovalQuery::Wrapper& query);
	// 通过ID查询单个数据
	RemovalDetailDTO::Wrapper getById(const oatpp::String& id);
	RemovalDetailPageDTO::Wrapper getdetail(const RemovalQuery::Wrapper& query);
	//通过字符ID查询详细数据
	//RemovalDetailDTO::Wrapper getbyorder_id(const RemovalQuery::Wrapper& query);
	// 保存数据
	//uint64_t saveData(const SampleAddDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const RemovalListDTO::Wrapper& dto);
	// 通过ID删除数据
	//bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_