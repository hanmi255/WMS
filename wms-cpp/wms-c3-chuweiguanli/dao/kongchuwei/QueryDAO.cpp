#include "stdafx.h"
#include "QueryDAO.h"
#include "QueryMapper.h"
#include <sstream>

std::string QueryDAO::queryConditionBuilder(const DaoChuKongChuWeiQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->bin_store) {

		sqlCondition << " AND bin_store=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->bin_store.getValue(""));
	}
	if (query->ku_wei_shu_xing) {

		sqlCondition << " AND ku_wei_shu_xing=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->ku_wei_shu_xing.getValue(""));
	}
	if (query->CHP_SHU_XING) {

		sqlCondition << " AND CHP_SHU_XING=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->CHP_SHU_XING.getValue(""));
	}
	if (query->ku_wei_bian_ma) {

		sqlCondition << " AND ku_wei_bian_ma=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->ku_wei_bian_ma.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t QueryDAO::count(const DaoChuKongChuWeiQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM md_bin ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<BinDO> QueryDAO::selectWithPage(const DaoChuKongChuWeiQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT bin_store,ku_wei_shu_xing,CHP_SHU_XING,ku_wei_bian_ma,suo_shu_ke_hu,zui_da_ti_ji,shang_jia_ci_xu,chang,kuan,gao,zui_da_tuo_pan,ting_yong,ku_wei_lei_xing FROM md_bin ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	QueryMapper mapper;
	return sqlSession->executeQuery<BinDO>(sql, mapper, params);
}