#include "stdafx.h"
#include "ComdegfigDAO.h"
#include "ComdegfigMapper.h"
#include <sstream>

std::string ComdegfigDAO::queryComdegBuilder(const ComdegQuery::Wrapper& query, SqlParams& params) {
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->degname) {

		sqlCondition << " AND com_deg_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->degname.getValue(""));
	}
	if (query->degcode) {

		sqlCondition << " AND com_deg_code=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->degcode.getValue(""));
	}
	return sqlCondition.str();
}

// 统计数据条数
uint64_t ComdegfigDAO::count(const ComdegQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM ba_com_deg ";
	// 构建查询条件
	sql += queryComdegBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

// 分页查询数据
std::list<ComdegfigDO> ComdegfigDAO::selectWithPage(const ComdegQuery::Wrapper& query) {
	SqlParams params;
	string sql = "SELECT  com_deg_code,com_deg_name,com_deg_del,id FROM ba_com_deg ";
	// 构建查询条件
	sql += queryComdegBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	ComdegfigMapper mapper;
	return sqlSession->executeQuery<ComdegfigDO>(sql, mapper, params);
}

// 通过企业等级名称查询数据
std::list<ComdegfigDO> ComdegfigDAO::selectByDegName(const string& name) {
	string sql = "SELECT com_deg_code,com_deg_name,com_deg_del FROM ba_com_deg WHERE `com_deg_name` LIKE CONCAT('%',?,'%')";
	ComdegfigMapper mapper;
	return sqlSession->executeQuery<ComdegfigDO>(sql, mapper, "%s", name);
}


// 通过企业等级代码查询数据
std::list<ComdegfigDO> ComdegfigDAO::selectByDegCode(const string& code) {
	string sql = "SELECT com_deg_code,com_deg_name,com_deg_del FROM ba_com_deg WHERE `com_deg_code` LIKE CONCAT('%',?,'%')";
	ComdegfigMapper mapper;
	return sqlSession->executeQuery<ComdegfigDO>(sql, mapper, "%s", code);
}

// 通过ID查询数据
PtrComdegfigDO ComdegfigDAO::selectById(string id) {
	string sql = "SELECT com_deg_code,com_deg_name,com_deg_del FROM ba_com_deg WHERE `id` LIKE CONCAT('%',?,'%')";
	PtrComdegfigMapper mapper;
	return sqlSession->executeQueryOne<PtrComdegfigDO>(sql, mapper, "%ull", id);;
}

// 插入数据
uint64_t ComdegfigDAO::insert(const ComdegfigDO& iObj) {
	string sql = "INSERT INTO `ba_com_deg` (`id`,`create_name`,`create_by`,`create_date`,`sys_org_code`,`sys_company_code`,`com_deg_code`, `com_deg_name`, `com_deg_del`) VALUES ( ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s%s",iObj.getId(),iObj.getCreateName(), iObj.getCreateBy(), iObj.getCreateDate(), iObj.getOrgCode(), iObj.getCompanyCode(), iObj.getDegCode(), iObj.getDegName(), iObj.getDegDel());
}
