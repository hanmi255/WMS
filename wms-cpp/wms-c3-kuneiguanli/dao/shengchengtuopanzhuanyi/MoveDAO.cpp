#include "stdafx.h"
#include "MoveDAO.h"
#include "MoveMapper.h"
#include <sstream>

std::string MoveDAO::queryConditionBuilder(const HuoQuKeZhuanYiLieBiaoQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	/*if (query->move_date) {

		sqlCondition << " AND create_date=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->move_date.getValue(""));
	}*/
	if (query->kuctype) {

		sqlCondition << " AND kuctype=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->kuctype.getValue(""));
	}
	if (query->ku_wei_bian_ma) {

		sqlCondition << " AND ku_wei_bian_ma=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->ku_wei_bian_ma.getValue("0"));
	}
	if (query->bin_id) {

		sqlCondition << " AND bin_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->bin_id.getValue(""));
	}
	if (query->cus_code) {

		sqlCondition << " AND cus_code=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->cus_code.getValue(""));
	}
	if (query->zhong_wen_qch) {

		sqlCondition << " AND zhong_wen_qch=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->zhong_wen_qch.getValue(""));
	}
	if (query->goods_id) {

		sqlCondition << " AND goods_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods_id.getValue(""));
	}
	if (query->shp_ming_cheng) {

		sqlCondition << " AND shp_ming_cheng=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->shp_ming_cheng.getValue(""));
	}
	/*if (query->goods_pro_date) {

		sqlCondition << " AND goods_pro_date=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods_pro_date.getValue(""));
	}*/
	return sqlCondition.str();
}

uint64_t MoveDAO::count(const HuoQuKeZhuanYiLieBiaoQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM wv_stock_stt ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<MoveDO> MoveDAO::selectWithPage(const HuoQuKeZhuanYiLieBiaoQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT kuctype,ku_wei_bian_ma,bin_id,cus_code,zhong_wen_qch,goods_id,goods_qua,shp_ming_cheng,goods_pro_data,bzhi_qi,goods_unit FROM wv_stock_stt";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	MoveMapper mapper;
	return sqlSession->executeQuery<MoveDO>(sql, mapper, params);
}

