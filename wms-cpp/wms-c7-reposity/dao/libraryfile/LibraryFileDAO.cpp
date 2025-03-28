/*
 @Author: nanbowan
*/
#include "stdafx.h"
#include "LibraryFileDAO.h"
#include <sstream>

uint64_t LibraryFileDAO::count()
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM ba_bin_type ";
	// Ö´ÐÐ²éÑ¯
	return sqlSession->executeQueryNumerical(sql, params);
}

list< LibraryFileDO> LibraryFileDAO::selectAll()
{
	string sql = "SELECT bin_type_code,bin_type_name FROM ba_bin_type ";
	LibraryFileMapper mapper;
	return sqlSession->executeQuery<LibraryFileDO>(sql, mapper);
}


uint64_t LibraryFileDAO::insert(const LibraryDO& iObj)
{
	string sql = "INSERT INTO `ba_bin_type` (`id`,`bin_type_code`, `bin_type_name`) VALUES ( ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s", iObj.getId(), iObj.getCode(), iObj.getName());
}