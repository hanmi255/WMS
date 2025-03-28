/*****************************************************************************
    *  @COPYRIGHT NOTICE
    *  @Copyright (c) 2013, kato1
    *  @All rights reserved
    *  @file	 : AdjustlistDAO.cpp
    *  @version  : ver 1.0
    *  @author   : kato1
    *  @date     : 2025/2/27 15:21
    *  @brief    : brief
*****************************************************************************/

#include "stdafx.h"
#include "AdjustlistDAO.h"
#include "AdjustlistMapper.h"
#include <sstream>



uint64_t AdjustlistDAO::count(const ListgoodsQuery1::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM wm_to_up_goods ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::string getCurrentTimeAsString() {
	auto now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
	std::tm* now_tm = std::localtime(&now_c);

	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", now_tm);
	return std::string(buffer);
}



std::string AdjustlistDAO::queryConditionBuilder(const ListgoodsQuery1::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";

	if (query->id) {
		sqlCondition << " AND id=?";
		SQLPARAMS_PUSH(params, "i", std::string, query->id.getValue(""));
	}

	if (query->goods_pro_data) {

		sqlCondition << " AND goods_pro_data=?";
		SQLPARAMS_PUSH(params, "g", std::string, query->goods_pro_data.getValue(""));
	}


	if (query->goods_qua) {

		sqlCondition << " AND goods_qua=?";
		SQLPARAMS_PUSH(params, "g", std::string, query->goods_qua.getValue(""));
	}

	if (query->ku_wei_bian_ma) {

		sqlCondition << " AND ku_wei_bian_ma=?";
		SQLPARAMS_PUSH(params, "g", std::string, query->ku_wei_bian_ma.getValue(""));
	}

	if (query->goods_id) {

		sqlCondition << " AND goods_id=?";
		SQLPARAMS_PUSH(params, "g", std::string, query->goods_id.getValue(""));
	}
	if (query->goods_name) {

		sqlCondition << " AND  goods_name=?";
		SQLPARAMS_PUSH(params, "g", std::string, query->goods_name.getValue(""));
	}
	if (query->create_date) {

		sqlCondition << " AND create_date=?";
		SQLPARAMS_PUSH(params, "c", std::string, query->create_date.getValue(""));
	}
	if (query->order_id) {

		sqlCondition << " AND order_id=?";
		SQLPARAMS_PUSH(params, "o", std::string, query->order_id.getValue(""));
	}

	if (query->bin_id) {

		sqlCondition << " AND bin_id=?";
		SQLPARAMS_PUSH(params, "o", std::string, query->bin_id.getValue(""));
	}

	if (query->base_unit) {

		sqlCondition << " AND base_unit=?";
		SQLPARAMS_PUSH(params, "o", std::string, query->base_unit.getValue(""));
	}

	if (query->base_goodscount) {

		sqlCondition << " AND base_goodscount=?";
		SQLPARAMS_PUSH(params, "o", std::string, query->base_goodscount.getValue(""));
	}

	if (query->goods_unit) {

		sqlCondition << " AND goods_unit=?";
		SQLPARAMS_PUSH(params, "g", std::string, query->goods_unit.getValue(""));
	}
	if (query->cus_code) {

		sqlCondition << " AND cus_code=?";
		SQLPARAMS_PUSH(params, "h", std::string, query->cus_code.getValue(""));
	}
	return sqlCondition.str();
}



std::list<AdjustlistDO> AdjustlistDAO::selectWithPage(const ListgoodsQuery1::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT id,create_date,goods_qua,ku_wei_bian_ma,bin_id,goods_id,base_goodscount,base_unit,goods_name,order_id,goods_unit,cus_code FROM wm_to_up_goods";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	AdjustlistpageMapper mapper;
	return sqlSession->executeQuery<AdjustlistDO>(sql, mapper, params);
}


PtrAdjustlistDO AdjustlistDAO::selectById(const std::string id)
{
	string sql = "SELECT id,create_date,goods_id,order_id,goods_unit,cus_code,goods_qua,goods_pro_data,ku_wei_bian_ma,bin_id,base_unit,base_goodscount FROM wm_to_up_goods WHERE `id`=?";
	PtrAdjustlistMapper mapper;
	return sqlSession->executeQueryOne<PtrAdjustlistDO>(sql, mapper, "%s", id);
}



int AdjustlistDAO::update(const AdjustlistDO& uObj, const PayloadDTO& payload)
{
	string date = getCurrentTimeAsString();
	string sql = "UPDATE `wm_to_up_goods` SET `goods_qua`=?,`goods_pro_data`=?,`bin_id`=?,`ku_wei_bian_ma`=?,`base_unit`=? ,`update_name` = ?, `update_by` = ?, `update_date` = ? ,`sys_org_code` = ?, `sys_company_code` = ? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s", uObj.getGoodsQua(), uObj.getGoodsProData(), uObj.getBinId(), uObj.getKuWeiBianMa(), uObj.getBaseUnit(),payload.getUsername(), payload.getRealname(), date,payload.getOrgcode(), payload.getCompanycode(), uObj.getId());
}

