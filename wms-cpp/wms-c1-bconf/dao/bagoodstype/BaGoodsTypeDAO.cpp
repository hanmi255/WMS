#include "stdafx.h"
#include "BaGoodsTypeDAO.h"
#include "BaGoodsTypeMapper.h"

std::string BaGoodsTypeDAO::queryConditionBuilder(const BaGoodsTypeQuery::Wrapper& query, SqlParams& params) {
	stringstream sqlCondition;
	sqlCondition << "WHERE 1=1";
	if (query->goods_type_code) {
		sqlCondition << " AND `goods_type_code`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods_type_code.getValue(""));
	}
	if (query->goods_type_name) {
		sqlCondition << " AND `goods_type_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods_type_name.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t BaGoodsTypeDAO::count(const BaGoodsTypeQuery::Wrapper& query) {
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM ba_goods_type ";
	sql += queryConditionBuilder(query, params);
	return sqlSession->executeQueryNumerical(sql, params);
}


std::list<BaGoodsTypeDO> BaGoodsTypeDAO::selectWithPage(const BaGoodsTypeQuery::Wrapper& query) {
	SqlParams params;
	string sql = "SELECT id,goods_type_code,goods_type_name FROM ba_goods_type ";
	sql += queryConditionBuilder(query, params);
	////·ÖÒ³Ìõ¼þ
	sql += " LIMIT " + std::to_string((query->pageIndex - 1) * query->pageSize) + "," + std::to_string(query->pageSize);

	BaGoodsTypeMapper mapper;
	list<BaGoodsTypeDO> re = sqlSession->executeQuery<BaGoodsTypeDO>(sql, mapper, params);
	return re;
}