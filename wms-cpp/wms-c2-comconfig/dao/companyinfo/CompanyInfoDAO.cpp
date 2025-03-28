/*
 Copyright Zero One Star. All rights reserved.

 @Author: greent
 @Date: 2025/3/6 18:22:55

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
#include "CompanyInfoDAO.h"
#include "CompanyInfoMapper.h"
#include <sstream>

uint64_t CompanyInfoDAO::insert(const CompanyInfoDO& iObj)
{
	string sql = "INSERT INTO `ba_comp` (`id`, `com_code`, `com_zh_name`, `com_zh_aname`, `com_zh_addr`, `com_en_name`,  `com_en_aname`, `create_name`, `create_by`, `create_date`, `sys_org_code`, `sys_company_code`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	//string dd = "0";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s%s%s%s%s", iObj.getId(), iObj.getCompanyId(), iObj.getZhAbbr(), iObj.getZhFul(), iObj.getZhAddr(), iObj.getEnAbbr(), iObj.getEnFul(), iObj.getUserName(), iObj.getLoginName(), iObj.getDate(), iObj.getOrgDept(), iObj.getOrgCompany());
}

int CompanyInfoDAO::update(const CompanyInfoDO& uObj)
{
	//String sql = "UPDATE `ba_comp` SET `com_code` = ?, `com_zh_name` = ?, `com_zh_aname` = ?, `com_zh_addr` = ?, `com_en_name` = ?, `com_en_aname` = ?, `update_name` = ?, `update_by` = ?, `update_date` = ?, `sys_org_code` = ?, `sys_company_code` = ? WHERE `id` = ?";
	string sql = "UPDATE `ba_comp` SET `com_code` = ?, `com_zh_name` = ?, `com_zh_aname` = ?, `com_zh_addr` = ?, `com_en_name` = ?, `com_en_aname` = ?, `update_name` = ?, `update_by` = ?, `update_date` = ?, `sys_org_code` = ?, `sys_company_code` = ? WHERE `id` = ?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%s%s%s",  uObj.getCompanyId(), uObj.getZhAbbr(), uObj.getZhFul(), uObj.getZhAddr(), uObj.getEnAbbr(), uObj.getEnFul(), uObj.getUserName(), uObj.getLoginName(), uObj.getDate(), uObj.getOrgDept(), uObj.getOrgCompany(), uObj.getId());
}

int CompanyInfoDAO::deleteById(vector<string>& ids)
{
	string sql = "DELETE FROM `ba_comp` WHERE `id`=?";

	for (auto id : ids)
	{
		int res = sqlSession->executeUpdate(sql, "%s", id);

		if (res != 1) {
			return res;
		}
	}
	return 1;
}