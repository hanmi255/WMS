#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: whx
 @Date: 2025/3/5 14:23:49

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
#include "CostDetailAheadDAO.h"
#include "CostDetailAheadMapper.h"
#include <sstream>


std::string CostDetailAheadDAO::queryConditionBuilder(const CostDetailQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	
	if (query->cusCode && !query->cusCode->empty()) {
		sqlCondition << " AND `cus_code`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->cusCode.getValue(""));
	}
	if (query->cusName && !query->cusName->empty()) {

		sqlCondition << " AND `cus_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->cusName.getValue(""));
	}
	if (query->costCode && !query->costCode->empty()) {

		sqlCondition << " AND `cost_code`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->costCode.getValue(""));
	}
	if (query->costName && !query->costName->empty()) {

		sqlCondition << " AND `cost_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->costName.getValue(""));
	}

	if (query->costDateBegin && !query->costDateBegin->empty()) {
		sqlCondition << " AND `cost_data` >= STR_TO_DATE(?, '%Y-%m-%d %H:%i:%s')";
		SQLPARAMS_PUSH(params, "dt_start", std::string, query->costDateBegin.getValue(""));
	}

	if (query->costDateEnd && !query->costDateEnd->empty()) {
		sqlCondition << " AND `cost_data` < STR_TO_DATE(?, '%Y-%m-%d %H:%i:%s') + INTERVAL 1 DAY";
		SQLPARAMS_PUSH(params, "dt_end", std::string, query->costDateEnd.getValue(""));
	}
	
	if (query->note && !query->note->empty()) {

		sqlCondition << " AND `beizhu`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->note.getValue(""));
	}
	if (query->costState && !query->costState->empty()) {

		sqlCondition << " AND `cost_sta`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->costState.getValue(""));
	}
	
	return sqlCondition.str();
}


uint64_t CostDetailAheadDAO::count(const CostDetailQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT COUNT(*) FROM wm_day_cost ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 执行查询
	return sqlSession->executeQueryNumerical(sql, params);
}

std::list<DayCostDO> CostDetailAheadDAO::selectWithPage(const CostDetailQuery::Wrapper& query)
{
	SqlParams params;
	string sql = "SELECT `id`,`create_name`,`create_by`,`create_date`,`update_name`,`update_by`,`update_date`,`sys_org_code`,`sys_company_code`,`cus_code`,`cus_name`,`cost_code`,`cost_name`,`cost_data`,`day_cost_yj`,`day_cost_bhs`,`day_cost_se`,`day_cost_hsj`,`cost_ori`,`beizhu`,`cost_sta`,`cost_sl`,`cost_unit`,`cost_js` FROM `wm_day_cost` ";
	// 构建查询条件
	sql += queryConditionBuilder(query, params);
	// 构建分页条件
	sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
	
	cout << "sql: " << sql << endl;
	
	// 执行查询
	CostDetailMapper mapper;
	return sqlSession->executeQuery<DayCostDO>(sql, mapper, params);
}

//下面两个条件查询应该是有问题的
std::list<DayCostDO> CostDetailAheadDAO::selectByName(const string& name)
{
	string sql = "SELECT id,name,sex,age FROM wm_day_cost WHERE `name` LIKE CONCAT('%',?,'%')";
	CostDetailMapper mapper;
	return sqlSession->executeQuery<DayCostDO>(sql, mapper, "%s", name);
}

PtrDayCostDO CostDetailAheadDAO::selectById(uint64_t id)
{
	string sql = "SELECT id,name,sex,age FROM wm_day_cost WHERE `id`=?";
	PtrCostDetailMapper mapper;
	return sqlSession->executeQueryOne<PtrDayCostDO>(sql, mapper, "%ull", id);
}

uint64_t CostDetailAheadDAO::insert(const DayCostDO& iObj)
{
	string sql = "INSERT INTO `wm_day_cost` (`id`, `create_name`, `create_by`,`create_date`,`sys_org_code`,`sys_company_code`,`cus_code`,`cost_code`,`cost_data`,`day_cost_yj`,`day_cost_bhs`,`day_cost_se`,`day_cost_hsj`,`cost_ori`,`beizhu`,`cost_sta`,`cost_sl`,`cost_unit`) VALUES ( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%dt%s%s%s%s%dt%s%s%s%s%s%s%s%s%s", iObj.getId(), iObj.getCreateName(),  iObj.getCreateBy(), iObj.getCreateDate(), iObj.getSysOrgCode(), iObj.getSysCompanyCode(), iObj.getCusCode(),
		iObj.getCostCode(), iObj.getCostDate(), iObj.getDayCostYj(), iObj.getDayCostBhs(),iObj.getDayCostSe(), iObj.getDayCostHsj(), iObj.getCostOri(), iObj.getBeiZhu(), iObj.getCostSta(), iObj.getCostSl(), iObj.getCostUnit());
}

int CostDetailAheadDAO::update(const DayCostDO& uObj)
{
	 // 修正后的 SQL（注意字段名和逗号）
	string sql = "UPDATE `wm_day_cost` SET "
		"`update_name`=?, `update_by`=?, `update_date`=?, "
		"`cus_code`=?, `cost_code`=?, `cost_data`=?, "  // 假设字段名是 cost_date
		"`day_cost_yj`=?, `day_cost_bhs`=?, `day_cost_se`=?, "
		"`day_cost_hsj`=?, `cost_ori`=?, `beizhu`=?, "
		"`cost_sta`=?, `cost_sl`=?, `cost_unit`=? "
		"WHERE `id`=?";

	// 修正后的格式化字符串（16 个参数）
	const char* format = "%s%s%dt%s%s%dt%s%s%s%s%s%s%s%s%s%s"; // 根据实际类型调整

	return sqlSession->executeUpdate(sql, format,
		uObj.getUpdateName(),    // 字符串 (假设类型为 string)
		uObj.getUpdateBy(),      // 字符串
		uObj.getUpdateDate(),    // 日期时间（转换为字符串，如 "YYYY-MM-DD HH:mm:ss"）
		uObj.getCusCode(),       // 字符串
		uObj.getCostCode(),      // 字符串
		uObj.getCostDate(),      // 日期时间
		uObj.getDayCostYj(),     // 数值类型（
		uObj.getDayCostBhs(),    // 数值
		uObj.getDayCostSe(),     // 数值
		uObj.getDayCostHsj(),    // 数值
		uObj.getCostOri(),       // 数值
		uObj.getBeiZhu(),        // 字符串
		uObj.getCostSta(),       // 字符串
		uObj.getCostSl(),        // 数值
		uObj.getCostUnit(),      // 字符串
		uObj.getId()             // 整数
	);
}

int CostDetailAheadDAO::deleteById(const string& id)
{
	string sql = "DELETE FROM `wm_day_cost` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}


