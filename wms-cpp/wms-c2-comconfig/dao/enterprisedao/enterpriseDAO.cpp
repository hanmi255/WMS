#include "Macros.h"
#include "enterpriseDAO.h"

//查询条件构建器
std::string enterpriseDAO::queryCondionBuilder(const enterprisePageQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << "WHERE 1=1";
	if (query->enterpriseClassificationCode.getValue({}) != "NULL") {
		sqlCondition << " AND `com_type_code`=?";
		SQLPARAMS_PUSH(params, " % s", std::string, query->enterpriseClassificationCode.getValue({}));
	}
	if (query->enterpriseClassificationName.getValue({}) != "NULL") {
		sqlCondition << " AND `com_type_name`=?";
		SQLPARAMS_PUSH(params, " % s", std::string, query->enterpriseClassificationName.getValue({}));
	}
	return sqlCondition.str();
}
//计数
uint64_t enterpriseDAO::count(const enterprisePageQuery::Wrapper& query)
{
	string sql = "SELECT COUNT(*) FROM `ba_com_type`";
	SqlParams params;
	sql += queryCondionBuilder(query, params);
	return sqlSession->executeQueryNumerical(sql, params);
}
//增加企业分类信息
uint64_t enterpriseDAO::insert(const EnterpriseDO& enterpriseInfo)
{
	uint64_t jvo;
	/*
	添加redis
	缓存双写一致性
	*/
	string sql = "INSERT INTO `ba_com_type` (`id`,`create_name`,`create_by`,`create_date`,`com_type_code` ,`com_type_name`, `com_type_del`) VALUES(?,?,?,?,?,?,?)";
	jvo = sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s", enterpriseInfo.getId(), enterpriseInfo.getCreateName(), enterpriseInfo.getCreateBy(), enterpriseInfo.getCreateDate(), enterpriseInfo.getComTypeCode(), enterpriseInfo.getComTypeName(), to_string(enterpriseInfo.getComTypeDel()));
	return jvo;
}
//企业分类数据分页查询
std::list<EnterpriseDO> enterpriseDAO::selectWithPage(const enterprisePageQuery::Wrapper& query) {

	/*添加redis*/
	string sql = "SELECT `com_type_code` , `com_type_name`,`com_type_del` FROM `ba_com_type`";
	SqlParams params;
	EnterpriseDoMapper1 mapper;
	sql += queryCondionBuilder(query, params);
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	auto res = sqlSession->executeQuery<EnterpriseDO>(sql, mapper, params);
	return res;

}

//获取企业分类名称数据
std::list<EnterpriseDO> enterpriseDAO::getEnterpriseName()
{
	EnterpriseDoMapper map;
	/*添加redis*/
	string sql = "SELECT DISTINCT `com_type_name` FROM `ba_com_type`";
	return sqlSession->executeQuery<EnterpriseDO>(sql, map);
}
