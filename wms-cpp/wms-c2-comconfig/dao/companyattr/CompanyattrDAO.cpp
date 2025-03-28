/*
 @Author: laughter
*/
#include "stdafx.h"
#include "CompanyattrDAO.h"
#include "CompanyattrMapper.h"
#include <sstream>

std::string CompanyattrDAO::queryConditionBuilder(const CompanyattrQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->com_type_code) {

		sqlCondition << " AND `com_type_code`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->com_type_code.getValue(""));
	}
	if (query->com_type_name) {

		sqlCondition << " AND `com_type_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->com_type_name.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t CompanyattrDAO::count(const CompanyattrQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM ba_com_type ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<CompanyattrDO> CompanyattrDAO::selectWithPage(const CompanyattrQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT com_type_code,com_type_name FROM ba_com_type ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	CompanyattrMapper mapper;
	return sqlSession->executeQuery<CompanyattrDO>(sql, mapper, params);
}

uint64_t CompanyattrDAO::insert(const CompanyattrIdDO& iObj)
{
	string sql = "INSERT INTO `ba_com_type` (`id`, `create_name`, `create_by`,`com_type_code`, `com_type_name`, `create_date`, `sys_org_code`, `sys_company_code`) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s", iObj.getId(), iObj.getcreate_Name(), iObj.getcreate_By(),iObj.getcom_type_Code(), iObj.getcom_type_Name(),iObj.getcreate_Date(), iObj.getsys_org_Code(),iObj.getsys_company_Code());
}
int CompanyattrDAO::update(const CompanyattrIdDO& uObj)
{
	string sql = "UPDATE `ba_com_type` SET `com_type_code`=?, `com_type_name`=?, `update_name`=?, `update_by`=?, `update_date`=?, `sys_org_code`=?, `sys_company_code`=? WHERE `id`=?" ;
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s", uObj.getcom_type_Code(), uObj.getcom_type_Name(), uObj.getupdate_Name(), uObj.getupdate_By(), uObj.getupdate_Date(), uObj.getsys_org_Code(), uObj.getsys_company_Code(), uObj.getId());
}