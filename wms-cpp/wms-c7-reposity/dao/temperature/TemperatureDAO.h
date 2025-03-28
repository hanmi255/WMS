/*
 @Author: gutianxuan
*/
#pragma once

#ifndef _TEMPERATURE_DAO_
#define _TEMPERATURE_DAO_
#include "BaseDAO.h"
#include "domain/do/temperature/TemperatureDO.h"
#include "domain/dto/temperature/TemperatureDTO.h"
#include "TemperatureMapper.h"
#include "domain/query/temperature/TemperatureQuery.h"

/**
 * 表数据库操作实现
 */
class TemperatureDAO : public BaseDAO
{
private:

public:
	// 修改数据
	int update(const TemperatureDO& uObj);

	// 通过ID删除数据
	int deleteById(string id);

	//和excel相关的
	// 查询所有数据条数

	uint64_t count();
	// 查询所有数据
	list<TemperatureDO> selectAll();
	// 插入数据
	uint64_t insert(const TemperatureDO& iObj);


	// 构建查询条件
	inline std::string queryConditionBuilder(const TemperatureQuery::Wrapper& query, SqlParams& params);

	// 分页查询数据
	std::list<TemperatureDO> selectWithPage(const TemperatureQuery::Wrapper& query);

	// 查询温度属性名称列表
	std::list<TemperatureNameDO> selectTemperatureNameList();

};





#endif // !_TEMPERATURE_DAO_

