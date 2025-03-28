#pragma once
/*****************************************************************************
    *  @COPYRIGHT NOTICE
    *  @Copyright (c) 2013, kato1
    *  @All rights reserved
    *  @file	 : AdjustlistDAO.h
    *  @version  : ver 1.0
    *  @author   : kato1
    *  @date     : 2025/2/27 14:44
    *  @brief    : brief
*****************************************************************************/

#ifndef _AdjustlistDAO_
#define _AdjustlistDAO_
#include "BaseDAO.h"
#include "../../domain/do/adjust-list/AdjustlistDO.h"
#include "../../domain/query/adjust-list/ListgoodsQuery.h"

/**
 * 示例表数据库操作实现
 */
class AdjustlistDAO : public BaseDAO
{
private:
	//************************************
	// Method:      queryConditionBuilder
	// FullName:    SampleDAO::queryConditionBuilder
	// Access:      private 
	// Returns:     std::string 返回条件SQL语句，即WHERE部分的语句
	// Parameter:   const SampleQuery::Wrapper& query 查询数据对象
	// Parameter:   SqlParams& params 存放查询数据的参数对象
	// Description: 查询条件构建器，根据SampleQuery对象动态构建查询条件相关参数
	//************************************
	inline std::string queryConditionBuilder(const ListgoodsQuery1::Wrapper& query, SqlParams& params);
public:
	 //统计数据条数
	uint64_t count(const ListgoodsQuery1::Wrapper& query);

	 //通过ID查询数据
	PtrAdjustlistDO selectById(const std::string id);

	 //分页查询数据
	std::list<AdjustlistDO> selectWithPage(const ListgoodsQuery1::Wrapper& query);

	
	 //修改数据
	int update(const AdjustlistDO& uObj, const PayloadDTO& payload);

};
#endif // !_AdjustlistDAO_
