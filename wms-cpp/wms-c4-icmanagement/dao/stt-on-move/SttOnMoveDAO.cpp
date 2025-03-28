/*
 Copyright Zero One Star. All rights reserved.

 @Author: fangtang
 @Date: 2025/03/02 16:21:52

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
#include "SttOnMoveDAO.h"
#include "SttOnMoveMapper.h"
#include <sstream>

std::string SttOnMoveDAO::queryConditionBuilder(const SttOnMoveQuery::Wrapper& query, SqlParams& params)
{
	// 字符串流，用于填入查询条件
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->last_move_start)// 最早移动日期
	{
		sqlCondition << " AND `last_move` >=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->last_move_start.getValue(""));
	}
	if (query->last_move_end)// 最晚移动日期
	{
		sqlCondition << " AND `last_move` <=?";
		SQLPARAMS_PUSH(params,"s",std::string,query->last_move_end.getValue(""));
	}
	if (query->cktype)// 库存类型
	{
		sqlCondition << " AND `kuctype` =?";
		SQLPARAMS_PUSH(params,"s",std::string,query->cktype.getValue(""));
	}
	if (query->bin_id)// 储位
	{
		sqlCondition << " AND `ku_wei_bian_ma` =?";
		SQLPARAMS_PUSH(params, "s", std::string, query->bin_id.getValue(""));
	}
	if (query->tin_id)// 托盘
	{
		sqlCondition << " AND `bin_id` =?";
		SQLPARAMS_PUSH(params, "s", std::string, query->tin_id.getValue(""));
	}
	if (query->cus_code)// 客户
	{
		sqlCondition << " AND `cus_code` =?";
		SQLPARAMS_PUSH(params, "s", std::string, query->cus_code.getValue(""));
	}
	if (query->cus_name)// 客户名称
	{
		sqlCondition << " AND `zhong_wen_qch` =?";
		SQLPARAMS_PUSH(params, "s", std::string, query->cus_name.getValue(""));
	}
	if (query->goods_id)// 商品编码
	{
		sqlCondition << " AND `goods_id` =?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods_id.getValue(""));
	}
	if (query->goods_qua_min)// 最少商品数量
	{
		sqlCondition << " AND `goods_qua` >=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods_qua_min.getValue(""));
	}
	if (query->goods_qua_max)// 最大商品数量
	{
		sqlCondition << " AND `goods_qua` <=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods_qua_max.getValue(""));
	}
	if (query->goods_name)// 商品名称
	{
		sqlCondition << " AND `shp_ming_cheng` LIKE CONCAT('%',?,'%')";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods_name.getValue(""));
	}
	if (query->goods_pro_data_start)// 最早生产日期
	{
		sqlCondition << " AND `goods_pro_data` >=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods_pro_data_start.getValue(""));
	}
	if (query->goods_pro_data_end)// 最晚生产日期
	{
		sqlCondition << " AND `goods_pro_data` <=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods_pro_data_end.getValue(""));
	}

	return sqlCondition.str();
}

uint64_t SttOnMoveDAO::count(const SttOnMoveQuery::Wrapper& query)// 哦这个是计数的
{
	SqlParams params;
	string sql = "SELECT COUNT(*) from `wv_stock_stt`";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql,params);
}

std::list<SttOnMoveDO> SttOnMoveDAO::selectWithPage(const SttOnMoveQuery::Wrapper& query)
{
	SqlParams params;
	// 查询语句
	string sql = "SELECT last_move,kuctype,ku_wei_bian_ma,bin_id,cus_code,zhong_wen_qch,goods_id,goods_qua,shp_ming_cheng,goods_pro_data,bzhi_qi,goods_unit,stt_sta,`id` FROM `wv_stock_stt` ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	//构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	SttOnMoveMapper mapper;
	// 执行查询
	return sqlSession->executeQuery<SttOnMoveDO>(sql,mapper,params);
}

PtrSttOnMoveDO SttOnMoveDAO::selectWithId(string id)
{
	string sql = "SELECT last_move,kuctype,ku_wei_bian_ma,bin_id,cus_code,zhong_wen_qch,goods_id,goods_qua,shp_ming_cheng,goods_pro_data,bzhi_qi,goods_unit,stt_sta,`id` FROM `wv_stock_stt` WHERE `id` = ?";
	PtrSttOnMoveMapper mapper;
	return sqlSession->executeQueryOne<PtrSttOnMoveDO>(sql,mapper,"%s",id);
}
