#include "stdafx.h"
#include "BaGoodsTypeDAO.h"
#include "BaGoodsTypeMapper.h"

std::string BaGoodsTypeDAO::queryConditionBuilder(const BaGoodsTypeQuery::Wrapper& query, SqlParams& params) {
	stringstream sqlCondition;
	sqlCondition << "WHERE 1=1";
	if (query->id) {
		sqlCondition << "AND id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue(""));
	}
	if (query->create_name) {
		sqlCondition << "AND create_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->create_name.getValue(""));
	}
	if (query->update_name) {
		sqlCondition << "AND update_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->update_name.getValue(""));
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
	string sql = "SELECT * FROM ba_goods_type ";
	sql += queryConditionBuilder(query, params);
	////·ÖÒ³Ìõ¼þ
	sql += " LIMIT " + std::to_string((query->pageIndex - 1) * query->pageSize) + "," + std::to_string(query->pageSize);

	BaGoodsTypeMapper mapper;
	list<BaGoodsTypeDO> re = sqlSession->executeQuery<BaGoodsTypeDO>(sql, mapper, params);
	return re;
}