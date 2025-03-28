#include "stdafx.h"
#include "DareaInfoDAO.h"
#include "DareaInfoMapper.h"

std::list<DareaInfoDO> DareaInfoDAO::select(const DareaInfoQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT id,area_code,area_name FROM `ba_area`";
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->area_code)
	{
		sqlCondition << " AND `area_code`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->area_code.getValue(""));
	}
	if (query->area_name)
	{
		sqlCondition << " AND `area_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->area_name.getValue(""));
	}
	sql += sqlCondition.str();
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	DareaInfoMapper mapper;
	return sqlSession->executeQuery<DareaInfoDO>(sql, mapper, params);
}

bool DareaInfoDAO::insert(const DareaInfoAddDO& iObj)
{
	std::string sql = "INSERT INTO `ba_area` (`id`,`create_name`,`create_by`,`create_date`,`update_name`,`update_by`,`update_date`,`sys_org_code`,`sys_company_code`,`area_code`,`area_name`) VALUES (?,?,?,?,?,?,?,?,?,?,?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s",iObj.getId(),iObj.getCreate_name(),iObj.getCreate_by(),iObj.getCreate_date(), iObj.getUpdate_name(), iObj.getUpdate_by(), iObj.getUpdate_date(), iObj.getSys_org_code(),iObj.getSys_company_code(), iObj.getArea_code(), iObj.getArea_name()) == 1;
}

void DareaInfoDAO::insert(const list<DareaInfoAddDO>& Obj)
{
	for (auto iObj : Obj)
	{
		insert(iObj);
	}
}

#define GET(val) iObj.get##val()
bool DareaInfoDAO::update(const DareaInfoUpdDO& iObj)
{
	std::string sql = "UPDATE `ba_area` SET `update_name`=?,`update_by`=?,`update_date`=?,`area_code`=?,`area_name`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s", GET(Update_name), GET(Update_by), GET(Update_date), GET(Area_code), GET(Area_name), GET(Id)) == 1;
}
#undef GET

bool DareaInfoDAO::delet(const string& id)
{
	std::string sql = "DELETE FROM `ba_area` WHERE `id`=?";
	return sqlSession->executeUpdate(sql,"%s", id) == 1;
}

std::list<DareaInfoExportDO> DareaInfoDAO::select()
{
	string sql = "SELECT area_code,area_name FROM `ba_area`";
	DareaInfoExportMapper mapper;
	return sqlSession->executeQuery<DareaInfoExportDO>(sql, mapper);
}