#pragma once
#ifndef _COST_TYPE__DAO_
#define _COST_TYPE__DAO_
#include "BaseDAO.h"
#include "../../domain/do/CostType/CostTypeDO.h"
#include "../../domain/query/billingtype/CostTypeQuery.h"

/**
 * 示例表数据库操作实现
 */
class CostTypeDAO : public BaseDAO
{
private:
	inline std::string queryConditionBuilder(const CostTypeQuery::Wrapper& query, SqlParams& params);
public:
	// 统计费用类型数据条数
	uint64_t count(const CostTypeQuery::Wrapper& query);
	// 分页查询费用类型数据
	std::list<CostTypeDO> selectWithPage(const CostTypeQuery::Wrapper& query);
	// 通过姓名查询数据
	std::list<CostTypeDO> selectByName(const string& name);
	// 通过ID查询数据
	PtrCostTypeDO selectById(uint64_t id);
	// 插入费用类型数据
	uint64_t insert(const CostTypeDO& iObj);
	// 修改费用类型数据
	int update(const  CostTypeDO& uObj);
	// 通过ID删除费用类型数据
	int deleteById(uint64_t id);
};
#endif // !_COST_TYPE__DAO_
