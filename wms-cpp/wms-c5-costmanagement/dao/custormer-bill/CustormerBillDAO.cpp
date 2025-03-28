#include "stdafx.h"
#include "CustormerBillDAO.h"
#include "CustomerBillMapper.h"
#include <sstream>

std::string CustomerBillDAO::queryConditionBuilder(const CustomerBillQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->customercode) {
		sqlCondition << " AND `cus_code` LIKE CONCAT('%', ? , '%')";
		SQLPARAMS_PUSH(params, "s", std::string, query->customercode.getValue(""));
	}
	if (query->fullchinesename) {

		sqlCondition << " AND cus_name  LIKE CONCAT('%', ? )";
		SQLPARAMS_PUSH(params, "s", std::string, query->fullchinesename.getValue(""));
	}

	return sqlCondition.str();
}






uint64_t CustomerBillDAO::count(const CustomerBillQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM mv_cus ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

//根据query分页查do
std::list<CustomerBillDO> CustomerBillDAO::selectWithPage(const CustomerBillQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT cus_code,cus_name FROM mv_cus ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	CustomerBillMapper mapper;
	return sqlSession->executeQuery<CustomerBillDO>(sql, mapper, params);
}







//根据客户编码id（mv_code）查do
std::list<DayCostDO> CustomerBillDAO::selectById(oatpp::String id)
{ 
	SqlParams params;
	string sql = "SELECT id,create_name,create_by,create_date,update_name,update_by,update_date,sys_org_code\
					,sys_company_code,cus_code,cus_name,cost_code,cost_name,cost_data,day_cost_yj,day_cost_bhs,day_cost_se,day_cost_hsj\
					,cost_ori,beizhu,cost_sta,cost_sl,cost_unit,cost_js FROM wm_day_cost  WHERE `cus_code`=? ";

	DayCostMapper mapper;
	return sqlSession->executeQuery<DayCostDO>(sql, mapper, "%s",id.getValue(""));
}


//在上面id的基础上多了一个起始时间与结束时间cost_date
std::list<DayCostDO> CustomerBillDAO::selectBydate(const PeriodQuery::Wrapper& file)
{
	string sql = "SELECT id,create_name,create_by,create_date,update_name,update_by,update_date,sys_org_code\
					,sys_company_code,cus_code,cus_name,cost_code,cost_name,cost_data,day_cost_yj,day_cost_bhs,day_cost_se,day_cost_hsj\
					,cost_ori,beizhu,cost_sta,cost_sl,cost_unit,cost_js FROM wm_day_cost WHERE `cus_code`=? AND cost_data BETWEEN ? AND ?" ;
	DayCostMapper mapper;
	return sqlSession->executeQuery<DayCostDO>(sql, mapper, "%s%s%s", file->customercode.getValue(""),file->startdate.getValue(""),file->enddate.getValue(""));
}
