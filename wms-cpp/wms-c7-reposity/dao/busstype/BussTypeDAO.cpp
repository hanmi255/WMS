#include "stdafx.h"
#include "BussTypeDAO.h"
#include "BussTypeMapper.h"
#include <sstream>

std::string BussTypeDAO::queryConditionBuilder(const BussTypeQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->buss_type_name) {
		sqlCondition << " AND `buss_type_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->buss_type_name.getValue(""));
	}
	if (query->buss_type_code) {
		sqlCondition << " AND buss_type_code=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->buss_type_code.getValue(""));
	}
	if (query->buss_type_code) {
		sqlCondition << " AND buss_type_text=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->buss_type_text.getValue(""));
	}
	return sqlCondition.str();
}
std::list<BussTypeDO> BussTypeDAO::selectWithPage(const BussTypeQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT id,buss_type_name,buss_type_code,buss_type_text FROM ba_buss_type";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	BussTypeMapper mapper;
	return sqlSession->executeQuery<BussTypeDO>(sql, mapper, params);
}
// 通过业务类型名称查询数据
std::list<BussTypeDO> BussTypeDAO::selectByName(const string& name)
{
	string sql = "SELECT id,buss_type_code,buss_type_name,buss_type_text FROM ba_buss_type WHERE `buss_type_name` LIKE CONCAT('%',?,'%')";
	BussTypeMapper mapper;
	return sqlSession->executeQuery<BussTypeDO>(sql, mapper, "%s", name);
}
// 通过业务类型代码查询数据
std::list<BussTypeDO> BussTypeDAO::selectByCode(const string& code)
{
	string sql = "SELECT id,buss_type_code,buss_type_name,buss_type_text FROM ba_buss_type WHERE `buss_type_code` LIKE CONCAT('%',?,'%')";
	BussTypeMapper mapper;
	return sqlSession->executeQuery<BussTypeDO>(sql, mapper, "%s", code);
}
// 通过业务类型备注查询数据
std::list<BussTypeDO> BussTypeDAO::selectByText(const string& text)
{
	string sql = "SELECT id,buss_type_code,buss_type_name,buss_type_text FROM ba_buss_type WHERE `buss_type_text` LIKE CONCAT('%',?,'%')";
	BussTypeMapper mapper;
	return sqlSession->executeQuery<BussTypeDO>(sql, mapper, "%s", text);
}
// 插入数据
uint64_t BussTypeDAO::insert(const BussTypeDO& iObj)
{
	string sql = "INSERT INTO `ba_buss_type` (`id`,`buss_type_code`, `buss_type_name`, `buss_type_text`) VALUES (?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s", iObj.getId(),iObj.getBussTypeCode(), iObj.getBussTypeName(), iObj.getBussTypeText());
}
// 统计数据条数
uint64_t BussTypeDAO::count(const BussTypeQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM ba_buss_type ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}
// 修改数据
int BussTypeDAO::update(const BussTypeDO& uObj)
{
	string sql = "UPDATE `ba_buss_type` SET `buss_type_code`=?, `buss_type_name`=?, `buss_type_text`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s", uObj.getBussTypeCode(), uObj.getBussTypeName(), uObj.getBussTypeText(), uObj.getId());
}