#include "stdafx.h"
#include "BaWorkStDAO.h"
#include "BaworkStMapper.h"

std::string BaWorkStDAO::queryConditionBuilder(const BaWorkStQuery::Wrapper& query, SqlParams& params) {
	stringstream sqlCondition;
	sqlCondition << "WHERE 1=1";
	if (query->id) {
		sqlCondition << "AND id=?";
		SQLPARAMS_PUSH(params,"s",std::string,query->id.getValue(""));
	}
	if (query->create_name) {
		sqlCondition << "AND create_name=?";
		SQLPARAMS_PUSH(params,"s",std::string,query->create_name.getValue(""));
	}
	if (query->update_name) {
		sqlCondition << "AND update_name=?";
		SQLPARAMS_PUSH(params,"s",std::string,query->update_name.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t BaWorkStDAO::count(const BaWorkStQuery::Wrapper& query) {
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM ba_work_sta ";
	sql += queryConditionBuilder(query,params);
	return sqlSession->executeQueryNumerical(sql,params);
}


std::list<BaWorkStDO> BaWorkStDAO::selectWithPage(const BaWorkStQuery::Wrapper& query) {
	SqlParams params;
	string sql = "SELECT * FROM ba_work_sta ";
	sql += queryConditionBuilder(query,params);
	////·ÖÒ³Ìõ¼þ
	sql += " LIMIT " + std::to_string((query->pageIndex -1) * query->pageSize) + "," + std::to_string(query->pageSize);

	BaWorkStMapper mapper;
	list<BaWorkStDO> re = sqlSession->executeQuery<BaWorkStDO>(sql, mapper, params);
	return re;
}

uint64_t BaWorkStDAO::insert(const BaWorkStDO& iObj) {
	string sql = "INSERT INTO ba_work_sta (id,create_name,create_by,create_date,sys_org_code,sys_company_code,work_sta_code,work_sta_name) VALUES (?, ?, ?, NOW(), ?, ?, ?, ?) ";
	uint64_t re = sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s", iObj.getId(), iObj.getCreateName(), iObj.getCreateBy()/*, iObj.getCreateDate()*/, iObj.getSysOrgCode(), iObj.getSysCompanyCode(), iObj.getWorkStaCode(), iObj.getWorkStaName());
	return re;
}

int BaWorkStDAO::update(const BaWorkStDO& uObj){
	string sql = "UPDATE ba_work_sta SET update_name=?, update_by=?, update_date=NOW(), sys_org_code=?, sys_company_code=?, work_sta_code=?, work_sta_name=? WHERE id=? ";
	return sqlSession->executeUpdate(sql,"%s%s%s%s%s%s%s",uObj.getUpdateName(), uObj.getUpdateBy(), uObj.getSysOrgCode(),uObj.getSysCompanyCode(),uObj.getWorkStaCode(),uObj.getWorkStaName(),uObj.getId());	
}