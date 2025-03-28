#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei
 @Date: 2025/3/4 11:08

*/
#ifndef _LIST_GOODS_DAO_
#define _LIST_GOODS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/adjust-list/wm_to_up_goodsDO.h"
#include "../../domain/query/adjust-list/ListgoodsQuery.h"

/**
 * 库存表数据库操作实现
 */
class ListGoodsDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    ListGoodsDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const ListgoodsQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据ListgoodsQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const ExportDataQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const ExportDataQuery::Wrapper& query);
	// 分页查询数据
	std::list<Wm_To_Up_GoodsDO> selectWithPage(const ExportDataQuery::Wrapper& query);
	// 查询数据---不分页
	std::list<Wm_To_Up_GoodsDO> selectWithConditions(const ExportDataQuery::Wrapper& query);
};
#endif // !_LIST_GOODS_DAO_
