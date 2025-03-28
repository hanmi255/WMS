
#include "stdafx.h"
#include "LadModDao.h"
#include "LadModMapper.h"
#include <sstream>

std::string LadModDAO::queryConditionBuilder(const LadModQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->code) {

		sqlCondition << " AND `lad_mode_code`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->code.getValue(""));
	}
	if (query->name) {

		sqlCondition << " AND lad_mode_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue(""));
	}

	return sqlCondition.str();
}

uint64_t LadModDAO::count(const LadModQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM ba_lad_mode ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<LadModDO> LadModDAO::selectWithPage(const LadModQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT id,lad_mode_code,lad_mode_name FROM ba_lad_mode ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	LadModMapper mapper;
	return sqlSession->executeQuery<LadModDO>(sql, mapper, params);
}



uint64_t LadModDAO::insert(const LadModDO& iObj)
{
	string sql = "INSERT INTO `ba_lad_mode` (`lad_mode_code`, `lad_mode_name`) VALUES (?, ?)";
	return sqlSession->executeInsert(sql, "%s%s", iObj.getCode(), iObj.getName());
}

int LadModDAO::update(const LadModDO& uObj)
{
	string sql = "UPDATE `ba_lad_mode` SET `lad_mode_code`=?, `lad_mode_name`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%ull", uObj.getCode(), uObj.getName(), uObj.getId());
}

int LadModDAO::deleteById(oatpp::UInt64 id)
{
	string sql = "DELETE FROM `ba_lad_mode` WHERE `id`=?";
    int idStr = id;
	return sqlSession->executeUpdate(sql, "%ull", idStr);
}

int LadModDAO::batchDelete(const BatchDeleteRequestDto::Wrapper& dto)
{
	string sql = "DELETE FROM `ba_lad_mode` WHERE `id` IN (";

    for (auto it = dto->ids->begin(); it != dto->ids->end(); ++it) {
		sql += std::to_string(*it);
        if (std::next(it) != dto->ids->end()) {
            sql += ", ";
        }
    }
    sql += ");";

    return sqlSession->executeUpdate(sql);
}

std::list<LadModDO> LadModDAO::selectAll()
{
	string sql = "SELECT id,lad_mode_code,lad_mode_name FROM ba_lad_mode";

	// 执行查询
	LadModMapper mapper;
	return sqlSession->executeQuery<LadModDO>(sql, mapper);
}

uint64_t LadModDAO::insert(const list<LadModDO>& data)
{
	if (data.size() > 0)
	{
		if (data.size() == 1)
		{
			return insert(*data.begin());
		}
		else
		{
			// 构建批量插入的SQL语句
			string sql = "INSERT INTO `ba_lad_mode` (`lad_mode_code`, `lad_mode_name`) VALUES ";
			for (size_t i = 0; i < data.size(); ++i) {
				sql += "(?, ?)";
				if (i < data.size() - 1) {
					sql += ", ";
				}
			}
			// 准备SQL参数
			SqlParams params;
			for (const auto& value : data) {
				SQLPARAMS_PUSH(params, "lad_mode_code", string, value.getCode());
				SQLPARAMS_PUSH(params, "lad_mode_name", string, value.getName());
			}
			return sqlSession->executeInsert(sql, params);
		}
	}
	return -1;
}