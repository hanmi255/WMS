#include "stdafx.h"
#include "QualityDAO2.h"
#include "QualityMapper2.h"
#include "domain/do/qcd/QualityDO2.h"
#include <cstdarg>

// 批量删除数据
int QualityDAO::deleteByIds(const std::vector<std::int32_t>& ids) {
	if (ids.empty()) {
		OATPP_LOGE("QualityDAO", "No IDs provided for batch deletion");
		return 0;
	}

	// 构建 SQL 语句，动态生成占位符
	std::string sql = "DELETE FROM `ba_qm_qa` WHERE `id` IN (";
	for (size_t i = 0; i < ids.size(); ++i) {
		sql += "?";
		if (i < ids.size() - 1) {
			sql += ",";
		}
	}
	sql += ")";

	// 动态构建参数列表
	std::vector<std::string> params;
	for (const auto& id : ids) {
		params.push_back(std::to_string(id));
	}

	// 调用 SqlSession 的 executeUpdate 方法
	try {
		return sqlSession->executeUpdate(sql, params);
	}
	catch (const std::exception& e) {
		OATPP_LOGE("QualityDAO", "Failed to execute batch delete: %s", e.what());
		return 0;
	}
}


// 插入数据
uint64_t QualityDAO::insert2(const QualityDO& iObj) {
	try {
		OATPP_LOGD("QualityDAO", "Attempting to insert/update data with ID: %s", iObj.getId().c_str());

		// 先检查ID是否存在
		string checkSql = "SELECT COUNT(*) FROM ba_qm_qa WHERE id=?";
		int exists = sqlSession->executeQueryNumerical(checkSql, "%s", iObj.getId());
		OATPP_LOGD("QualityDAO", "ID exists check result: %d", exists);

		if (exists > 0) {
			// 如果存在则获取当前最大ID
			string maxIdSql = "SELECT COALESCE(MAX(CAST(id AS UNSIGNED)), 0) FROM ba_qm_qa";
			int maxId = sqlSession->executeQueryNumerical(maxIdSql);
			string newId = to_string(maxId + 1);
			OATPP_LOGD("QualityDAO", "Generated new ID: %s", newId.c_str());

			try {
				std::string sql =
					"INSERT INTO ba_qm_qa (id, create_name, create_by, create_date, "
					"update_name, update_by, update_date, sys_org_code, "
					"sys_company_code, qm_qa_code, qm_qa_name) "
					"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

				// 打印所有字段值用于调试
				OATPP_LOGD("QualityDAO", "Inserting with values: id=%s, create_name=%s, create_by=%s, create_date=%s",
					newId.c_str(), iObj.getCreate_name().c_str(), iObj.getCreate_by().c_str(), iObj.getCreate_date().c_str());

				uint64_t result = sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s%s%s%s",
					newId, iObj.getCreate_name(), iObj.getCreate_by(),
					iObj.getCreate_date(), iObj.getUpdate_name(), iObj.getUpdate_by(),
					iObj.getUpdate_date(), iObj.getSys_org_code(),
					iObj.getSys_company_code(), iObj.getQm_qa_code(), iObj.getQm_qa_name());

				return result > 0 ? 0 : 1;  // 修改返回值：成功返回0，失败返回1
			}
			catch (const exception& e) {
				OATPP_LOGE("QualityDAO", "Insert with new ID failed: %s", e.what());
				return 1;  // 修改返回值
			}
		}
		else {
			try {
				std::string sql =
					"INSERT INTO ba_qm_qa (id, create_name, create_by, create_date, "
					"update_name, update_by, update_date, sys_org_code, "
					"sys_company_code, qm_qa_code, qm_qa_name) "
					"VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

				uint64_t result = sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s%s%s%s",
					iObj.getId(), iObj.getCreate_name(), iObj.getCreate_by(),
					iObj.getCreate_date(), iObj.getUpdate_name(), iObj.getUpdate_by(),
					iObj.getUpdate_date(), iObj.getSys_org_code(),
					iObj.getSys_company_code(), iObj.getQm_qa_code(), iObj.getQm_qa_name());

				return result > 0 ? 0 : 1;  // 修改返回值：成功返回0，失败返回1
			}
			catch (const exception& e) {
				OATPP_LOGE("QualityDAO", "Direct insert failed: %s", e.what());
				return 1;  // 修改返回值
			}
		}
	}
	catch (const exception& e) {
		OATPP_LOGE("QualityDAO", "General error: %s", e.what());
		return 1;  // 修改返回值
	}
}


// 分页查询
std::list<QualityDO> QualityDAO::QueryWithPage(const QualityQuery::Wrapper& query)
{
	std::list<QualityDO> res;
	std::string sql = "SELECT * FROM ba_qm_qa";

	// 执行查询
	QualityMapper mapper;
	res = sqlSession->executeQuery<QualityDO>(sql, mapper);

	// 检查查询结果是否为空
	if (res.empty()) {
		OATPP_LOGE("QualityDAO", "Query returned no results");
	}
	return res;
}

