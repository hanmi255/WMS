#include "stdafx.h"
#include "EnterpriseStatusDAO.h"
#include "EnterpriseStatusMapper.h"
#include <sstream>

std::string EnterpriseStatusDAO::queryConditionBuilder(const EnterpriseQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->enterpriseid) {

		sqlCondition << " AND kehuzhuangtai_code=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->enterpriseid.getValue(""));
	}
	if (query->enterprisename) {

		sqlCondition << " AND kehuzhuangtai_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->enterprisename.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t EnterpriseStatusDAO::count(const EnterpriseQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM zo_wms.ba_kehuzhuangtai ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	auto res = sqlSession->executeQueryNumerical(sql, params);
	return res;
}

uint64_t EnterpriseStatusDAO::count1()
{
	string sql = "SELECT COUNT(*) FROM zo_wms.ba_kehuzhuangtai WHERE cus_sta_del<> 'Y'  ";
	// 执行查询
	return sqlSession->executeQueryNumerical(sql);
}

std::list<EnterpriseStatusDO> EnterpriseStatusDAO::selectWithPage(const EnterpriseQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT kehuzhuangtai_code,kehuzhuangtai_name,cus_sta_del FROM zo_wms.ba_kehuzhuangtai ";
	
	
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	EnterpriseStatusMapper mapper;
	auto res = sqlSession->executeQuery<EnterpriseStatusDO>(sql, mapper, params);
	return res;
}


std::list<EnterpriseStatusListDO> EnterpriseStatusDAO::selectForList()
{
	string sql = "SELECT id,kehuzhuangtai_code,kehuzhuangtai_name FROM zo_wms.ba_kehuzhuangtai WHERE cus_sta_del<> 'Y' ";
	EnterpriseStatusListMapper mapper;
	return sqlSession->executeQuery<EnterpriseStatusListDO>(sql, mapper);
}