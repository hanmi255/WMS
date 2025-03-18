#include "stdafx.h"
#include "StoreDAO.h"
//#include "../lib-common/include/id/SnowFlake.h"
#include "id/UuidFacade.h"


std::string StoreDAO::queryConditionBuilder(const CangkuListQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->store_code)
	{
		sqlCondition << " AND store_code=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->store_code.getValue(""));
	}
	if (query->store_name)
	{
		sqlCondition << " AND store_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->store_name.getValue(""));
	}
	if (query->store_text)
	{
		sqlCondition << " AND store_text=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->store_text.getValue(""));
	}
	return sqlCondition.str();
}

string get_id()
{
	UuidFacade uf(1);
	return uf.genUuid();
}

string StoreDAO::add(const StoreDO& obj)
{
	string Id = get_id();
	string sql = "INSERT INTO `ba_store` \
		(`store_code`, `store_name`, `store_text`,\
		`create_name`, `create_by`, `create_date`,  \
		`sys_org_code`,`sys_company_code`, `id`)\
		VALUES(? , ? , ? , ? , ? , ? , ? , ? , ?)";
	auto res = sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s",
		obj.getStoreCode(),
		obj.getStoreName(),
		obj.getStoreText(),
		obj.getCreateName(),
		obj.getCreateBy(),
		obj.getCreateDate(),
		obj.getSysOrgCode(),
		obj.getSysCompanyCode(), Id);
	if (res > 0)
	{
		return Id;
	}
	return string{ "failed" };
}

string StoreDAO::modify(const StoreDO& obj)
{
	string sql = R"(UPDATE `ba_store`
SET 
    `store_code` = COALESCE(NULLIF(?, ''), `store_code`),
    `store_name` = COALESCE(NULLIF(?, ''), `store_name`),
    `store_text` = COALESCE(NULLIF(?, ''), `store_text`),
    `update_name` = ?,
    `update_by` = ?,
    `update_date` = ?
WHERE `id` = ?)";
	auto res = sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s",
		obj.getStoreCode(),
		obj.getStoreName(),
		obj.getStoreText(),
		obj.getUpdateName(),
		obj.getUpdateBy(),
		obj.getUpdateDate(),
		obj.getId());
	if (res > 0)
	{
		return obj.getId();
	}
	return string{ "failed" };
}

uint64_t StoreDAO::count(const CangkuListQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM ba_store ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<StoreDO> StoreDAO::selectWithPage(const CangkuListQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT store_code,store_name,store_code,id FROM ba_store ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	StoreMapper mapper;
	return sqlSession->executeQuery<StoreDO>(sql, mapper, params);
}