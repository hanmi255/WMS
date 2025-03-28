/*
wangye 2025 02 28
*/
#include "stdafx.h"
#include "WorkStateDAO.h"
#include "WorkStateMapper.h"
#include <sstream>


int WorkStateDAO::deleteById(string id)
{
	string sql = "DELETE FROM `ba_work_sta` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);

}

std::list<WorkStateDO> WorkStateDAO::selectAll()
{
	string sql = "SELECT * FROM ba_work_sta";
	WorkStateMapper mapper;
	return sqlSession->executeQuery<WorkStateDO>(sql, mapper);
}

std::list<WorkStateDO> WorkStateDAO::selectWork()
{
	string sql = "select work_sta_code,work_sta_name from ba_work_sta";
	WorkStateMapper2 mapper;
	return sqlSession->executeQuery<WorkStateDO>(sql, mapper);
}

static int queryExsit(string t) {
	SqlSession sqlSession;
	string sql = "SELECT EXISTS (SELECT 1 FROM ba_work_sta WHERE work_sta_code = ?) AS exists_flag";
	return sqlSession.executeQueryNumerical(sql, "%s", t);
}

int WorkStateDAO::insert(WorkStateDO tmp)
{
	if (queryExsit(tmp.getWork_sta_code()) == 1) {
		string sql = "UPDATE `ba_work_sta` SET `id`=?, `update_name`=?, `update_by`=?,`update_date`=CURRENT_TIMESTAMP ,`work_sta_code`=?, \
			`work_sta_name`=? WHERE `work_sta_code`=?";
		return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s", \
			tmp.getId(),tmp.getCreate_name(), tmp.getCreate_by(), tmp.getWork_sta_code(), tmp.getWork_sta_name(),tmp.getWork_sta_code()
		);
	}
	else if (queryExsit(tmp.getWork_sta_code()) == 0) {
		string sql = "INSERT INTO `ba_work_sta` (`id`,`create_name`, `create_by`,`create_date`,`sys_org_code` ,`sys_company_code`,`work_sta_code`,`work_sta_name`) VALUES (?, ?, ?, CURRENT_TIMESTAMP,?,?, ?, ?)";
		return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s", \
			tmp.getId(),tmp.getCreate_name(), tmp.getCreate_by(), tmp.getSys_org_code(), tmp.getSys_company_code(), tmp.getWork_sta_code(), tmp.getWork_sta_name()
		);
	}
	else {
		return -1;
	}
}
