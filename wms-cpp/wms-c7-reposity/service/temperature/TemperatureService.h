#pragma once
/*
 @Author: gutianxuan
*/
#ifndef _TEMPERATURE_SERVICE_
#define _TEMPERATURE_SERVICE_

#include <list>
#include "domain/dto/temperature/TemperatureDTO.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/temperature/TemperatureQuery.h"
#include "domain/vo/temperature/TemperatureVO.h"
/**
 * 服务实现 修改数据、删除数据
 */
class TemperatureService
{
public:

	// 用于excel查询数据
	string queryData();

	// 用于excel插入数据
	bool insertData(string fullpath);

	//新增数据
	uint64_t addData(const TemperatureDetailDTO::Wrapper& dto);

	//修改数据
	bool updateData(const TemperatureDetailDTO::Wrapper& dto);

	// 通过ID删除数据
	bool removeData(string id);


	// 分页查询所有数据
	TemperaturePageDTO::Wrapper listQueryTemperature(const TemperatureQuery::Wrapper& query);

	// 查询温度属性名称列表
	TemperatureNamePageDTO::Wrapper listTemperatureName(const PageQuery::Wrapper& query);
};

#endif // !_TEMPERATURE_SERVICE_
