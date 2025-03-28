/*
 Copyright Zero One Star. All rights reserved.

 @Author: 圣少游
 @Date: 2025/2/22 11:36:29

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "DownGoodsDAO.h"
#include "DownGoodsMapper.h"
#include <sstream>

std::string DownGoodsDAO::queryConditionBuilder(const DownGoodsQuery::Wrapper& query, SqlParams& params)
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

// 修改数据
int DownGoodsDAO::update(const DownGoodsModifyDO& uObj, const PayloadDTO& payload)
{
	string sql = "UPDATE `wm_to_down_goods` SET `goods_qua`=?, `goods_quaok`=?, `base_unit`=?, `goods_pro_date`=?, `bin_id_from=?, `ku_wei_bian_ma`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s", uObj.getGoodsQua(), uObj.getGoodsQuaok(), uObj.getBaseUnit(), uObj.getGoodsProDate(), uObj.getBinIdFrom(), uObj.getKuWeiBianMa(), uObj.getId());
}

//无分页查询所有数据
std::list<DownGoodsDO> DownGoodsDAO::selectWithConditions(const DownGoodsQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT * FROM wm_to_down_goods";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	DownGoodsMapper mapper;
	return sqlSession->executeQuery<DownGoodsDO>(sql, mapper, params);
}