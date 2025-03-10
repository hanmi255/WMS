#pragma once
#include "stdafx.h"
#include "ChuWeiDao.h"
#include "ChuWeiMapper.h"
#include <sstream>

// 查询条件构建
std::string ChuWeiDAO::queryConditionBuilder(const ChuWeiQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	//仓库
	if (query->bin_store) {

		sqlCondition << " AND `bin_store`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->bin_store.getValue(""));
	}
	//库位编码
	if (query->ku_wei_bian_ma) {

		sqlCondition << " AND `ku_wei_bian_ma`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->ku_wei_bian_ma.getValue(""));
	}
	//库位条码
	if (query->ku_wei_tiao_ma) {

		sqlCondition << " AND `ku_wei_tiao_ma`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->ku_wei_tiao_ma.getValue(""));
	}
	//库位类型
	if (query->ku_wei_lei_xing) {

		sqlCondition << " AND `ku_wei_lei_xing`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->ku_wei_lei_xing.getValue(""));
	}
	//x坐标
	if (query->xnode) {

		sqlCondition << " AND `xnode`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->xnode.getValue(""));
	}
	//y坐标
	if (query->ynode) {

		sqlCondition << " AND `ynode`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->ynode.getValue(""));
	}
	//z坐标
	if (query->znode) {

		sqlCondition << " AND `znode`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->znode.getValue(""));
	}

	return sqlCondition.str();
}

// 统计数据条数
uint64_t ChuWeiDAO::count(const ChuWeiQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM md_bin ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

// 分页查询数据
std::list<BinDO> ChuWeiDAO::selectWithPage(const ChuWeiQuery::Wrapper& query)
{
	// 参数合法性校验
	if (query->pageIndex < 1 || query->pageSize < 1) {
		throw std::invalid_argument("Invalid page parameters: pageIndex and pageSize must be positive integers");
	}
	SqlParams params;
	string sql = "SELECT id,bin_store,ku_wei_bian_ma,ku_wei_tiao_ma,ku_wei_lei_xing,ku_wei_shu_xing,\
		CHP_SHU_XING,shang_jia_ci_xu,qu_huo_ci_xu,suo_shu_ke_hu,zui_da_ti_ji,zui_da_zhong_liang,\
		zui_da_tuo_pan,chang,kuan,gao,ting_yong,ming_xi,ming_xi1,ming_xi2,ming_xi3,LORA_bqid,\
		xnode,ynode,znode FROM md_bin ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	
	/*// 构建分页条件 
	//用字符串拼接sql的方式，故要用to_string将uint类型的pageIndex、pageSize转化为字符串
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	*/

	// 参数化分页（安全改进,可避免SQL注入，若数据库不支持LIMIT参数化，则继续用上面的方法）
	const int offset = (query->pageIndex - 1) * query->pageSize;
	sql += " LIMIT ?,?";  // 使用占位符  WHERE条件值 + offset + pageSize

	// 绑定分页参数
	//实际值通过 SQLPARAMS_PUSH 绑定到 params，并替代'?'占位符，故不用to_string
	SQLPARAMS_PUSH(params, "i", int, offset);    // 偏移量
	SQLPARAMS_PUSH(params, "i", int, query->pageSize);  // 每页数量

	// 执行查询
	ChuWeiMapper mapper;
	return sqlSession->executeQuery<BinDO>(sql, mapper, params);

}

//修改储位
int ChuWeiDAO::update(const BinDO& uObj)
{
	string sql = "UPDATE `md_bin` SET `bin_store`=?, `suo_shu_ke_hu`=?, \
		`ku_wei_lei_xing`=?, `ku_wei_shu_xing`=?, `CHP_SHU_XING`=?,\
		 `shang_jia_ci_xu`=?, `qu_huo_ci_xu`=?, `zui_da_zhong_liang`=?,\
		 `zui_da_tuo_pan`=?, `chang`=?, `kuan`=?, `gao`=?,\
		 `zui_da_ti_ji`=?, `ting_yong`=?, `ming_xi`=?, `ming_xi1`=?,\
		 `ming_xi2`=?, `ming_xi3`=?, `LORA_bqid`=?, `xnode`=?,\
		 `ynode`=?, `znode`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
		uObj.getBinStore(), uObj.getSuoShuKeHu(), uObj.getKuWeiLeiXing(),
		uObj.getKuWeiShuXing(), uObj.getCHPShuXing(), uObj.getShangJiaCiXu(), 
		uObj.getQuHuoCiXu(), uObj.getZuiDaZhongLiang(), uObj.getZuiDaTuoPan(), 
		uObj.getChang(), uObj.getKuan(), uObj.getGao(), 
		uObj.getZuiDaTiJi(), uObj.getTingYong(), uObj.getMingXi(), 
		uObj.getMingXi1(), uObj.getMingXi2(), uObj.getMingXi3(), 
		uObj.getLORABqid(), uObj.getXNode(), uObj.getYNode(), 
		uObj.getZNode(), uObj.getId());
}

//删除储位
int ChuWeiDAO::deleteById(string id)
{
	string sql = "DELETE FROM `md_bin` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}