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
#include "MovingBinDAO.h"
#include "MovingBinMapper.h"

std::string MovingBinDAO::queryConditionBuilder(const MovingBinQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->bin_id) {

		sqlCondition << " AND `bin_id`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->bin_id.getValue(""));
	}
	if (query->tin_id) {

		sqlCondition << " AND tin_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->tin_id.getValue(""));
	}
	if (query->goods_id) {

		sqlCondition << " AND goods_id=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods_id.getValue(""));
	}
	if (query ->goods_name) {

		sqlCondition << " AND goods_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->goods_name.getValue(""));
	}
	if (query->last_pick_time_start) {

		sqlCondition << " AND last_pick_time_start<=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->last_pick_time_start.getValue(""));
	}
	if (query->last_pick_time_end) {

		sqlCondition << " AND last_pick_time_end>=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->last_pick_time_end.getValue(""));
	}
	return sqlCondition.str();
}


uint64_t MovingBinDAO::count(const MovingBinQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM wm_stt_in_moving_bin ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}


std::list<MovingBinDO> MovingBinDAO::selectWithPage(const MovingBinQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT * FROM wm_stt_in_moving_bin ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);

	// 执行查询
	MovingBinMapper mapper;
	return sqlSession->executeQuery<MovingBinDO>(sql, mapper, params);
}

std::list<MovingBinDO> MovingBinDAO::selectWithConditions(const MovingBinQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT * FROM wm_stt_in_moving_bin";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	MovingBinMapper mapper;
	return sqlSession->executeQuery<MovingBinDO>(sql, mapper, params);
}