#include "stdafx.h"
#include "CostTypeDAO.h"
#include "CostTypeMapper.h"
#include <sstream>
#include "../lib-common/include/id/SnowFlake.h"
std::string CostTypeDAO::queryConditionBuilder(const CostTypeQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->cost_code) {

		sqlCondition << " AND `cost_code`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->cost_code.getValue(""));
	}
	if (query->cost_name) {

		sqlCondition << " AND `cost_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->cost_name.getValue(""));
	}
	if (query->cost_type) {

		sqlCondition << " AND `cost_type`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->cost_type.getValue(""));

	}
	if (query->create_name) {

		sqlCondition << " AND `create_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->create_name.getValue(""));
	}
	if (query->create_date) {

		sqlCondition << " AND `create_date`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->create_date.getValue(""));
	}
	if (query->update_name) {

		sqlCondition << " AND `update_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->update_name.getValue(""));
	}
	if (query->update_date) {

		sqlCondition << " AND update_date=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->update_date.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t CostTypeDAO::count(const CostTypeQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM ba_cost_type";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<CostTypeDO> CostTypeDAO::selectWithPage(const CostTypeQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT id,cost_code,cost_name,cost_type,create_name,create_date,update_name,update_date FROM ba_cost_type";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	CostTypeMapper mapper;
	return sqlSession->executeQuery<CostTypeDO>(sql, mapper, params);
}

std::list<CostTypeDO> CostTypeDAO::selectByName(const string& name)
{
	string sql = "SELECT id,cost_code,cost_name,cost_type,create_name，create_date，update_name,update_data FROM ba_cost_type WHERE `cost_name` LIKE CONCAT('%',?,'%')";
	CostTypeMapper mapper;
	return sqlSession->executeQuery<CostTypeDO>(sql, mapper, "%s", name);
}

PtrCostTypeDO CostTypeDAO::selectById(uint64_t id)
{
	string sql = "SELECT id,cost_code,cost_name,cost_type,create_name,create_date,update_name,update_date FROM ba_cost_type WHERE `id`=?";
	PtrCostTypeMapper mapper;
	return sqlSession->executeQueryOne<PtrCostTypeDO>(sql, mapper, "%ull", id);
}

uint64_t CostTypeDAO::insert(const CostTypeDO& iObj)
{
	SnowFlake sf(1, 1);
	
    uint64_t  id = sf.nextId()/100;
	// 完善insert(fangtang新增
	string sql = "INSERT INTO ba_cost_type( id ,cost_code, cost_name, cost_type,create_name,create_date,create_by,cost_type_code,cost_type_name,sys_company_code,sys_org_code) VALUES (?,?,?,?,?,?,?,?,?,?,?)";
	sqlSession->executeInsert(sql, "%ull%s%s%s%s%s%s%s%s%s%s", id, iObj.getCost_code(), iObj.getCost_name(), iObj.getCost_type(), iObj.getCreate_name(), iObj.getCreate_date(),iObj.getCreate_by(), iObj.getCost_code(),iObj.getCost_name(),iObj.getSysCompanyCode(),iObj.getSysOrgCode());
	return id;
}


int CostTypeDAO::update(const CostTypeDO& uObj)
{
	string sql = "UPDATE ba_cost_type SET cost_code =  ?, cost_name= ?, cost_type= ? ,update_name= ? ,update_date= ? WHERE id = ?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%ull", uObj.getCost_code(), uObj.getCost_name(), uObj.getCost_type(), uObj.getUpdate_name(), uObj.getUpdate_date(), uObj.getId());
}

int CostTypeDAO::deleteById(uint64_t id)
{
	string sql = "DELETE FROM `ba_cost_type` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%ull", id);
}