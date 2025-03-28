#include "stdafx.h"
#include "OperStepDAO.h"
#include "OperStepMapper.h"

bool OperStepDAO::del(const OperStepDO& dObj)
{
	std::string id = dObj.getId();
	std::string sql = "DELETE FROM `ba_oper_step` WHERE `id`=(SELECT id FROM `ba_oper_step` WHERE `id`=?);";
	return sqlSession->executeUpdate(sql, "%s", id) == 1;
}

bool OperStepDAO::update(const OperStepDO& uObj)
{
	std::string sql = "UPDATE `ba_oper_step` SET `update_name`=?,`update_by`=?,`update_date`=?,\
		`oper_step_code`=?,`oper_step_name`=?,`sys_org_code`=?,`sys_company_code`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s", uObj.getUpdate_name(), uObj.getUpdate_by(), 
		uObj.getUpdate_date(), uObj.getOper_step_code(), uObj.getOper_step_name(), uObj.getSys_org_code(),
		uObj.getSys_company_code(), uObj.getId()) == 1;
}

bool OperStepDAO::insertFromExcel(const std::list<OperStepDO>& iObj)
{
	for (const OperStepDO& obj : iObj)
	{
		std::string sql = "INSERT INTO `ba_oper_step` (`id`, `create_name`, `create_by`, `create_date`, `update_name`, `update_by`, `update_date`,\
			`sys_org_code`, `sys_company_code`, `oper_step_code`, `oper_step_name`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
		sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s", obj.getId(), obj.getCreate_name(), obj.getCreate_by(), obj.getCreate_date(), 
			obj.getUpdate_name(), obj.getUpdate_by(), obj.getUpdate_date(), obj.getSys_org_code(), obj.getSys_company_code(), 
			obj.getOper_step_code(), obj.getOper_step_name());
	}
	return true;
}

std::list<OperStepDO> OperStepDAO::selectAll()
{
	std::string sql = "SELECT create_name,create_by,create_date,update_name,update_by,update_date,sys_org_code,sys_company_code,\
		oper_step_code, oper_step_name FROM ba_oper_step";
	OperStepMapper mapper;
	return sqlSession->executeQuery<OperStepDO>(sql, mapper);
}


