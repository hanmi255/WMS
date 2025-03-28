#include "stdafx.h"
#include "onocc_dao.h"
#include "es_mapper.h"
#include <sstream>
#include <ctime>
#include <string>
#include <chrono>
#include <iomanip>

// C++11及以上版本可用，线程安全且跨平台
std::string getCurrentDateTimeString() {
	// 获取当前时间点
	auto now = std::chrono::system_clock::now();

	// 转换为time_t类型（C风格时间）
	std::time_t now_time = std::chrono::system_clock::to_time_t(now);

	// 转换为本地时间结构体（线程安全版本）
	std::tm tm_struct{};

	// 平台兼容性处理
#if defined(_WIN32) || defined(_WIN64)
	localtime_s(&tm_struct, &now_time);    // Windows安全版本
#else
	localtime_r(&now_time, &tm_struct);     // Linux/macOS安全版本
#endif

	// 使用std::put_time格式化时间
	std::stringstream ss;
	ss << std::put_time(&tm_struct, "%Y-%m-%d %H:%M:%S");

	return ss.str();
}

std::string EsDAO::queryConditionBuilder(const EsQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->pos_sta_code)
	{
		sqlCondition << " AND `pos_sta_code`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->pos_sta_code.getValue(""));
	}
	if (query->pos_sta_name)
	{
		sqlCondition << " AND `pos_sta_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->pos_sta_name.getValue(""));
	}
	return sqlCondition.str();
}
uint64_t EsDAO::count(const EsQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM ba_pos_sta ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}
std::list<EsDO> EsDAO::selectWithPage(const EsQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT id,pos_sta_code,pos_sta_name FROM ba_pos_sta ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	EsMapper mapper;
	return sqlSession->executeQuery<EsDO>(sql, mapper, params);
}
std::string EsDAO::insert(const EsDO& iObj)
{
	string sql = "INSERT INTO `ba_pos_sta` (`id`,`create_name`,`create_by`,`create_date`,`pos_sta_code`,`pos_sta_name`,`sys_org_code`,`sys_company_code`) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
	UuidFacade uid(1);
	string _uid = uid.genUuid();
	sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s", _uid,iObj.getCreate_Name(), iObj.getCreate_By(), getCurrentDateTimeString(),iObj.getPos_Sta_Code(), iObj.getPos_Sta_Name(),iObj.getSys_Org_Code(),iObj.getSys_Company_Code());
	return _uid;
}
int EsDAO::update(const EsDO& uObj)
{
	string sql = "UPDATE `ba_pos_sta` SET `update_name`=?,`update_by`=?,`update_date`=?,`pos_sta_code`=?, `pos_sta_name`=?,`sys_org_code`=?,`sys_company_code`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s",uObj.getUpdate_Name(),uObj.getUpdate_By(), getCurrentDateTimeString(),uObj.getPos_Sta_Code(), uObj.getPos_Sta_Name(), uObj.getSys_Org_Code(),uObj.getSys_Company_Code(),uObj.getId());
}