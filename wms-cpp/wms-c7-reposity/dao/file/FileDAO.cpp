/*
 @Author: nanbowan
*/
#include "stdafx.h"
#include "FileDAO.h"
#include <sstream>

uint64_t FileDAO::count()
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM ba_order_type ";
	// Ö´ÐÐ²éÑ¯
	return sqlSession->executeQueryNumerical(sql, params);
}

list< FileDO> FileDAO::selectAll()
{
	string sql = "SELECT order_type_code,order_type_name FROM ba_order_type ";
	FileMapper mapper;
	return sqlSession->executeQuery<FileDO>(sql, mapper);
}


uint64_t FileDAO::insert(const OrderTypesDO& iObj)
{
	string sql = "INSERT INTO `ba_order_type` (`id`,`order_type_code`, `order_type_name`) VALUES ( ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s",iObj.getId(), iObj.getCode(), iObj.getName());
}