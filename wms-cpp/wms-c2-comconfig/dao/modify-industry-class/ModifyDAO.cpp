#include "stdafx.h"
#include "ModifyDAO.h"
#include "ModifyMapper.h"
#include <sstream>


int ModifyDAO::update(const ModifyDO& uObj)
{
	string sql = "UPDATE `ba_classfl` SET `classfl_code`=?, `classfl_name`=?, `classfl_del`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s", uObj.getClassfl_code(), uObj.getClassfl_name(), uObj.getClassfl_del(), uObj.getId());

}
