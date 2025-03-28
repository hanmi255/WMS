#include "BusinessLinkDAO.h"
#include "BusinessLinkMapper.h"
#include "../../domain/do/bussiness-link/BusinessLinkDO.h"


std::string BusinessLinkDAO::queryConditionBuilder(const BusinessLinkQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->create_name) {

		sqlCondition << " AND create_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->create_name.getValue(""));
	}
	if (query->create_by) {

		sqlCondition << " AND create_by=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->create_by.getValue(""));
	}
	if (query->create_date) {

		sqlCondition << " AND create_date=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->create_date.getValue(""));
	}
	if (query->update_name) {

		sqlCondition << " AND update_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->update_name.getValue(""));
	}
	if (query->update_by) {

		sqlCondition << " AND update_by=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->update_by.getValue(""));
	}
	if (query->update_date) {

		sqlCondition << " AND update_date=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->update_date.getValue(""));
	}
	if (query->sys_org_code) {

		sqlCondition << " AND sys_org_code=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->sys_org_code.getValue(""));
	}
	if (query->sys_company_code) {

		sqlCondition << " AND sys_company_code=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->sys_company_code.getValue(""));
	}
	if (query->oper_step_code) {

		sqlCondition << " AND oper_step_code=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->oper_step_code.getValue(""));
	}
	if (query->oper_step_name) {

		sqlCondition << " AND oper_step_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->oper_step_name.getValue(""));
	}
	return sqlCondition.str();
}

std::list<BusinessLinkNameDO> BusinessLinkDAO::selectAllName()
{
	std::string sql = "select DISTINCT oper_step_name from ba_oper_step";
	BusinessLinkNameMapper mapper;

	return sqlSession->executeQuery<BusinessLinkNameDO>(sql, mapper);
}

std::list<BusinessLinkDO> BusinessLinkDAO::selectWithPage(const BusinessLinkQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT * FROM ba_oper_step ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	BusinessLinkMapper mapper;
	return sqlSession->executeQuery<BusinessLinkDO>(sql, mapper, params);
}

uint64_t BusinessLinkDAO::insert(const BusinessLinkDO& iObj)
{
	string sql = "INSERT INTO `ba_oper_step` (`id`, `create_name`, `create_by`, `create_date`, `sys_org_code`, `sys_company_code`, `oper_step_code`, `oper_step_name`) VALUES (?,?,?,NOW(),?,?,?,?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s", iObj.getId(), iObj.getCreateName(), iObj.getCreateBy(), iObj.getSysOrgCode(), iObj.getSysCompanyCode(), iObj.getOperStepCode(), iObj.getOperStepName());
}

uint64_t BusinessLinkDAO::count(const BusinessLinkQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM ba_oper_step ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}
