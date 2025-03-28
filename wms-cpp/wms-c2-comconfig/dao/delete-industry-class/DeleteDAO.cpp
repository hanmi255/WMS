#include "stdafx.h"
#include "DeleteDAO.h"
#include <sstream>


int DeleteDAO::deleteById(vector<string>& ids)
{
	string sql = "DELETE FROM `ba_classfl` WHERE `id`=?";
	for (auto id : ids)
	{
		int res = sqlSession->executeUpdate(sql, "%s", id);

		if (res != 1) {
			return res;
		}
	}
	return 1;
	
}

