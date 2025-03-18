#include "stdafx.h"
<<<<<<< HEAD
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
=======
#include "MoveGoodsDAO.h"
#include "MoveGoodsMapper.h"
#include <sstream>


std::string MoveGoodsDAO::queryConditionBuilder(const MoveGoodsQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->goodsID) {
		sqlCondition << " AND goods_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goodsID.getValue(""));
	}
	if (query->goodsName) {
		sqlCondition << " AND goods_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goodsName.getValue(""));
	}
	if (query->cusCode) {
		sqlCondition << " AND cus_code=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->cusCode.getValue(""));
	}
	if (query->cusName) {
		sqlCondition << " AND cus_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->cusName.getValue(""));
	}
	if (query->tinFrom) {
		sqlCondition << " AND tin_from=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->tinFrom.getValue(""));
	}
	if (query->tinTo) {
		sqlCondition << " AND tin_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->tinTo.getValue(""));
	}
	if (query->binFrom) {
		sqlCondition << " AND bin_from=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->binFrom.getValue(""));
	}
	if (query->binTo) {
		sqlCondition << " AND bin_to=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->binTo.getValue(""));
	}
	if (query->moveSta) {
		sqlCondition << " AND move_sta=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->moveSta.getValue(""));
	}
	if (query->toCusCode) {
		sqlCondition << " AND to_cus_code=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->toCusCode.getValue(""));
	}
	if (query->toCusName) {
		sqlCondition << " AND to_cus_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->toCusName.getValue(""));
	}
	if (query->runSta) {
		sqlCondition << " AND run_sta=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->runSta.getValue(""));
	}
	return sqlCondition.str();
}

//uint64_t MoveGoodsDAO::count(const SampleQuery::Wrapper& query)
//{
//	SqlParams params;
//	string sql = "SELECT COUNT(*) FROM wm ";
//	// 构建查询条件
//	sql += queryConditionBuilder(query, params);
//	// 执行查询
//	return sqlSession->executeQueryNumerical(sql, params);
//}
//
//
//
PtrMoveGoodsDO MoveGoodsDAO::selectDetailedById(const oatpp::String  queryID)
{
	string sql = "SELECT goods_id,goods_name,goods_qua,goods_pro_data,goods_unit,cus_code,cus_name,"
		"tin_from,tin_id,bin_from,bin_to,move_sta,to_cus_code,to_cus_name,base_goodscount,"
		"to_goods_pro_data FROM wm_to_move_goods where id = ?";
	PtrMoveGoodsDetailedMapper mapper;
	string id = queryID->c_str();
	return sqlSession->executeQueryOne<PtrMoveGoodsDO>(sql, mapper, "%s", id);
}

std::vector<std::vector<string>> MoveGoodsDAO::selectDownLoadById(const vector<string>& ids)
{
	SqlParams params;
	string sql = "SELECT create_by,create_date,order_id_i,goods_id,goods_name,goods_qua,goods_pro_data,"
		"goods_unit,cus_code,cus_name,tin_from,tin_id,bin_from,bin_to,move_sta,to_cus_code,to_cus_name,"
		"base_unit, base_goodscount, to_goods_pro_data  FROM wm_to_move_goods  WHERE id IN(";
	for (size_t i = 0; i < ids.size(); i++)
	{
		sql += "?";
		if (i < ids.size() - 1)
		{
			sql += ",";
		}
		SQLPARAMS_PUSH(params, "s", std::string, ids[i]);
	}
	sql += ")";
	MoveGoodsDownLoadMapper mapper;
	auto list = sqlSession->executeQuery<MoveGoodsDO>(sql, mapper, params);
	std::vector<std::vector<string>> res;
	std::vector<string> sub;
	sub.push_back(ZH_WORDS_GETTER("move-goods.field.create-by"));
	sub.push_back(ZH_WORDS_GETTER("move-goods.field.create-date"));
	sub.push_back(ZH_WORDS_GETTER("move-goods.field.order-id-i"));
	sub.push_back(ZH_WORDS_GETTER("move-goods.field.cus-code"));
	sub.push_back(ZH_WORDS_GETTER("move-goods.field.cus-name"));
	sub.push_back(ZH_WORDS_GETTER("move-goods.field.goods-id"));
	sub.push_back(ZH_WORDS_GETTER("move-goods.field.goods-name"));
	sub.push_back(ZH_WORDS_GETTER("move-goods.field.now-num"));
	sub.push_back(ZH_WORDS_GETTER("move-goods.field.goods-unit"));
	sub.push_back(ZH_WORDS_GETTER("move-goods.field.move-num"));
	sub.push_back(ZH_WORDS_GETTER("move-goods.field.goods-base-unit"));
	sub.push_back(ZH_WORDS_GETTER("move-goods.field.produce-date"));
	sub.push_back(ZH_WORDS_GETTER("move-goods.field.bin-from"));
	sub.push_back(ZH_WORDS_GETTER("move-goods.field.tin-from"));
	sub.push_back(ZH_WORDS_GETTER("move-goods.field.to-cus-code"));
	sub.push_back(ZH_WORDS_GETTER("move-goods.field.to-cus-name"));
	sub.push_back(ZH_WORDS_GETTER("move-goods.field.bin-to"));
	sub.push_back(ZH_WORDS_GETTER("move-goods.field.tin-id"));
	sub.push_back(ZH_WORDS_GETTER("move-goods.field.to-produce-date"));
	sub.push_back(ZH_WORDS_GETTER("move-goods.field.move-sta"));
	res.push_back(sub);
	for (auto& item : list)
	{
		std::vector<string> sub;
		sub.push_back(item.getCreateBy());
		sub.push_back(item.getCreateDate());
		sub.push_back(item.getOrderIdI());
		sub.push_back(item.getCusCode());
		sub.push_back(item.getCusName());
		sub.push_back(item.getGoodsId());
		sub.push_back(item.getGoodsName());
		sub.push_back(item.getGoodsQua());
		sub.push_back(item.getGoodsUnit());
		sub.push_back(item.getBaseGoodscount());
		sub.push_back(item.getBaseUnit());
		sub.push_back(item.getGoodsProData());
		sub.push_back(item.getBinFrom());
		sub.push_back(item.getTinFrom());
		sub.push_back(item.getToCusCode());
		sub.push_back(item.getToCusName());
		sub.push_back(item.getBinTo());
		sub.push_back(item.getTinId());
		sub.push_back(item.getToGoodsProData());
		sub.push_back(item.getMoveSta());
		res.push_back(sub);
	}
	return res;

}

//获取当前日期时间
std::string getCurrentDateTime() {
	// 获取当前时间点 
	auto now = std::chrono::system_clock::now();
	// 将时间点转换为time_t类型 
	std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
	// 将time_t转换为tm结构体 
	std::tm now_tm = *std::localtime(&now_time_t);
	// 使用stringstream格式化日期和时间 
	std::stringstream ss;
	ss << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S");
	// 返回格式化后的日期时间字符串 
	return ss.str();
}

int MoveGoodsDAO::deleteById(const vector<string> id,const string usrName)
{
	/*string sql = "DELETE FROM wm_to_move_goods WHERE `id`IN(";*/
	string updateDate = getCurrentDateTime();
	string sql = "UPDATE wm_to_move_goods SET update_date='"+updateDate+"',update_by='"+usrName+"', move_sta= '"+ZH_WORDS_GETTER("move-goods.delete.move-sta.del")+"' WHERE `id`IN(";
	SqlParams params;
	for (size_t i = 0; i < id.size(); i++)
	{
		sql += "?";
		if (i < id.size() - 1)
		{
			sql += ",";
		}
		SQLPARAMS_PUSH(params, "s", std::string, id[i]);
	}
	sql += ")";
	return sqlSession->executeUpdate(sql, params);
>>>>>>> 05f7ec7fb45d4bc1f52eea780440c95f076c61f0
}