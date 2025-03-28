/*
 Copyright Zero One Star. All rights reserved.

 @Author: Jane
 @Date: 2025/03/05 14:26:52

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
#include "CostGoodsDAO.h"
#include "CostGoodsMapper.h"
#include <sstream>


std::string CostGoodsDAO::queryConditionBuilder(const BillingProductCategoryQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->code) {

		sqlCondition << " AND `goods_class_code`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->code.getValue(""));
	}
	if (query->name) {

		sqlCondition << " AND `goods_class_name`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue(""));
	}
	return sqlCondition.str();
}



int CostGoodsDAO::deleteByCode(string code)
{
	string sql = "DELETE FROM `ba_goods_class` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", code);
}

uint64_t CostGoodsDAO::insert(const GoodsClassDO& iObj)
{
	string sql = "INSERT INTO `ba_goods_class` (`id`, `create_name`,`create_by`,`create_date`,`sys_org_code`,`sys_company_code`, `goods_class_code`, `goods_class_name`) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s", iObj.getId(), iObj.getCreateName(), iObj.getCreateBy(), iObj.getCreateDate(), iObj.getSysOrgCode(), iObj.getSysCompanyCode(), iObj.getGoodsClassCode(), iObj.getGoodsClassName());
}

std::list<GoodsClassDO> CostGoodsDAO::select()
{
	SqlParams params;
	string sql = "SELECT goods_class_code,goods_class_name FROM ba_goods_class";

	CostGoodsMapper mapper;

	return sqlSession->executeQuery<GoodsClassDO>(sql, mapper, params);
}
