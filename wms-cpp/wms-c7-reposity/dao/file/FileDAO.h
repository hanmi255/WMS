#pragma once
/*
 @Author: nanbowan
*/
#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include"../wms-c7-reposity/domain/do/file/FileDO.h"
#include"../wms-c7-reposity/domain/do/ordertypes/OrderTypesDO.h"
#include"FileMapper.h"


/**
 * 表数据库操作实现
 */
class FileDAO : public BaseDAO
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
public:
	// 查询所有数据条数
	uint64_t count();
	// 查询所有数据
	list< FileDO> selectAll();
	// 插入数据
	uint64_t insert(const OrderTypesDO& iObj);
};
#endif // !_SAMPLE_DAO_

