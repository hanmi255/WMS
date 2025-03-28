#include "stdafx.h"
#include "PisDAO.h"
#include "PisMapper.h"
#include <sstream>

std::string PisDAO::queryConditionBuilder(const PisQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->code) {

		sqlCondition << " AND `qm_sta_code`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->code.getValue(""));
	}
	if (query->name) {

		sqlCondition << " AND `qm_sta_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t PisDAO::count(const PisQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM ba_qm_sta ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<PisDO> PisDAO::selectWithPage(const PisQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT id,qm_sta_code,qm_sta_name FROM ba_qm_sta ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	PisMapper mapper;
	return sqlSession->executeQuery<PisDO>(sql, mapper, params);
}

std::string getCurrentTime()
{
	// 获取当前时间
	auto now = std::chrono::system_clock::now();
	auto now_time_t = std::chrono::system_clock::to_time_t(now);

	// 转换为本地时间
	std::tm tm = *std::localtime(&now_time_t);

	// 格式化时间为字符串 "YYYY-MM-DD HH:MM:SS"
	std::ostringstream oss;
	oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
	return oss.str();
}

std::string PisDAO::insert(const PisDO& iObj)
{
	UuidFacade uidFacade(1);
	// 获取生成的UUID
	std::string uuid = uidFacade.genUuid();
	// 获取当前时间
	std::string currentTime = getCurrentTime();

	string sql = "INSERT INTO `ba_qm_sta` (`id`,`create_name`,`create_by`,`create_date`,`sys_org_code`,`sys_company_code`,`qm_sta_code`, `qm_sta_name`) VALUES (?,?,?,?,?,?,?,?)";
	sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s",uuid, iObj.getCreate_Name(), iObj.getCreate_By(), currentTime, iObj.getSys_Org_Code(), iObj.getSys_Company_Code(), iObj.getCode(), iObj.getName());
	return uuid;
}

int PisDAO::update(const PisDO& uObj)
{
	string sql = "UPDATE `ba_qm_sta` SET `qm_sta_name`=? WHERE `qm_sta_code`=?";
	return sqlSession->executeUpdate(sql, "%s%s", uObj.getName(),uObj.getCode());
}


//PtrPisDO PisDAO::selectByCode(const string& code)
//{
//	string sql = "SELECT qm_sta_code,qm_sta_name FROM ba_qm_sta_test WHERE `qm_sta_code`=? ";
//	PtrPisMapper mapper;
//	return sqlSession->executeQueryOne<PtrPisDO>(sql, mapper, "%s", code);
//}

//PtrPisDO PisDAO::selectBySta(const string& sta)
//{
//	string sql = "SELECT code,sta FROM ba_qm_sta_test WHERE `sta`=? ";
//	PtrPisMapper mapper;
//	return sqlSession->executeQueryOne<PtrPisDO>(sql, mapper, "%s", sta);
//}
