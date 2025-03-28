#pragma once
#include <list>
#include <stdint.h>

//#include "domain/vo/employedstatus/employedVO.h"
//#include "domain/query/employedstatus/employedQuery.h"
#include "domain/dto/employedstatus/EmployedStatusDTO.h"

// 不导入ApiHelper不识别String 不知道为什么
#include "ApiHelper.h"
typedef oatpp::data::mapping::type::String String;
/**
 * 在职状态服务实现
 */
class EmployedService
{
public:

	bool removeData(const EmployedStatusRemoveDTO::Wrapper& dto);
	// 分页查询所有数据
	//SamplePageDTO::Wrapper listAll(const SampleQuery::Wrapper& query);
	// 通过ID查询单个数据
	//SampleDTO::Wrapper getById(uint64_t id);
	// 保存数据
	//uint64_t saveData(const SampleAddDTO::Wrapper& dto);
 


	// 修改数据	// 导入数据
	//bool updateData(const EmployedDTO::Wrapper& dto);
	// 通过ID删除数据

	// 导出在职状态表中的所有数据
	bool exportAllData(string localpath);
	// 导入数据
	bool importAllData(const vector<vector<string>>& ptr_data, const PayloadDTO& payload);
};