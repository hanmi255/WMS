/*
 @Author: nanbowan
*/
#pragma once

#ifndef _SAMPLE_DAO_
#define _SAMPLE_DAO_
#include "BaseDAO.h"
#include "domain/do/ordertypes/OrderTypesDO.h"
#include "domain/dto/ordertypes/OrderTypesDTO.h"

/**
 * 表数据库操作实现
 */
class OrderTypesDAO : public BaseDAO
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
	// 修改数据
	int update(const OrderTypesDO& uObj);
	// 通过ID删除数据
	int deleteById(string id);
};
#endif // !_SAMPLE_DAO_

