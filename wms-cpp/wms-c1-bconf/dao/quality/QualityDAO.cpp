#include "stdafx.h"
#include "QualityDAO.h"
#include "QualityMapper.h"
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


inline std::string QualityDAO::queryConditionBuilder(const QualityQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->qm_qa_name) {

		sqlCondition << " AND `qm_qa_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->qm_qa_name.getValue(""));
	}
	if (query->qm_qa_code) {

		sqlCondition << " AND qm_qa_code=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->qm_qa_code.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t QualityDAO::count(const QualityQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM ba_qm_qa";

	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<QualityDO> QualityDAO::selectWithPage(const QualityQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT id,qm_qa_code,qm_qa_name FROM ba_qm_qa ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	QualityMapper mapper;
	return sqlSession->executeQuery<QualityDO>(sql, mapper, params);
}

std::list<QualityDO> QualityDAO::selectByName(const string& name)
{
	string sql = "SELECT id,qm_qa_code,qm_qa_name FROM ba_qm_qa WHERE `qm_qa_name` LIKE CONCAT('%',?,'%')";
	QualityMapper mapper;
	return sqlSession->executeQuery<QualityDO>(sql, mapper, "%s", name);
}

std::list<QualityDO> QualityDAO::selectByCode(const string& code)
{
	string sql = "SELECT id,qm_qa_code,qm_qa_name FROM ba_qm_qa WHERE `qm_qa_code` LIKE CONCAT('%',?,'%')";
	QualityMapper mapper;
	return sqlSession->executeQuery<QualityDO>(sql, mapper, "%s", code);
}

uint64_t QualityDAO::insert(const QualityDO& iObj)
{
	string sql = "INSERT INTO `ba_qm_qa` (`id`, `qm_qa_code`, `qm_qa_name`,`create_name`,`create_by`,`create_date`,`sys_org_code`,`sys_company_code`) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
	UuidFacade uid(1);
	string _uid = uid.genUuid();
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s", _uid, iObj.getCode(), iObj.getName(), iObj.getCreate_Name(), iObj.getCreate_By(), getCurrentDateTimeString(), iObj.getSys_Org_Code(), iObj.getSys_Company_Code());
}

int QualityDAO::update(const QualityDO& uObj)
{
	string sql = "UPDATE `ba_qm_qa` SET `qm_qa_name`=?, `qm_qa_code`=?, `update_name`=?,`update_by`=?,`update_date`=?,`sys_org_code`=?,`sys_company_code`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s", uObj.getName(), uObj.getCode(), uObj.getUpdate_Name(), uObj.getUpdate_By(), getCurrentDateTimeString(), uObj.getSys_Org_Code(), uObj.getSys_Company_Code(), uObj.getId());
}
