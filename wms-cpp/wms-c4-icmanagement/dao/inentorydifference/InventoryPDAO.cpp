#include "stdafx.h"
#include "InventoryPDAO.h"
#include "InventoryPMapper.h"
#include <sstream>
inline std::string InventoryPDAO::queryConditionBuilder(const InventoryPquery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->stt_name) {

		sqlCondition << " AND `stt_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->stt_name.getValue(""));
	}
	if (query->stt_date) {

		sqlCondition << " AND `stt_date`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->stt_date.getValue(""));
	}
	if (query->bin_id) {

		sqlCondition << " AND `bin_id`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->bin_id.getValue(""));
	}
	if (query->tin_id) {

		sqlCondition << " AND `tin_id`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->tin_id.getValue(""));
	}
	if (query->goods_id) {

		sqlCondition << " AND `goods_id`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods_id.getValue(""));
	}
	if (query->goods_name) {

		sqlCondition << " AND `goods_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods_name.getValue(""));
	}
	if (query->goods_qua) {

		sqlCondition << " AND `goods_qua`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods_qua.getValue(0));
	}
	if (query->goods_unit) {

		sqlCondition << " AND `goods_unit`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods_unit.getValue(""));
	}
	if (query->goods_pro_data) {

		sqlCondition << " AND `goods_pro_data`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods_pro_data.getValue(""));
	}
	if (query->stt_qua) {

		sqlCondition << " AND `stt_qua`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->stt_qua.getValue(0));
	}
	if (query->cus_code) {

		sqlCondition << " AND `cus_code`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->cus_code.getValue(""));
	}
	if (query->cus_id) {

		sqlCondition << " AND `cus_id`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->cus_id.getValue(""));
	}
	if (query->stt_sta) {

		sqlCondition << " AND `stt_sta`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->stt_sta.getValue(""));
	}
	return sqlCondition.str();
}
uint64_t InventoryPDAO::count(const InventoryPquery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM wm_stt_in_goods ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}
std::list<InventoryPDO> InventoryPDAO::selectWithPage(const InventoryPquery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT id,stt_name,stt_date,bin_id,tin_id,goods_id,goods_name,goods_qua,goods_unit,goods_pro_data,stt_qua,cus_code,cus_id,stt_sta FROM wm_stt_in_goods ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	InventoryPMapper mapper;
	return sqlSession->executeQuery<InventoryPDO>(sql, mapper, params);
}

uint64_t InventoryPDAO::insert(const InventoryPDO& iObj)
{
	string sql = "INSERT INTO `wm_stt_in_goods` (stt_name,stt_date,bin_id,tin_id,goods_id,goods_name,goods_qua,goods_unit,goods_pro_data,stt_qua,cus_code,cus_id,stt_sta) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%i%s%s%i%s%s%s", iObj.getId(), iObj.getStt_name(), iObj.getStt_date(), iObj.getBin_id(), iObj.getTin_id(), iObj.getGoods_id(), iObj.getGoods_name(), iObj.getGoods_qua(), iObj.getGoods_unit(), iObj.getGoods_pro_data(), iObj.getStt_qua(), iObj.getCus_code(), iObj.getCus_id(), iObj.getStt_sta());
}
