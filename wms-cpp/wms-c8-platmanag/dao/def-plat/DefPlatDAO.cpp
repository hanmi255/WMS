/*
 Copyright Zero One Star. All rights reserved.

 @Author: mao
 @Date: 2025/2/27 16:13:44

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
#include "DefPlatDAO.h"
#include "DefPlatMapper.h"
#include <sstream>

//std::string SampleDAO::queryConditionBuilder(const SampleQuery::Wrapper& query, SqlParams& params)
//{
//	stringstream sqlCondition;
//	sqlCondition << " WHERE 1=1";
//	if (query->name) {
//
//		sqlCondition << " AND `name`=?";
//		SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue(""));
//	}
//	if (query->sex) {
//
//		sqlCondition << " AND sex=?";
//		SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue(""));
//	}
//	if (query->age) {
//
//		sqlCondition << " AND age=?";
//		SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0));
//	}
//	return sqlCondition.str();
//}

uint64_t DefPlatDAO::deleteById(string id)
{
	string sql = "DELETE FROM `ba_platform` WHERE `id`=?";
	int a= sqlSession->executeUpdate(sql, "%s", id);
	return a;
}
uint64_t DefPlatDAO::update(string id,const PlatDO& uObj)
{
	string sql = "UPDATE `ba_platform` SET `platform_name`=?, `platform_code`=?, `update_name`=?, `update_by`=?, `update_date`=?  WHERE `id`=?";
	
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s", uObj.getplatform_name(), uObj.getplatform_code(), uObj.getupdate_name(), uObj.getupdate_by(), uObj.getupdate_date(), id);
}
std::list<PlatDO> DefPlatDAO::queryAll() {
	string sql = "SELECT `platform_name`,`platform_code` FROM `ba_platform`";
	DefPlatMapper mapper;
	return sqlSession->executeQuery<PlatDO>(sql, mapper);
}