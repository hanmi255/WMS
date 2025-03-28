#include "stdafx.h"
#include "ActTypeDAO.h"
#include "ActTypeMapper.h"
#include <sstream>

std::list<ActTypeDO> ActTypeDAO::selectWithPage(const ActTypeQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT id,act_type_code,act_type_name,oper_step_code FROM ba_act_type ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	ActTypeMapper mapper;
	return sqlSession->executeQuery<ActTypeDO>(sql, mapper, params);
}

std::string ActTypeDAO::queryConditionBuilder(const ActTypeQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->act_type_code)
    {
        sqlCondition << " AND `act_type_code` = ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->act_type_code.getValue(""));
    }
	if (query->act_type_name)
	{
        sqlCondition << " AND `act_type_name` = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->act_type_name.getValue(""));
	}
	if (query->oper_step_code)
	{
        sqlCondition << " AND `oper_step_code` = ?";
        SQLPARAMS_PUSH(params, "s", std::string, query->oper_step_code.getValue(""));
	}
	return sqlCondition.str();
}


uint64_t ActTypeDAO::insert(const ActTypeDO& iObj)
{
	//string sql = "INSERT INTO `ba_act_type` (`act_type_code`, `act_type_name`, `oper_step_code`) VALUES (?, ?, ?)";
	//return sqlSession->executeUpdate(sql, "%s%s%s", iObj.getActTypeCode(), iObj.getActTypeName(), iObj.getOperStepCode());
    
    //return sqlSession->executeInsert(sql, "%s%s%s", iObj.getActTypeCode(), iObj.getActTypeName(), iObj.getOperStepCode());

	string sql = "INSERT INTO `ba_act_type` (`id`,`create_date` ,`act_type_code`, `act_type_name`, `oper_step_code`, `create_name`, `create_by`, `sys_org_code`, `sys_company_code`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s", iObj.getId(),iObj.getCreateDate(), iObj.getActTypeCode(), iObj.getActTypeName(), iObj.getOperStepCode(), iObj.getCreateName(), iObj.getCreateBy(), iObj.getSysOrgCode(), iObj.getSysCompanyCode());
}

uint64_t ActTypeDAO::count(const ActTypeQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(id) FROM ba_act_type ";
	//string sql = "SELECT COUNT(*) FROM ba_act_type ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}
