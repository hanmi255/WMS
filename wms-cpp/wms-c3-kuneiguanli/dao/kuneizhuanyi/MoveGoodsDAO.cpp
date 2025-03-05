#include "stdafx.h"
#include "dao/kuneizhuanyi/MoveGoodsDAO.h"
#include "dao/kuneizhuanyi/MoveGoodsMapper.hpp"

#include <sstream>

inline std::string MoveGoodsDAO::queryConditionBuilder(const MoveGoodsQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";

	if (query->id) {
		sqlCondition << " AND `id`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue(""));
	}
	if (query->goods_id) {
		sqlCondition << " AND `goods_id` LIKE ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods_id.getValue(""));
	}
	if (query->goods_name) {
		sqlCondition << " AND `goods_name` LIKE ?";
		SQLPARAMS_PUSH(params, "s", std::string, "%" + query->goods_name.getValue("") + "%");
	}
	if (query->cus_code) {
		sqlCondition << " AND `cus_code` LIKE ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->cus_code.getValue(""));
	}
	if (query->cus_name) {
		sqlCondition << " AND `cus_name` LIKE ?";
		SQLPARAMS_PUSH(params, "s", std::string, "%" + query->cus_name.getValue("") + "%");
	}
	if (query->to_cus_code) {
		sqlCondition << " AND `to_cus_code` LIKE ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->to_cus_code.getValue(""));
	}
	if (query->to_cus_name) {
		sqlCondition << " AND `to_cus_name` LIKE ?";
		SQLPARAMS_PUSH(params, "s", std::string, "%" + query->to_cus_name.getValue("") + "%");
	}
	if (query->tin_from) {
		sqlCondition << " AND `tin_from` LIKE ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->tin_from.getValue(""));
	}
	if (query->tin_id) {
		sqlCondition << " AND `tin_id` LIKE ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->tin_id.getValue(""));
	}
	if (query->bin_from) {
		sqlCondition << " AND `bin_from` LIKE ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->bin_from.getValue(""));
	}
	if (query->bin_to) {
		sqlCondition << " AND `bin_to` LIKE ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->bin_to.getValue(""));
	}
	if (query->move_sta) {
		sqlCondition << " AND `move_sta` LIKE ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->move_sta.getValue(""));
	}
	if (query->run_sta) {
		sqlCondition << " AND `run_sta` LIKE ?";
		SQLPARAMS_PUSH(params, "s", std::string, query->run_sta.getValue(""));
	}

	return sqlCondition.str();
}

uint64_t MoveGoodsDAO::count(const MoveGoodsQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM wm_to_move_goods ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<MoveGoodsDO> MoveGoodsDAO::selectWithPage(const MoveGoodsQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT id, goods_id, goods_name, cus_code, cus_name, to_cus_code, to_cus_name, tin_from, tin_id, bin_from, bin_to, move_sta, run_sta FROM wm_to_move_goods ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	MoveGoodsMapper mapper;
	return sqlSession->executeQuery<MoveGoodsDO>(sql, mapper, params);
}

std::string MoveGoodsDAO::updateMoveGoods(const MoveGoodsDO& moveGoods)
{
	string sql = R"(UPDATE `wm_to_move_goods`
SET 
    `base_goodscount` = COALESCE(NULLIF(?, ''), `base_goodscount`),
    `tin_id` = COALESCE(NULLIF(?, ''), `tin_id`),
    `bin_to` = COALESCE(NULLIF(?, ''), `bin_to`),
	`to_cus_code` = COALESCE(NULLIF(?, ''), `to_cus_code`),
    `to_cus_name` = COALESCE(NULLIF(?, ''), `to_cus_name`),
	`goods_pro_data` = COALESCE(NULLIF(?, ''), `goods_pro_data`),
    `to_goods_pro_data` = COALESCE(NULLIF(?, ''), `to_goods_pro_data`),
    `move_sta` = COALESCE(NULLIF(?, ''), `move_sta`),
    `update_name` = ?,
    `update_by` = ?,
    `update_date` = ?
WHERE `id` = ?)";

	// 执行更新
	auto res = sqlSession->executeUpdate(sql,
		"%s%s%s%s%s%s%s%s%s%s%s%s",
		moveGoods.getBaseGoodscount(),
		moveGoods.getTinId(),
		moveGoods.getBinTo(),
		moveGoods.getToCusCode(),
		moveGoods.getToCusName(), 
		moveGoods.getGoodsProData(),
		moveGoods.getToGoodsProData(),
		moveGoods.getMoveSta(),
		moveGoods.getUpdateName(),
		moveGoods.getUpdateBy(),
		moveGoods.getUpdateDate(),
		moveGoods.getId()
	);

	if (res > 0)
		return moveGoods.getId();

	return std::string{ "failed" };
}

std::string MoveGoodsDAO::updateMoveGoodsBatch(const std::vector<MoveGoodsDO>& moveGoodsList)
{
	string sql = R"(UPDATE `wm_to_move_goods`
SET 
    `base_goodscount` = COALESCE(NULLIF(?, ''), `base_goodscount`),
    `tin_id` = COALESCE(NULLIF(?, ''), `tin_id`),
    `bin_to` = COALESCE(NULLIF(?, ''), `bin_to`),
    `update_name` = ?,
    `update_by` = ?,
    `update_date` = ?
WHERE `id` = ?)";

	int successCount = 0;

	// 遍历所有元素执行更新
	for (const auto& moveGoods : moveGoodsList) {
		auto res = sqlSession->executeUpdate(sql,
			"%s%s%s%s%s%s%s",
			moveGoods.getBaseGoodscount(),
			moveGoods.getTinId(),
			moveGoods.getBinTo(),
			moveGoods.getUpdateName(),
			moveGoods.getUpdateBy(),
			moveGoods.getUpdateDate(),
			moveGoods.getId()
		);

		if (res > 0) 
			successCount++;
	}

	if (successCount == moveGoodsList.size())
		return std::string{ "All Updated" };
	else if (successCount > 0)
		return std::string{ "Part Updated" };
	else
		return std::string{ "failed" };
}