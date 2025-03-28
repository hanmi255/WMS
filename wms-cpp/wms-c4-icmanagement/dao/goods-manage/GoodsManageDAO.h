#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei
 @Date: 2025/2/26 11:08

*/
#ifndef _GOODS_MANAGE_DAO_
#define _GOODS_MANAGE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/goods-manage/wm_stt_in_goodsDO.h"
#include "../../domain/query/goods-manage/GoodsDiffPostQuery.h"

/**
 * 库存表数据库操作实现
 */
class GoodsManageDAO : public BaseDAO
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
	inline std::string queryConditionBuilder(const GoodsDiffPostQuery::Wrapper& query, SqlParams& params);
public:
	// 统计数据条数
	uint64_t count(const GoodsDiffPostQuery::Wrapper& query);
	// 分页查询数据
	std::list<Wm_Stt_In_GoodsDO> selectWithPage(const GoodsDiffPostQuery::Wrapper& query);
	// 查询数据---不分页
	std::list<Wm_Stt_In_GoodsDO> selectWithConditions(const GoodsDiffPostQuery::Wrapper& query);
	// 通过姓名查询数据
	//std::list<Wm_Stt_In_GoodsDO> selectByName(const string& name);
	// 通过ID查询数据
	PtrWm_Stt_In_GoodsDO selectById(uint64_t id);
	// 插入数据
	uint64_t insert(const Wm_Stt_In_GoodsDO& iObj);
	// 修改数据
	int update(const Wm_Stt_In_GoodsDO& uObj, const PayloadDTO& payload);
	// 通过ID删除数据
	int deleteById(uint64_t id);
};
#endif // !_GOODS_MANAGE_DAO_
