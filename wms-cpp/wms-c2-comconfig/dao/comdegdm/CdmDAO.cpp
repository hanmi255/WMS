#include "stdafx.h"
#include "CdmDAO.h"
#include "../lib-common/include/id/SnowFlake.h"
#include "id/UuidFacade.h"
#include"CdmMapper.h"



 int  CdmDAO::update(const CdmDO& uObj)
 {
	 string sql = "UPDATE `ba_com_deg`SET  `create_name`=?, `create_by`=?, `create_date`=?, `update_name`=?, `update_by`=?,`update_date`=?,`sys_org_code`=?,`sys_company_code`=?,`com_deg_code`=?,`com_deg_name`=?,`com_deg_del`=? WHERE `id`=?";
	 return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s",  uObj.getId(), uObj.getCname(), uObj.getCby(), uObj.getCdate(), uObj.getUname(), uObj.getUby(), uObj.getUdate(), uObj.getSoc(), uObj.getScc(), uObj.getCdn() ,uObj.getCdd());
 }

 int CdmDAO::deleteById(vector<string>& ids)
 {
	 string sql = "DELETE FROM `ba_com_deg` WHERE `id`=?";

	 for (auto id : ids)
	 {
		 int res = sqlSession->executeUpdate(sql, "%s", id);

		 if (res != 1) {
			 return res; 
		 }
	 }
	 return 1;
 }

 std::list<CdmDO> CdmDAO::getAllattri() {
	 string sql = "SELECT `id`,`create_name`,`create_by`,`create_date`,`sys_org_code`,`sys_company_code`,`com_type_code`,`com_type_name` from `ba_com_type`";
	 CdmMapper mapper;
	 return sqlSession->executeQuery<CdmDO>(sql, mapper);
 }
