/*
 @Author: nanbowan
*/
#include "stdafx.h"
#include "OrderTypesDAO.h"

#include <sstream>


int OrderTypesDAO::update(const OrderTypesDO& uObj)
{
	string sql = "UPDATE `ba_order_type` SET `order_type_code`=?, `order_type_name`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s", uObj.getCode(), uObj.getName(), uObj.getId());
}

int OrderTypesDAO::deleteById(string id)
{
	if (id == "0") {
		string sql = "DELETE FROM `ba_order_type` ";
		sqlSession->executeUpdate(sql);
		return 1;
	}

	string sql = "DELETE FROM `ba_order_type` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}