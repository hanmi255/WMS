#include "stdafx.h"
//#include "SampleDAO.h"
#include "RemovalAdjustDAO.h"
//#include "SampleMapper.h"
#include "RemovalAdjustMapper.h"
#include <sstream>

std::string RemovalDAO::queryConditionBuilder(const RemovalQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->order_id) {

		sqlCondition << " AND `order_id`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->order_id.getValue(""));
	}
	if (query->goods_id) {

		sqlCondition << " AND goods_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods_id.getValue(""));
	}
	if (query->goods_name) {

		sqlCondition << " AND goods_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods_name.getValue(""));
	}
	return sqlCondition.str();
}

uint64_t RemovalDAO::count(const RemovalQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM wm_to_down_goods";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	//std::cout << sql <<" "<<params.size();
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<RemovalDO> RemovalDAO::selectWithPage(const RemovalQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT id,order_id,goods_id,goods_name FROM wm_to_down_goods";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	//把分页条件构造好后就可以执行查询了
	// 执行查询
	RemovalMapper mapper;
	//mapper就是将查询结果映射到 RemovalDO 对象。
	//
	return sqlSession->executeQuery<RemovalDO>(sql, mapper, params);
	//通过这一部分的代码就把数据库的字段给整进DO里面了
}
PtrRemovalDO RemovalDAO::selectById(const string &id)
{
	string sql = "SELECT id,order_id,goods_id,goods_name,goods_qua FROM wm_to_down_goods WHERE `id`=?";
	PtrRemovalDetailMapper mapper;
	
	return sqlSession->executeQueryOne<PtrRemovalDO>(sql, mapper, "%s", id);
}
int RemovalDAO::update(const RemovalDO& uObj)
{
	string sql = "UPDATE `wm_to_down_goods` SET `order_id`=?, `goods_id`=?, `goods_name`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s", uObj.getOrder_id(),uObj.getGoods_id(),uObj.getGoods_name(),uObj.getId());
}
std::list<RemovalDO> RemovalDAO::selectdetail(const RemovalQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT id,order_id,goods_id,goods_name,goods_qua FROM wm_to_down_goods";
	sql += queryConditionBuilder(query, params);
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	RemovalDetailMapper  detailmapper;
	return sqlSession->executeQuery<RemovalDO>(sql, detailmapper, params);
}