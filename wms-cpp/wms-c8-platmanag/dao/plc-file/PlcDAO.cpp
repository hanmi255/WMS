/*
 @Author: tutu
 @Date: 2025/03/05 14:26:52
*/
#include "stdafx.h"
#include "PlcDAO.h"
#include "PlcMapper.h"
#include "../../lib-common/include/id/UuidFacade.h"

std::string PlcDAO::queryConditionBuilder(const PlcFileQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->plc_type1) {
		sqlCondition << " AND `plc_type`>=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->plc_type1.getValue(""));
	}
	if (query->plc_type2) {

		sqlCondition << " AND `plc_type`<=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->plc_type2.getValue(""));
	}
	if (query->com_remark1) {
		sqlCondition << " AND `com_remark`>=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->com_remark1.getValue(""));
	}
	if (query->com_remark2) {
		sqlCondition << " AND `com_remark`<=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->com_remark2.getValue(""));
	}
	if (query->com_no) {

		sqlCondition << " AND `com_no`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->com_no.getValue(""));
	}
	return sqlCondition.str();
}
//查询数据总条数
uint64_t PlcDAO::count(const PlcFileQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM wms_plc ";
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}
//分页查询
std::list<PlcBaseDO> PlcDAO::selectWithPage(const PlcFileQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT id,plc_ip,plc_port,plc_type,com_remark,com_no FROM wms_plc ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	// 执行查询
	PlcBaseMapper mapper;
	return sqlSession->executeQuery<PlcBaseDO>(sql, mapper, params);
}
//
//std::list<SampleDO> SampleDAO::selectByName(const string& name)
//{
//	string sql = "SELECT id,name,sex,age FROM sample WHERE `name` LIKE CONCAT('%',?,'%')";
//	SampleMapper mapper;
//	return sqlSession->executeQuery<SampleDO>(sql, mapper, "%s", name);
//}
//
PtrPlcDO PlcDAO::selectById(string id)
{
	string sql = "SELECT * FROM wms_plc WHERE `id`=?";
	PtrPlcMapper mapper;
	return sqlSession->executeQueryOne<PtrPlcDO>(sql, mapper, "%s", id);
}
int PlcDAO::insert(const PlcDO& iObj, string name, string realname, string orgcode, string companycode)
{
	std::string currentTime = getCurrentDateTime(); //update_date
	UuidFacade uf(0);
	std::string id = uf.genUuid();
	string sql = "INSERT INTO `wms_plc` (`id`, `create_name`, `create_by`, `create_date`, "
		"`sys_org_code`,`sys_company_code`, "
		" `plc_ip`, `plc_port`, `plc_type`,`com_remark`,`com_time`,`com_seq`,"
		"`com_cons`,`remark1`,`com_no`,`query01`,`query02`,`setp_time`,`setp_num`) VALUES(? , "
		"?  , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? )";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", 
		id, name, realname, currentTime, orgcode, companycode, 
		iObj.getplc_ip(), iObj.getplc_port(), iObj.getplc_type(), iObj.getcom_remark(), 
		iObj.getcom_time(), iObj.getcom_seq(), iObj.getcom_cons(), iObj.getremark1(), 
		iObj.getcom_no(), iObj.getquery01(), iObj.getquery02(), iObj.getsetp_time(), iObj.getsetp_num());
}//std::string("")

int PlcDAO::update(const PlcDO& uObj)
{
	std::string currentTime = getCurrentDateTime();
	string sql = "UPDATE `wms_plc` SET `update_date`=?, `plc_ip`=?, `plc_port`=? ,`plc_type`=?,`com_remark`=?,`com_time`=?,`com_seq`=?,`com_cons`=?,`remark1`=?,`com_no`=?,`query01`=?,`query02`=?,`setp_time`=?,`setp_num`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", currentTime,
		uObj.getplc_ip(), uObj.getplc_port(), uObj.getplc_type(), uObj.getcom_remark(),
		uObj.getcom_time(), uObj.getcom_seq(), uObj.getcom_cons(), uObj.getremark1(),
		uObj.getcom_no(), uObj.getquery01(), uObj.getquery02(), uObj.getsetp_time(), uObj.getsetp_num(), uObj.getid());
}
//
int PlcDAO::deleteById(string id)
{
	string sql = "DELETE FROM `wms_plc` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}
std::string PlcDAO::getCurrentDateTime() {
	std::time_t now = std::time(nullptr);
	char buf[20];
	std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
	return std::string(buf);
}