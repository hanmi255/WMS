#pragma once
#ifndef _INVENTORY_LIST_DAO_
#define _INVENTORY_LIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/overallInventory/InventorylistDo.h"
#include "../../domain/query/overallInventory/InventorylistQuery.h"
/**
 * 库存表数据库操作实现
 */
class InventorylistDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    GoodsManageDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const GoodsDiffPostQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据GoodsDiffPostQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const InventorylistQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const InventorylistQuery::Wrapper& query);
	// 分页查询数据
	std::list<InventorylistDo> selectWithPage(const InventorylistQuery::Wrapper& query);
	// 查询数据---不分页
	std::list<InventorylistDo> selectWithConditions(const InventorylistQuery::Wrapper& query);
	// 通过姓名查询数据
	//std::list<InventorylistDo> selectByName(const string& name);
	// 通过ID查询数据
	PtrInventorylistDo selectById(uint64_t id);
	// 插入数据
	uint64_t insert(const InventorylistDo& iObj);
	// 修改数据
	int update(const InventorylistDo& uObj);
	// 通过ID删除数据
	//int deleteById(uint64_t id);
};
#endif // !_GOODS_MANAGE_DAO_
