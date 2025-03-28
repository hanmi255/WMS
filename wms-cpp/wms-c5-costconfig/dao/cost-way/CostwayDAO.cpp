/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

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
#include "CostwayDAO.h"
#include "CostwayMapper.h"
#include "CostwayOutMapper.h"

#include <sstream>

std::string CostwayDAO::queryConditionBuilder(const DeleteQuery::Wrapper& query, SqlParams& params)
{
	stringstream sqlCondition;
	sqlCondition << " WHERE 1=1";
	if (query->prount_code) {

		sqlCondition << " AND `prount_code`=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->prount_code.getValue(""));
	}
	if (query->prount_name) {

		sqlCondition << " AND prount_name=?";
		SQLPARAMS_PUSH(params, "s", std::string, query->prount_name.getValue(""));
	}
	return sqlCondition.str();
}

int CostwayDAO::deleteById(string id)
{
	string sql = "DELETE FROM `ba_pronut_method` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id);
}
uint64_t CostwayDAO::insert(const CostwayDO& iObj)
{
	string sql = "INSERT INTO `ba_pronut_method` (`id`, `pronut_code`, `pronut_name`,`create_name`,`create_by`,`create_date`,`sys_org_code`,`sys_company_code`) VALUES (?, ?, ?,?,?,?,?,?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s",iObj.getId(), iObj.getPronut_code(), iObj.getPronut_name(),iObj.getCreate_name(),iObj.getCreate_by(),iObj.getCreate_date(),iObj.getSys_org_code(),iObj.getSys_company_code());
}


std::list<CostwayDO> CostwayDAO::select()
{
	SqlParams params;
	string sql = "SELECT pronut_code,pronut_name FROM ba_pronut_method ";
	// Ö´ÐÐ²éÑ¯
	CostwayOutMapper mapper;
	return sqlSession->executeQuery<CostwayDO>(sql, mapper, params);
}