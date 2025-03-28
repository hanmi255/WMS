#include "stdafx.h"
#include "EnterpriseLevelDAO.h"
#include "EnterpriseLevelMapper.h"
#include <sstream>


//获取企业等级名称数据
std::list<CustomerLevelDO> EnterpriseLevelDAO::getEnterpriseName()
{
	EnterpriseLevelMapper map;
	/*添加redis*/
	string sql = "SELECT DISTINCT `com_deg_name` FROM `ba_com_deg`";
	return sqlSession->executeQuery<CustomerLevelDO>(sql, map);
}
