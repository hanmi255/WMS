/*
 @Author: nanbowan
*/
#include "stdafx.h"
#include "LibraryDAO.h"

#include <sstream>


int LibraryDAO::update(const LibraryDO& uObj)
{
	string sql = "UPDATE `ba_bin_type` SET `bin_type_code`=?, `bin_type_name`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s", uObj.getCode(), uObj.getName(), uObj.getId());
}

int LibraryDAO::deleteById(string id)
{
	if (id == "0") {
		string sql = "DELETE FROM `ba_bin_type` ";
		sqlSession->executeUpdate(sql);
		return 1;
	}

	string sql = "DELETE FROM `ba_bin_type` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}