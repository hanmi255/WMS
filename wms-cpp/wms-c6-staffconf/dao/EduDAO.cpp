#include "stdafx.h"
#include "EduDAO.h"
#include "../dao/EduMapper.h"
#include <sstream>

std::string EduDAO::queryConditionBuilder(const EduQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->educode) {

		sqlCondition << " AND `edu_sta_code`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->educode.getValue(""));
	}
	if (query->eduname) {

		sqlCondition << " AND `edu_sta_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->eduname.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t EduDAO::count(const EduQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM ba_edu_sta ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<EducationDO> EduDAO::selectWithPage(const EduQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT id, edu_sta_code, edu_sta_name FROM ba_edu_sta ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	EduMapper mapper;
	return sqlSession->executeQuery<EducationDO>(sql, mapper, params);
}

std::list<EduBaseDO> EduDAO::select()
{
	string sql = "SELECT edu_sta_code, edu_sta_name FROM ba_edu_sta ";
	EduBaseMapper mapper;
	return sqlSession->executeQuery<EduBaseDO>(sql, mapper);
}

#define GET(val) iObj.get##val()
bool EduDAO::insert(const EducationDO& iObj)
{
	string sql = "INSERT INTO `ba_edu_sta` (`id`,`create_name`,`create_by`,`create_date`,`update_name`,`update_by`,`update_date`,`sys_org_code`,`sys_company_code`, `edu_sta_code`, `edu_sta_name`) VALUES (?, ?, ?,?,?,?,?,?,?,?,?)";
	return sqlSession->executeUpdate(sql,"%s%s%s%s%s%s%s%s%s%s%s",GET(Id), GET(Create_name), GET(Create_by), GET(Create_date), GET(Update_name), GET(Update_by), GET(Update_date), GET(Sys_org_code), GET(Sys_company_code), GET(EduCode), GET(EduName)) == 1;
}
#undef GET

void EduDAO::insert(const list<EducationDO>& obj)
{
	for (auto sub : obj)
	{
		insert(sub);
	}
}