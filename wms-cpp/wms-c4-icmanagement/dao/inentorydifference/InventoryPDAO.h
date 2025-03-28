#pragma once
#ifndef _INVENTORYP_DAO_
#define _INVENTORYP_DAO_
#include "BaseDAO.h"
#include "../../domain/do/inentorydifference/InventoryPDO.h"
#include "../../domain/query/inentorydifference/InventoryPquery.h"

/**
 * 示例表数据库操作实现
 */
class InventoryPDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    InventoryPDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const InventoryPQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据InventoryPQuery对象动态构建查询条 件相关参数
	//************************************
	inline std::string queryConditionBuilder(const InventoryPquery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const InventoryPquery::Wrapper& query);
	// 分页查询数据
	std::list<InventoryPDO> selectWithPage(const InventoryPquery::Wrapper& query);
	// 插入数据
	uint64_t insert(const InventoryPDO& iObj);
};
#endif // !_INVENTORYP_DAO_
