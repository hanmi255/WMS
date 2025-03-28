#pragma once

#ifndef _COST_NAME_DAO_
#define _COST_NAME_DAO_
#include "BaseDAO.h"
#include "../../domain/do/billing-configuration/CostNameDO.h"
#include "../../domain/query/billing-configuration/CostNameQuery.h"
#include<iostream>

/**
 * 费用名称数据访问对象
 */
class CostNameDAO : public BaseDAO
{
private:
	// 查询条件构建器
	inline std::string queryConditionBuilder(const CostNameQuery::Wrapper& query, SqlParams& params);

public:

	// 统计数据条数
	uint64_t count(const CostNameQuery::Wrapper& query);
	//获取全部费用名称
    std::list<CostNameDO> selectAll(const CostNameQuery::Wrapper& query);

	// 分页查询数据
	std::list<CostNameDO> selectWithPage(const CostNameQuery::Wrapper& query);



	// 插入数据
	int insert(const CostNameDO& iObj, const PayloadDTO& payload);

	// 修改数据
	int update(const CostNameDO& uObj, const PayloadDTO& payload);

	
};
#endif // !_COST_NAME_DAO_