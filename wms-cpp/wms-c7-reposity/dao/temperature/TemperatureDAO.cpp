/*
 @Author: gutianxuan
*/
#include "stdafx.h"
#include "TemperatureDAO.h"

#include <sstream>


int TemperatureDAO::update(const TemperatureDO& uObj)
{
	string sql = "UPDATE `ba_deg_type` SET`create_name`=?,`create_by`=?,`create_date`=?,`update_name`=?,`update_by`=?,`update_date`=?,`sys_org_code`=?,`sys_company_code`=?, `deg_type_code`=?, `deg_type_name`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s", uObj.getCreate_Name(), uObj.getCreate_By(), uObj.getCreate_Date(), uObj.getUpdate_Name(), uObj.getUpdate_By(), uObj.getUpdate_Date(), uObj.getSys_Org_Code(), uObj.getSys_Company_Code(), uObj.getDeg_Type_Code(), uObj.getDeg_Type_Name());
}

int TemperatureDAO::deleteById(string id)
{
	if (id == "0") {
		string sql = "DELETE FROM `ba_deg_type` ";
		sqlSession->executeUpdate(sql);
		return 1;
	}

	string sql = "DELETE FROM `ba_deg_type` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}

uint64_t TemperatureDAO::count()
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM ba_deg_type ";
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

list<TemperatureDO> TemperatureDAO::selectAll()
{
	string sql = "SELECT * FROM ba_deg_type ";
	TemperatureDetailMapper mapper;
	return sqlSession->executeQuery<TemperatureDO>(sql, mapper);
}


uint64_t TemperatureDAO::insert(const TemperatureDO& iObj)
{
	string sql = "INSERT INTO `ba_deg_type` (`id`,`create_name`,`create_by`,`create_date`,`update_name`,`update_by`,`update_date`,`sys_org_code`,`sys_company_code`, `deg_type_code`, `deg_type_name`) VALUES ( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s", iObj.getId(), iObj.getCreate_Name(), iObj.getCreate_By(), iObj.getCreate_Date(), iObj.getUpdate_Name(), iObj.getUpdate_By(), iObj.getUpdate_Date(), iObj.getSys_Org_Code(), iObj.getSys_Company_Code(), iObj.getDeg_Type_Code(), iObj.getDeg_Type_Name());
}

inline std::string TemperatureDAO::queryConditionBuilder(const TemperatureQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->deg_type_code)
	{
		sqlCondition << " AND deg_type_code = ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->deg_type_code.getValue(""));
	}
	if (query->deg_type_name)
	{
		sqlCondition << " AND deg_type_name = ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->deg_type_name.getValue(""));
	}
	return sqlCondition.str();
}

std::list<TemperatureDO> TemperatureDAO::selectWithPage(const TemperatureQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT id,deg_type_code,deg_type_name FROM ba_deg_type ";
	sql += queryConditionBuilder(query, params);
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	TemperatureMapper mapper;
	return sqlSession->executeQuery<TemperatureDO>(sql, mapper, params);
}

std::list<TemperatureNameDO> TemperatureDAO::selectTemperatureNameList()
{
	SqlParams params;
	string sql = "SELECT id,deg_type_name FROM ba_deg_type ";
	TemperatureNameMapper mapper;
	return sqlSession->executeQuery<TemperatureNameDO>(sql, mapper, params);
}
