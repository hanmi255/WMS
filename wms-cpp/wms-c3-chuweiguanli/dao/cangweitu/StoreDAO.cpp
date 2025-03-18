#include "stdafx.h"
#include "StoreDAO.h"
#include "StoreMapper.h"
#include <sstream>

std::string StoreDAO::queryConditionBuilder(const HuoQuCangWeiShuJuQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->bin_store) {

		sqlCondition << " AND bin_store=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->bin_store.getValue(""));
	}
	if (query->bin_id) {

		sqlCondition << " AND binid=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->bin_id.getValue(""));
	}
	if (query->znode) {

		sqlCondition << " AND znode=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->znode.getValue(""));
	}
	if (query->xnode) {

		sqlCondition << " AND cast(xnode AS unsigned)<=? ";
		SQLPARAMS_PUSH(params, "s", std::string, query->xnode.getValue(""));
	}
	if (query->ynode) {

		sqlCondition << " AND cast(ynode AS unsigned)<=? ";
		SQLPARAMS_PUSH(params, "s", std::string, query->ynode.getValue(""));
	}
	return sqlCondition.str();
}

std::list<WvDO> StoreDAO::selectWithPage(const HuoQuCangWeiShuJuQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT bin_store,binid,znode,xnode,ynode,colour,tincount FROM wv_bin_all ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	

	// 执行查询
	StoreMapper mapper;
	return sqlSession->executeQuery<WvDO>(sql, mapper, params);
}