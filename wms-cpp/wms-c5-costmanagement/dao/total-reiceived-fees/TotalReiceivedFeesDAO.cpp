#include "TotalReiceivedFeesDAO.h"
#include "stdafx.h"
#include "TotalReiceivedFeesMapper.h"
#include "sstream"


uint64_t TotalReiceivedFeesDAO::count(const TotalReiceivedFeesQuery::Wrapper& query) {
	stringstream ss;
	ss << "SELECT count(*) FROM wm_day_cost WHERE cost_js='Y' ";
	if (query->feestartdate) {
		ss << "AND cost_data>" << string(query->feestartdate.getValue(""));
	}
	if (query->feeenddate) {
		ss << " AND cost_data<" << string(query->feeenddate.getValue(""));
	}
	if (query->customers) {
		ss << " AND cus_code=" << string(query->customers.getValue(""));
	}
	if (query->fees) {
		ss << " AND cost_code=" << string(query->fees.getValue(""));
	}
	return sqlSession->executeQueryNumerical(ss.str());
}
// 分页查询数据
std::list<DayCostDO> TotalReiceivedFeesDAO::selectWithPage(const TotalReiceivedFeesQuery::Wrapper& query) {
	stringstream ss;
	ss << "SELECT cost_data,cus_code,cus_name,cost_code,\
		cost_name,cost_sl,cost_unit,day_cost_yj,day_cost_bhs,day_cost_se,\
		day_cost_hsj,id FROM wm_day_cost WHERE cost_js='Y'";
	if (query->feestartdate) {
		ss << "AND cost_data>" << string(query->feestartdate.getValue(""));
	}
	if (query->feeenddate) {
		ss << " AND cost_data<" << string(query->feeenddate.getValue(""));
	}
	if (query->customers) {
		ss << " AND cus_code=" << string(query->customers.getValue(""));
	}
	if (query->fees) {
		ss << " AND cost_code=" << string(query->fees.getValue(""));
	}
	ss << " LIMIT " << std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	TotalReiceivedFeesMapper mapper;
	return sqlSession->executeQuery<DayCostDO>(ss.str(), mapper);
}